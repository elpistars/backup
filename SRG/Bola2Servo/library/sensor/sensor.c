#ifndef SENSOR_C 
#define SENSOR_C

#include "/home/pi/systemTest/library/allLib.h"

#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846
//#include "gyro.h" 

using namespace std;

int *Pacc_raw;
int *Pmag_raw;
int acc_raw[3];
int mag_raw[3];
int i = 0;
float AccYangle = 0.0;
float AccXangle = 0.0;
float AcceleroY = 0.0;
float AcceleroX = 0.0;
float MagOut = 0.0;
float Magneto = 0.0;
char nstatus;
int bangun; 
float last_errorx;
float last_errory; 
float errorpidy;
float errorpidx;
float tot_errorx;
float tot_errory;
float dif_errorx;
float dif_errory;
float Py;
float Px;
int VarPID[20];
int counterPID;
float velocity,p,h,d,pi,pd,pd2, error,p2,d2, error2,tot_error,rate,rate2, lasterror, lasterror2;
int file;    
int putar;

void readBlock(uint8_t command, uint8_t size, uint8_t *data) {
    int result = i2c_smbus_read_i2c_block_data(file, command, size, data);

    if (result != size)
    {
        printf("Failed to read block from I2C.");
        exit(1);
    }
}

void selectDevice(int file, int addr) {
        char device[3];
        if (addr == 1)
                device == "L3G";
        else
                device == "LSM";
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
                fprintf(stderr,
                        "Error: Could not select device 0x%02x: %s\n",device, strerror(errno));
        }
}

void readACC(int *a) {
 	uint8_t block[6];
        selectDevice(file,ACC_ADDRESS);
		readBlock(0x80 | LSM303_OUT_X_L_A, sizeof(block), block);
        *a = (int16_t)(block[0] | block[1] << 8) >> 4;
        *(a+1) = (int16_t)(block[2] | block[3] << 8) >> 4;
        *(a+2) = (int16_t)(block[4] | block[5] << 8) >> 4;
}

void readMAG(int *m) {
	uint8_t block[6];
        selectDevice(file,MAG_ADDRESS);
	// DLHC: register address order is X,Z,Y with high bytes first
	readBlock(0x80 | LSM303_OUT_X_H_M, sizeof(block), block);
       	*m = (int16_t)(block[1] | block[0] << 8);
        *(m+1) = (int16_t)(block[5] | block[4] << 8) ;
        *(m+2) = (int16_t)(block[3] | block[2] << 8) ;
}

void readGYR(int *g) {
	uint8_t block[6];
        selectDevice(file,GYR_ADDRESS);
	readBlock(0x80 | L3G_OUT_X_L, sizeof(block), block);
        *g = (int16_t)(block[1] << 8 | block[0]);
        *(g+1) = (int16_t)(block[3] << 8 | block[2]);
        *(g+2) = (int16_t)(block[5] << 8 | block[4]);
}
void writeAccReg(uint8_t reg, uint8_t value) {
	selectDevice(file,ACC_ADDRESS);
	int result = i2c_smbus_write_byte_data(file, reg, value);
	if (result == -1){
	        printf ("Failed to write byte to I2C Acc.");
	        exit(1);
	}
}

void writeMagReg(uint8_t reg, uint8_t value) {
	selectDevice(file,MAG_ADDRESS);
	int result = i2c_smbus_write_byte_data(file, reg, value);
	if (result == -1){
	        printf("Failed to write byte to I2C Mag.");
	        exit(1);
	}
}

void writeGyrReg(uint8_t reg, uint8_t value) {
	selectDevice(file,GYR_ADDRESS);
	int result = i2c_smbus_write_byte_data(file, reg, value);
	if (result == -1){
	        printf("Failed to write byte to I2C Gyr.");
	        exit(1);
	}
}

void enableIMU() {
	Pacc_raw=acc_raw;
	Pmag_raw=mag_raw;

	__u16 block[I2C_SMBUS_BLOCK_MAX];
        int res, bus, size;
        char filename[20];
        sprintf(filename, "/dev/i2c-%d", 1);
        file = open(filename, O_RDWR);
        if (file<0) {
		printf("Unable to open I2C bus!");
                exit(1);
        }
 // Enable accelerometer.
	writeAccReg(LSM303_CTRL_REG1_A, 0b01010111); // z,y,x axis enabled , 100Hz data rate
	writeAccReg(LSM303_CTRL_REG4_A, 0b00101000); // +/- 8G full scale: FS = 10 on DLHC, high resolution output mode
 // Enable magnetometer
        writeMagReg(LSM303_MR_REG_M, 0x00); // enable magnometer
 // Enable Gyro
       // writeGyrReg(L3G_CTRL_REG1, 0b00001111); // Normal power mode, all axes enabled
        //writeGyrReg(L3G_CTRL_REG4, 0b00110000); // Continuos update, 2000 dps full scale
}

