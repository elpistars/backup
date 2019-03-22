#include "/home/pi/systemTest/library/allLibtune.h"
#include "/home/pi/systemTest/library/movement/moveArray.h"
#include "/home/pi/systemTest/library/dynamixel/syncWrite.cpp"
#include "/home/pi/systemTest/putarkiri.cpp"
#include "/home/pi/systemTest/putarkanan.cpp"
#include "bangun.cpp"
#include <iostream>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
double x,y,z,sudutX,sudutY,sudutZ,x2,y2,z2,sudutX2,sudutY2,sudutZ2,sudutNgurang;
/*
double nilaisensor,epx,edx,epy,edy,erry,outpx,outpy;
double kpx = 0;
double kdx = 0;//.005;;
double kpy = 0;
double kdy = 0;
double outdx = 0;
double outdy = 0;
double edysblm = 0;
double edxsblm = 0;
double pidx = 0;
double pidy= 0;
double setpointx = 270.5;
double setpointy = 1.1;
double f2;
double a=0.2;
struct {
        int condition,x_head,y_head;
}data_image;
int jdt=0;
int jdt2;*/

void berdiri(){

        int speed, com7, com8;


//       com7=4;
  //      com8=4;
          dxl_write_word(10,26,1);
          dxl_write_word(10,27,1);
          dxl_write_word(9,26,1);
          dxl_write_word(9,27,1);

        //kirimPacketTorque(12,id,tor);
        //for(int i=0;i<=11;i++){
          dxl_write_word(10,28,4);
          dxl_write_word(10,29,4);
          dxl_write_word(9,28,4);
          dxl_write_word(9,29,4);



/*
        cout<<"Masukkan sudut X: ";
        cin>>sudutX;
        cout<<"Masukkan sudut Y: ";
        cin>>sudutY;
        cout<<"Masukkan sudut Z: ";
        cin>>sudutZ;

        cout<<"Masukkan X: ";
        cin>>x;
        cout<<"Masukkan Y: ";
        cin>>y;
        cout<<"Masukkan Z: ";
        cin>>z;*/
        x=-13.4;// tinggi kaki kanan //-13.4
        y=0;// miring kaki
        z=0.5;// langkah kaki //0

        sudutX=0;//miring badan
        sudutY=16;//kebungkukan badan //-4
        sudutZ=0;//putaran badan

        x2=-13.4; //tinggi kaki kiri
        y2=0;//3;
        z2=0;

        sudutX2=0;//-6;
        sudutY2=16; //-4
        sudutZ2=0;

        // inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,50,'2');
          inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,200,512,512,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);
        cout<<"Masukkan Speed: "<<endl;
        //cin>>speed;
        sleep(1);//5
         //kirimPacketInverse(x,y);
        //cin>>speed;
        //for(int i=1;i<=10;i++){
}
void dadah(int n){
	int tk2,tk3, i;
	double f=0; double shift;
	tk2=400;
        x=-13.4;
        x2=-13.4;
        sudutY=16;
        sudutY2=16;
	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,200,512,512,'2',800,500,500,780,500,500,data_image.x_head,data_image.y_head);
	sleep(1);
	i=0;
	while (i<n){
	  f=0;
	  while (f<=360){
		f=f+0.2;
		tk2=400+30*cos(f*3.14/180);
		tk3=290-40*cos(f*3.14/180);
		inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,200,512,512,'2',800,500,tk2,780,tk3,500,data_image.x_head,data_image.y_head);
		usleep(300);
	  }
	  i++;
	  usleep(300);
	}
}
void kibar(){
	int tk4=0;
	double f=0; int i=0;
	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,512,512,'2',500,230,250,780,500,230,data_image.x_head,data_image.y_head);
	sleep(1);
	usleep(100);
	x=-15;
	z=0.5;
	x2=-15;
	sudutY=16;
	sudutY2=16;

	while(i<4){
	  f=0;
	  while(f<=180){
		f=f+0.05;
		tk4=780-120*sin(f*3.14/180);
	 	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,512,512,'2',500,230,250,tk4,500,230,data_image.x_head,data_image.y_head);
		usleep(200);
	  }
	  i++;
	  usleep(300);
	}
}
void tunjuk(){
	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,512,512,'2',1000,500,250,780,750,500,data_image.x_head,data_image.y_head);
}
void angguk(){
	double f=0;
	while(f<=180){
	  f+=0.01;
	  data_image.y_head=512-132*sin(f*3.14/180);
	  inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,200,512,512,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);
	}
}
int main(){
	dxl_initialize(0,1);
	data_image.x_head=512;
	data_image.y_head=512;
/*	banguns();
	while(cin.get() != '\n');*/
	berdiri();
	while(cin.get() != '\n');
/*	spki();
	int count=0;
	while(count<9){
	  count++;
	  putarkiri();
	  sleep(1);
	  //sleep(0.5);
	}
	sleep(1);
	berdiri();
	while(cin.get() != '\n');
	angguk();
	while(cin.get() != '\n');
	count=0;
        while(count<7){
          count++;
          putarkanan();
          //usleep(3000);
          //sleep(0.5);
        }
	sleep(1);
	berdiri();*/
//	while(cin.get() != '\n');
	dadah(20);
	sleep(1);
	berdiri();
	return 0;
}
