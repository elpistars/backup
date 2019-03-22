#ifndef ALLLIB_H
#define ALLLIB_H

//------------------------------------------------ImageProc----------------------
#include <opencv2/objdetect/objdetect.hpp> // Library Opencv
#include <opencv2/core/core.hpp> // Library Opencv
#include <opencv2/highgui/highgui.hpp> // Library Opencv
#include <opencv2/imgproc/imgproc.hpp>// Library Opencv
#include <opencv2/opencv.hpp>// Library Opencv

//------------------------------------------------Sensor dan Dynamixel----------------------
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <time.h>

//------------------------------------------------MultiThreading-----------------------
#include <pthread.h>

//------------------------------------------------Dynamixel-----------------------------
#include <termio.h>
#include <termios.h>
//#include "/home/pi/SRG/Bola2Servo/library/dynamixel/dynamixel.h"
#include <dynamixel.h>

//#include "/home/pi/SRG/Bola2Servo/library/dynamixel/syncWrite.cpp"
		// yang di komenbuat inverse kinematik
//#include "/home/pi/SRG/Bola2Servo/library/dynamixel/InversKinematik.cpp"

//#include "/home/pi/SRG/Bola2Servo/library/movement/move.h"
//#include "/home/pi/SRG/Bola2Servo/library/movement/moveArray.h"


//------------------------------------------------Sensor---------------------------------
#include <math.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <linux/types.h>
#include <sys/ioctl.h>
#include <stdint.h>

#include "/home/pi/SRG/Bola2Servo/library/sensor/i2c-dev.h"
#include "/home/pi/SRG/Bola2Servo/library/sensor/L3G.h"
#include "/home/pi/SRG/Bola2Servo/library/sensor/LSM303.h"
#include "/home/pi/SRG/Bola2Servo/library/sensor/sensor.c"

//-----------------------------------------------WIFI-----------------------------------
#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <netdb.h>
#include <sstream>
#include <inttypes.h>
//#include "/home/pi/SRG/Bola2Servo/library/wifi/wifi.cpp"

#pragma comment (lib, "dynamixel.lib")

#define DEFAULT_PORTNUM 0 // misalnya 
#define DEFAULT_BAUDNUM 1

using namespace std;
using namespace cv;

VideoCapture cap(0); //fungsi yang menintegrasikan kamera menggunakan variable cap
Mat matWebCam; // Variable matriks untuk kamera
Mat matProcessed; // Variable matriks untuk kamera
Mat matWebcam2; // Variable matriks untuk kamera
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
int c_image,d_image,e_image,f_image;
int b_image;
int a_image;
double setpointx_image;
double setpointy_image;
double nilai_sensorx_image;
double nilai_sensory_image;
double errorx_image;
double errory_image;
double outPx_image;
double outDx_image,outPy_image;
double outDy_image;
double PIDx_image;
double PIDy_image;
double errorDx_image;
double errorDy_image;

#endif
