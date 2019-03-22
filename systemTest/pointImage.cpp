#ifndef POINTIMAGE_C
#define POINTIMAGE_C

#include "/home/pi/systemTest/library/allLib.h"

#pragma comment (lib, "dynamixel.lib")
#define DEFAULT_PORTNUM 0 // misalnya 
#define DEFAULT_BAUDNUM 1
int FRAME_WIDTH=640;
int FRAME_HEIGHT=480;

using namespace std;
using namespace cv ;
int comimage,comcam,com;
int cimage,dimage,eimage,fimage,tempimage,aa,bb;
int aimage=400;
int bimage=512;
int limage=10000;
double korximage=0;
double koryimage=0;
double areaimage;
double error_sblmDximage = 0;
const double Kpximage =0.003;// 10.003;
const double Kdximage = 0.0006;//0.2006;
const double Kiximage = 0 ;
double error_sblmDyimage = 0;
const double Kpyimage = 0.003;//10.003;
const double Kdyimage = 0.0006;//0.2006;
const double Kiyimage = 2;
double setpointximage;
double setpointyimage;
double nilai_sensorximage;
double nilai_sensoryimage;
double errorximage;
double erroryimage;
double outPximage;


double outPyimage;
double outDximage;
double outDyimage;
double PIDximage;
double PIDyimage;
double errorDximage;
double errorDyimage;
int pimage1,pimage2;
VideoCapture cap(0); //fungsi yang menintegrasikan kamera menggunakan variable cap
Mat matWebCam; // Variable matriks untuk kamera
Mat matProcessed; // Variable matriks untuk kamera
Mat matWebcam2; // Variable matriks untuk kamera
int res=0;

void pid(double v, double w,int nilaiimage1, int nilaiimage2){

	setpointximage= FRAME_WIDTH/2;
	nilai_sensorximage = v;
	cout<<" "<<erroryimage<<"  "<< nilai_sensoryimage<<endl;    
//P
	errorximage=setpointximage-nilai_sensorximage;
	outPximage=Kpximage*errorximage;

//dimage
	
	errorDximage=errorximage-error_sblmDximage;
	outDximage=Kdximage*errorDximage;
	error_sblmDximage = errorximage;

	PIDximage=outPximage+outDximage;
 
//PIDyimage
	setpointyimage=FRAME_HEIGHT/2; 
	nilai_sensoryimage= w;

//P
	erroryimage=setpointyimage-nilai_sensoryimage;
	outPyimage=Kpyimage*erroryimage;

//dimage
	
	errorDyimage=erroryimage-error_sblmDyimage;
	outDyimage=Kdyimage*errorDyimage;
	error_sblmDyimage=erroryimage;

	PIDyimage=outPyimage+outDyimage;
	
	aimage=nilaiimage1+PIDyimage;
	bimage=nilaiimage2+PIDximage;
	cout<<"  PID "<<" aimage : "<<aimage<<"  bimage : "<<bimage<<endl;
//	if(aimage>512){
//	aimage=512;	}
	dxl_write_word(19,30,aimage);
	dxl_write_word(20,30,bimage);
	comimage =1;


}
void peta(double x, double y){
pimage1=0;

	cimage = aimage-10; //turun
	dimage = aimage+10; //naik
	eimage = bimage-10; //kiri
	fimage = bimage+10; //kanan
//1
//	while(x<213.333 && x>426.666 && y<160 && y>320)
if(x<=213.333 && y<=160){
	 cout<<"h"<<endl;
	aimage=dimage;
	bimage=fimage;
//	 pid(x,y);
	}
//2
else if(x>213.333 && x<426.666 && y<=160){
	 cout<<"g"<<endl;
	aimage=dimage;
	bimage=bimage;
// pid(x,y);
	}
//3
else if(x>=426.666 && y<=160){
	 cout<<"f"<<endl;
	aimage=dimage;
	bimage=eimage;
// pid(x,y);
	}
//4
else if(x<=213.333 && y>160 && y<320){
	 cout<<"e"<<endl;
	aimage=aimage;
	bimage=fimage;
// pid(x,y);
	}
//5
else if(x>213.333 && x<426.666 && y>160 && y<320){
	 cout<<"a"<<endl;
	pid(x,y,aimage,bimage);
	}
//6
else if(x>=426.666 && y>160 && y<320){
	bimage=eimage;
// pid(x,y);
	}
//7
else if(x<=213.333 && y>=320){
	 cout<<"d"<<endl;
	aimage=cimage;
	bimage=fimage;
// pid(x,y);
	}
//8
else if(x>213.333 && x<426.666 && y>=320){
	 cout<<"c"<<endl;
	aimage=cimage;
	}
//9
else if(x>=426.666 && y>=320){
	 cout<<"b"<<endl;
// pid(x,y);
	aimage=cimage;
	bimage=eimage;
	}
//		if(aimage>512)
//			{aimage=512;}
		dxl_write_word(19,30,aimage);
		dxl_write_word(20,30,bimage);
		
		if(bimage>540){comimage = 2;}
		else if(bimage<500){comimage = 3;}
}

void awal(){
	cap >> matWebCam;
	cap >> matWebcam2;
	cvtColor(matWebCam,matWebcam2,CV_BGR2Lab); //pengubahan dari kamera normal (BRG) menjadi HSV inputnya matwebcam dan outpunya juga matwebcam
	inRange(matWebcam2,Scalar(5,132,151),Scalar(160,167,256),matProcessed);
	GaussianBlur(matProcessed,matProcessed,Size(9,9),1.5);	//ngeblur warna pada kamera yang sudah terproses agar mudah di deteksi
	Moments moment = moments (matProcessed); // fungsi moment untuk mengetahui luas objek yang terdeteksi
	areaimage = moment.m00;
	cout<<"area "<<areaimage<<endl;

	if(areaimage >= 80000){
		pimage1=1;
		korximage = moment.m10/areaimage;
		koryimage = moment.m01/areaimage;
	//	comimage = 1;
	}
	else{
		cout<<"Searching Balls.."<<aimage<<" "<<bimage<<endl;
		pimage2=1;
		error_sblmDximage=0;
		error_sblmDyimage=0;
		comimage = 0;
		comger = 1;
		comkan = 1;
		comkir = 1;
	}
}

void *melihat(void *arg){
//void melihat(){
comcam=0;
awal();
peta(korximage,koryimage);
com=1;   	
}

#endif
