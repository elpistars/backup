#include <opencv2/objdetect/objdetect.hpp> // Library Opencv
#include <opencv2/core/core.hpp> // Library Opencv
#include <opencv2/highgui/highgui.hpp> // Library Opencv
#include <opencv2/imgproc/imgproc.hpp>// Library Opencv
#include <opencv2/opencv.hpp>// Library Opencv
//#include <iostream>
#include <stdio.h>
#include <dynamixel.h> // USB2DYNAMIXEL
//#include <Windows.h>
//#include <conio.h>
#include <stdlib.h>
//#include <unistd.h>


#pragma comment (lib, "dynamixel.lib")

#define DEFAULT_PORTNUM 0 // misalnya 
#define DEFAULT_BAUDNUM 1
int FRAME_WIDTH=640;
int FRAME_HEIGHT=480;

using namespace std;
using namespace cv ;

int g,h,c,d,e,f;
int b;
int a;
double korx=0;
double kory=0;
double area; 
//double a;
//double b;
//double error_sblmIx ;
double error_sblmDx = 0;
 //const double Tc = 0.01 ;
const double Kpx = 0.002;
const double Kdx = 0.0006;
const double Kix = 0 ;
//double error_sblmIy ;
double error_sblmDy = 0;
const double Kpy = 0.002;
const double Kdy = 0.0006;
const double Kiy = 0;
double setpointx;
double setpointy;
double nilai_sensorx;
double nilai_sensory;
double errorx;
double errory;
double outPx;
double outPy;
//double outIx;
//double outIy;
double outDx;
double outDy;
double PIDx;
double PIDy;
//double errorIx;
//double errorIy;
double errorDx;
double errorDy;

void pid(double v, double w){

//PIDx
	setpointx= FRAME_WIDTH/2;
	nilai_sensorx = v;
	    
//P
	errorx=setpointx-nilai_sensorx;
	outPx=Kpx*errorx;

//I
	
	/*errorIx=errorx+error_sblmIx;
	outIx=Kix*errorIx*Tc;
	error_sblmIx = errorIx;*/

//D
	
	errorDx=errorx-error_sblmDx;
	outDx=Kdx*errorDx;
	error_sblmDx = errorx;

	PIDx=outPx+outDx;
 
//PIDy
	setpointy=FRAME_HEIGHT/2; 
	nilai_sensory= w;

//P
	errory=setpointy-nilai_sensory;
	outPy=Kpy*errory;

//I
	
	/*errorIy=errory+error_sblmIy;
	outIy=Kiy*errorIy*Tc;
	error_sblmIy=errorIy;*/

//D
	
	errorDy=errory-error_sblmDy;
	outDy=Kdy*errorDy;
	error_sblmDy=errory;

	PIDy=outPy+outDy;
	cout << "PIDx: "<< PIDx <<" PIDy: "<< PIDy << endl;
 
	a=a+PIDx;
	b=b+PIDy;
	cout << "3: " << a <<" 20: " << b << endl;

	dxl_write_word(20,30,b);
	dxl_write_word(19,30,a);
}

void peta(double x, double y){

//cout<<"x: "<<x<<"y: "<<y<<endl;
	c = a-15; //turun
	d = a+15; //naik
	e = b-15; //kiri
	f = b+15; //kanan
//1
if(x<=213.333 && y<=160){
	cout <<"area 1"<<endl;
	a=d;
	b=f;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);
	error_sblmDx=0;
	error_sblmDy=0;
	//return 1;
	}
//2
else if(x>213.333 && x<426.666 && y<=160){
	cout <<"area 2"<<endl;
	a=d;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);
	error_sblmDx=0;
        error_sblmDy=0;
	//return 2;
	}
//3
else if(x>=426.666 && y<=160){
	cout <<"area 3"<<endl;
	a=d;
	b=e;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);
	error_sblmDx=0;
        error_sblmDy=0;
	//return 3;
	}
//4
else if(x<=213.333 && y>160 && y<320){
	cout <<"area 4"<<endl;
	b=f;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);
	error_sblmDx=0;
        error_sblmDy=0;
	//return 4;
	}
//5
else if(x>213.333 && x<426.666 && y>160 && y<320){
	cout <<"area 5"<<endl;
	//dxl_write_word(3,30,a);
	//dxl_write_word(20,30,b);
	pid(x,y);
	//return 5;
	}
//6
else if(x>=426.666 && y>160 && y<320){
	cout <<"area 6"<<endl;
	b=e;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);
	error_sblmDx=0;
        error_sblmDy=0;
	//return 6;
	}
//7
else if(x<=213.333 && y>=320){
	cout <<"area 7"<<endl;
	a=c;
	b=f;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);
	error_sblmDx=0;
        error_sblmDy=0;
	//return 7;
	}
//8
else if(x>213.333 && x<426.666 && y>=320){
	cout <<"area 8"<<endl;
	a=c;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);
	error_sblmDx=0;
        error_sblmDy=0;
	//return 8;
	}
//9
else if(x>=426.666 && y>=320){
	cout <<"area 9"<<endl;
	a=c;
	b=e;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);
	error_sblmDx=0;
        error_sblmDy=0;
	//return 9;
	}
}

int main (){
	dxl_initialize(0,1);
	dxl_write_word(19,32,512);
	dxl_write_word(20,32,512);
	a=400;
	b=512;
	dxl_write_word(19,30,a);
	dxl_write_word(20,30,b);

	VideoCapture cap(0); //fungsi yang menintegrasikan kamera menggunakan variable cap
    	if(!cap.isOpened()) // kondisi dimana jika kamera tidak terdeteksi maka program akan tertutup
    	return -1;

	Mat matWebCam; // Variable matriks untuk kamera
        Mat matProcessed; // Variable matriks untuk kamera
	Mat matWebcam2; // Variable matriks untuk kamera

while(1){
	cap >> matWebCam;
	cap >> matWebcam2;
	cvtColor(matWebCam,matWebcam2,CV_BGR2Lab); //pengubahan dari kamera normal (BRG) menjadi HSV inputnya matwebcam dan outpunya juga matwebcam
	//inRange(matWebcam2,Scalar(37,137,53),Scalar(214,240,256),matProcessed);
	inRange(matWebcam2,Scalar(0,132,0),Scalar(254,256,256),matProcessed);
	GaussianBlur(matProcessed,matProcessed,Size(9,9),1.5);	//ngeblur warna pada kamera yang sudah terproses agar mudah di deteksi
	//line(matWebCam,cvPoint(213,0),cvPoint(213,480),255,2,30,0); //garis pada layar
	//line(matWebCam,cvPoint(426,0),cvPoint(426,480),255,2,30,0); // garis pada layar
	//line(matWebCam,cvPoint(0,120),cvPoint(640,120),255,2,30,0);
	//line(matWebCam,cvPoint(0,360),cvPoint(640,360),255,2,30,0); // garis pada layar
	//imshow("Mantap",matWebCam);
	Moments moment = moments (matProcessed); // fungsi moment untuk mengetahui luas objek yang terdeteksi

	area = moment.m00;
	if(area >= 80000){
		 korx = moment.m10/area;
		 kory = moment.m01/area;
		 peta(korx,kory);
	}
	else{
		cout<<"No Balls"<<endl;
		//dxl_write_word(3,30,400);
		//dxl_write_word(20,30,512);
		//error_sblmDx=0;
		//error_sblmDy=0;
	}
}
return(0);
}