string bacaACC(int *Pacc_raw){
	string status;
	readACC(Pacc_raw);
        float AccXangle = (float) (atan2(*(Pacc_raw+1),*(Pacc_raw+2))+M_PI)*RAD_TO_DEG;
        float AccYangle = (float) (atan2(*(Pacc_raw+2),*(Pacc_raw))+M_PI)*RAD_TO_DEG;
	cout << AccXangle << ", " << AccYangle << endl;

        if(AccXangle > 280){status = "Kanan";}
        else if(AccXangle < 160){status = "Kiri";}
        else if(AccYangle > 330 || AccYangle < 50){status = "Depan";}
	else if(AccYangle < 190 && AccYangle > 170 && AccXangle < 267 && AccXangle > 80){status = "Belakang";}
	else {status = "Stabil";}

	cout << "Status: " << status << endl;
	return status;
}

float bacaACC2(int *Pacc_raw){
        string status;
        readACC(Pacc_raw);
        float AccXangle = (float) (atan2(*(Pacc_raw+1),*(Pacc_raw+2))+M_PI)*RAD_TO_DEG;
        float AccYangle = (float) (atan2(*(Pacc_raw+2),*(Pacc_raw))+M_PI)*RAD_TO_DEG;
        return AccXangle;
}

float bacaACC3(int *Pacc_raw){
        string status;
        readACC(Pacc_raw);
	 float AccXangle = (float) (atan2(*(Pacc_raw+1),*(Pacc_raw+2))+M_PI)*RAD_TO_DEG;
        float AccYangle = (float) (atan2(*(Pacc_raw+2),*(Pacc_raw))+M_PI)*RAD_TO_DEG;
        return AccYangle;
}

int bacaMAG(int *Pmag_raw, float kemana){
	readMAG(Pmag_raw);
	//int mag_raw[3];
	float MagOut = 180* (atan2(*(mag_raw+1),*(mag_raw))/M_PI);
	int gawang;
	bool direksi;

	if(MagOut<0){MagOut+=360;}
	float batasKanan = kemana+10;
	float batasKiri = kemana-10;
	float batasPKi = kemana-180;
	float batasPKa = kemana+180;

	if(batasKanan > 360){
		batasKanan = (batasKanan-360)+0;
	}
	if(batasKiri < 0){
		batasKiri = 360-(batasKiri);
	}
	if(batasPKa > 360){
		batasPKa = (batasPKa-360)+0;
	}
	if(batasPKi < 0){
		batasPKi = 360-(-batasPKi);
	}

	if(batasPKa <= 180){
		if(MagOut < batasPKa || MagOut > kemana){
			putar = 1;
		}
		else{putar = 2;}

	}else if(batasPKi >= 180){
		if(MagOut > batasPKi || MagOut < kemana){
			putar = 2;
		}
		else{putar = 1;}

	}else{
		if(MagOut > kemana){
			putar = 1;
		}
		else{putar = 2;}
	}

        int Magneto = MagOut; //output magneto "embeded universal"
	if(MagOut >= batasKiri && MagOut <= batasKanan){
		direksi=true;
	}
        else{
		direksi=false;
	}
	cout << "Magnet: " << MagOut << endl;
        usleep(100000);
        return direksi;
}


/*int bacaMAG(int *Pmag_raw, int kemana)
        {
                readMAG(Pmag_raw);
                //int mag_raw[3];
                float MagOut = 180* (atan2(*(mag_raw+1),*(mag_raw))/M_PI);
                int gawang;
		bool direksi;
		if(MagOut<0){MagOut+=360;}
                cout<<" Magneto: "<<MagOut;
                string arah;
                if(MagOut>=193 && MagOut<283){arah="Utara"; gawang=1; if(kemana==2){putar=1;} else if(kemana==4||kemana==3){putar=2;}}
                else if((MagOut>=283 && MagOut<=360) || (MagOut>=0 && MagOut<73)){arah="Barat"; gawang=2; if(kemana==1){putar=1;} else if(kemana==3||kemana==4){putar=2;}}
                else if(MagOut>=73 && MagOut<103){arah="Selatan"; gawang=3; if(kemana==4){putar=1;} else if(kemana==2||kemana==1){putar=2;}}
                else if(MagOut>=103 && MagOut<193){arah="Timur"; gawang=4; if(kemana==1){putar=1;} else if(kemana==3||kemana==2){putar=2;}}
                cout<<" Arah: "<<arah<<endl;
               int Magneto = MagOut; //output magneto "embeded universal"
		if(kemana==gawang){direksi=true;}
		else{direksi=false;}
                usleep(100000);
                return direksi;
        }*/
