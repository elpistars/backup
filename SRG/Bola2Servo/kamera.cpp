//512 tengah 
//400 lihat kanan
//624 lihat kiri
#ifndef KAMERA_CPP
#define KAMERA_CPP

#include "/home/pi/SRG/Bola2Servo/library/allLib.h"

int FRAME_WIDTH=640;
int FRAME_HEIGHT=480;

double korx_image=0;
double kory_image=0;
double area_image; 
double error_sblmDx_image = 0;
const double Kpx_image = 0.002;
const double Kdx_image = 0.0006;
const double Kix_image = 0 ;
double error_sblmDy_image = 0;
const double Kpy_image = 0.002;
const double Kdy_image = 0.0006;
const double Kiy_image = 0;
int comimage=0;
void pid_image(double v, double w){
//PIDx_image
	setpointx_image= FRAME_WIDTH/2;
	nilai_sensorx_image = v;
	    
//P
	errorx_image=setpointx_image-nilai_sensorx_image;
	outPx_image=Kpx_image*errorx_image;

//I
	
	/*errorIx=errorx_image+error_sblmIx;
	outIx=Kix_image*errorIx*Tc;
	error_sblmIx = errorIx;*/

//D
	
	errorDx_image=errorx_image-error_sblmDx_image;
	outDx_image=Kdx_image*errorDx_image;
	error_sblmDx_image = errorx_image;

	PIDx_image=outPx_image+outDx_image;
 
//PIDy_image
	setpointy_image=FRAME_HEIGHT/2; 
	nilai_sensory_image= w;

//P
	errory_image=setpointy_image-nilai_sensory_image;
	outPy_image=Kpy_image*errory_image;

//I
	
	/*errorIy=errory_image+error_sblmIy;
	outIy=Kiy_image*errorIy*Tc;
	error_sblmIy=errorIy;*/

//D
	
	errorDy_image=errory_image-error_sblmDy_image;
	outDy_image=Kdy_image*errorDy_image;
	error_sblmDy_image=errory_image;

	PIDy_image=outPy_image+outDy_image;
	//cout << "PIDx_image: "<< PIDx_image <<" PIDy_image: "<< PIDy_image << endl;
 
	a_image=a_image+PIDx_image;
	b_image=b_image+PIDy_image;
	//batas tengok atas bawah
	if (a_image>480)
		a_image=480;
	else if(a_image<250)
		a_image=250;
	//batas tengok kiri kanan
	if(b_image>700)
		b_image=700;
	else if(b_image<365)
		b_image=365;
	cout << "19: " << a_image << endl;
	
	dxl_write_word(20,30,b_image);
	dxl_write_word(19,30,a_image);
	
	if (b_image<=400){
		comimage=2;
	}else if(b_image>=624){
		comimage=3;
	}
	if (a_image<=150){
		comimage=0;
	
	}else{ 
		comimage=1;
	}
	
}

void peta(double x, double y){
//cout<<"x: "<<x<<"y: "<<y<<endl;
	c_image = a_image-25; //turun
	d_image = a_image+25; //naik
	e_image = b_image-25; //kiri
	f_image = b_image+25; //kanan
	//batasan tengok atas dan bawah
	if  (c_image>480)
		c_image=480;
	else if(c_image<250)
		c_image=250;
	if (d_image>480)
		d_image=480;
	else if(d_image<250)
		d_image=250;
	//batasan tengok kanan dan kiri
	if (e_image>700)
		e_image=700;
	else if(e_image<365);
		e_image=365;
	if (f_image>700)
		f_image=700;
	else if(f_image<365)
		f_image=365;
/*	cout<<"a: "<<a_image;
	cout<<"b: "<<b_image;
	cout<<"c: "<<c_image;
	cout<<"d: "<<d_image;
	cout<<"e: "<<e_image;
	cout<<"f: "<<f_image;*/
//1
if(x<=213.333 && y<=160){
//	cout <<"area_image 1"<<endl;
	a_image=d_image;
	b_image=f_image;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);
	
	error_sblmDx_image=0;
	error_sblmDy_image=0;
	//return 1;
	}
//2
else if(x>213.333 && x<426.666 && y<=160){
//	cout <<"area_image 2"<<endl;
	a_image=d_image;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);
	
	error_sblmDx_image=0;
        error_sblmDy_image=0;
	//return 2;
	}
//3
else if(x>=426.666 && y<=160){
//	cout <<"area_image 3"<<endl;
	a_image=d_image;
	b_image=e_image;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);
	
	error_sblmDx_image=0;
        error_sblmDy_image=0;
	//return 3;
	}
//4
else if(x<=213.333 && y>160 && y<320){
//	cout <<"area_image 4"<<endl;
	b_image=f_image;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);
	
	error_sblmDx_image=0;
        error_sblmDy_image=0;
	//return 4;
	}
//5
else if(x>213.333 && x<426.666 && y>160 && y<320){
//	cout <<"area_image 5"<<endl;
	//dxl_write_word(19,30,a_image);
	//dxl_write_word(20,30,b_image);
	pid_image(x,y);
	//return 5;
	}
//6
else if(x>=426.666 && y>160 && y<320){
//	cout <<"area_image 6"<<endl;
	b_image=e_image;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);
	
	error_sblmDx_image=0;
        error_sblmDy_image=0;
	//return 6;
	}
//7
else if(x<=213.333 && y>=320){
//	cout <<"area_image 7"<<endl;
	a_image=c_image;
	b_image=f_image;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);
	
	error_sblmDx_image=0;
        error_sblmDy_image=0;
	//return 7;
	}
//8
else if(x>213.333 && x<426.666 && y>=320){
//	cout <<"area_image 8"<<endl;
	a_image=c_image;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);
	
	error_sblmDx_image=0;
        error_sblmDy_image=0;
	//return 8;
	}
//9
else if(x>=426.666 && y>=320){
//	cout <<"area_image 9"<<endl;
	a_image=c_image;
	b_image=e_image;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);

	error_sblmDx_image=0;
        error_sblmDy_image=0;
	//return 9;
	}
}

void lihat(){
	int kol = 0;
	//while(kol<6){
	cap >> matWebCam;
	cap >> matWebcam2;
	cvtColor(matWebCam,matWebcam2,CV_BGR2Lab); //pengubahan dari kamera normal (BRG) menjadi HSV inputnya matwebcam dan outpunya juga matwebcam
	inRange(matWebcam2,Scalar(56,144,156),Scalar(132,172,200),matProcessed); //Oranye
	GaussianBlur(matProcessed,matProcessed,Size(9,9),1.5);	//ngeblur warna pada kamera yang sudah terproses agar mudah di deteksi
	Moments moment = moments (matProcessed); // fungsi moment untuk mengetahui luas objek yang terdeteksi
	area_image = moment.m00;
	if(area_image >= 85000){
		 korx_image = moment.m10/area_image;
		 kory_image = moment.m01/area_image;
		 peta(korx_image,kory_image);
	}
	else{
		cout<<"No Balls"<<endl;	
		comimage=0;
	}
	cout<<"comimage: "<<comimage<<endl;
	//kol++;
	//}
}
#endif