/*
void pid(float sp){
	bool stabil=false;
        //siapJalan(1,pd);
        //usleep(100000);
	while(!stabil&&bangun==0){
		//for(int k=0;k<5;k++){
		string status;
	        readACC(Pacc_raw);
	        float setpoint=sp;
	        float setpoint2=265;
		int change=0;
		int change2=0;
	        float kp=0.05;
	        float kd=0.01;
		float ki=0.03;
		float kp2=0.2;
		float ki2=0.1;
		float kd2=0.3;
	        float AccXangle = (float) (atan2(*(Pacc_raw+1),*(Pacc_raw+2))+M_PI)*RAD_TO_DEG;
	        float AccYangle = (float) (atan2(*(Pacc_raw+2),*(Pacc_raw))+M_PI)*RAD_TO_DEG;
	        cout<<AccXangle<<", "<<AccYangle<<endl;
	
	        error=setpoint-AccYangle;
		error2=setpoint2-AccXangle;
	
		if(AccYangle>=setpoint+0.5){change=-1.7;}
		else if(AccYangle<=setpoint-0.5){change=1.7;}
		else{change=0;}
	
		if(AccYangle>setpoint+3.5){change=-2;}
		else if(AccYangle<=setpoint-3.5){change=2;}
		else{change=0;}
	
	        if(AccXangle>=270){change2=-2;}
	        else if(AccXangle<=260){change2=2;}
	        else{change2=0;}
		
		velocity=6;
	        p=kp*error;
		if(change==0){p=0;}
		tot_error = error+lasterror;
		h=(tot_error*ki);
	        rate=error-lasterror;
	        d=(kd*rate);
		
	        pd=p+d+h;
		
		p2=kp*error2;
		rate2=error2-lasterror2;
		d2=kd*rate2;
	
		pd=change+pd;
	
		//pd2=change2+pd2;
	
		//walkReady[0]=walkReady[0]+pd;
		//walkReady[1]=walkReady[1]+pd;
	        set_siap_jalan(0,0,0,0,-pd,-pd,0,0,-pd*0.1,-pd*0.1,0,0);
        	//siapJalan(1);
	        pd=pd*velocity;
		//set_siap_jalan(0,0,0,0,-pd,-pd,0,0,0,0,0,0);
		siapJalan(1,pd);
		//set_siap_jalan(0,0,0,0,-pd,-pd,0,0,0,0,0,0);
		pd=change+pd;
	        //walkReady[0]=walkReady[0]-pd-39;
	        //walkReady[1]=walkReady[1]-pd-39;
	
		lasterror2=error2;
		lasterror=error;
		cout<<"Perubahan: "<<pd<<endl;
		if(-0.7<=error<=0.7){stabil=true;}
		usleep(100000);
	}
	usleep(100000);
}
*/





/*void stabPID(float setX,float setY) { 

	float Kp = 0.3;
	float Ki = 0.3;
	float Kd = 0.4; 
	int var1=0; 
	int var2=0; 
	int var3=0; 
	bool statx,staty;

	errorpidy=setY-AccYangle;
	errorpidx=setX-AccXangle;
	tot_errorx = errorpidx+last_errorx;
	tot_errory = errorpidy+last_errory;
	dif_errorx=errorpidx-last_errorx;
	dif_errory=errorpidy-last_errory;

	var1 = (errorpidy*Kp)+(tot_errory*Ki)+(dif_errory*Kd);
	var2 = (errorpidx*Kp)+(tot_errorx*Ki)+(dif_errorx*Kd);

	if (errorpidy>10) {
		VarPID[0] = -var1*2; 
		VarPID[1] = -var1*2;
 	}

	else if (errorpidy<-10){ 
		VarPID[0] = -(var1); 
		VarPID[1] = -(var1);
	} 

	else {
		VarPID[0]=0;
		VarPID[1]=0; 
		errorpidy=0; 
		staty=true;
	}

	if (errorpidx < -15) {
		VarPID[2] = -var2*1.5; 
		VarPID[3]=0;
	} 

	else if (errorpidx > 15) {
		VarPID[3] = var2*1.5; 
		VarPID[2] = 0;
	}

	else {
		VarPID[3]=0; 
		VarPID[2]=0; 
		errorpidx=0; 
		statx=true;
	}
	
	if (errorpidy>25 || errorpidx>25 || errorpidx<-25 || errorpidy<-25) {
		debug ("overshot PID");	
		VarPID[1]=0; 
		VarPID[2]=0; 
		VarPID[3]=0; 
		VarPID[0]=0;
	}
	
	counter++;


	if (statx && staty) {
		counterPID++; 
	}

	else {
		counterPID=0;
	}
		
	if (counter>100) {
		counterPID=50;
	}
}

/*void fixedPID(){
	counterPID=0;
	counter=0;
	enable_move=0;
	while(counterPID<49){stabPID(setACCx)}

}*/

#endif
