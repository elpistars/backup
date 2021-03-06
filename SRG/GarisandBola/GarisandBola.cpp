// GarisandBola.cpp : Defines the entry point for the console application.
//

#include <opencv2/objdetect/objdetect.hpp> // Library Opencv
#include <opencv2/core/core.hpp> // Library Opencv
#include <opencv2/highgui/highgui.hpp> // Library Opencv
#include <opencv2/imgproc/imgproc.hpp>// Library Opencv
#include <opencv2/opencv.hpp>// Library Opencv
#include <iostream>
#include <stdio.h>
//#include <Windows.h>
//#include <conio.h>
#include <stdlib.h>
#include <dynamixel.h> // USB2DYNAMIXEL

#pragma comment (lib, "dynamixel.lib")

#define DEFAULT_PORTNUM 0 // misalnya 
#define DEFAULT_BAUDNUM 1
int FRAME_WIDTH=640;
int FRAME_HEIGHT=480;
int a=512;
int b,c,all;

using namespace cv;
using namespace std;

int korx, kory, x, area;
int p1=0;
int p2=0;

Mat imgOriginal;

//void contour(Mat image);

void contour(){

  x=0;
  Mat imgHSV;
  cvtColor(imgOriginal, imgHSV, COLOR_RGB2GRAY); //Convert the captured frame from BGR to HSV

  Mat imgThresholded;
  threshold(imgHSV,imgThresholded,133,255,0);
  //inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

  Mat gray;
  //morphological opening (remove small objects from the foreground)
  erode(imgThresholded, gray, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  dilate( imgThresholded, gray, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

  //morphological closing (fill small holes in the foreground)
  dilate( imgThresholded, gray, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  erode(imgThresholded, gray, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );


  //imshow("Thresholded Image", imgThresholded); //show the thresholded image
  //imshow("Original", imgOriginal); //show the original image

     //namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
	 //  imshow( "Display window", image );
	 //   Mat gray;
	 //  cvtColor(image, gray, CV_BGR2GRAY);

	 Canny(gray, gray, 100, 200, 3);

     /// Find contours
     vector<vector<Point> > contours;
	/* vector<Point> fifthcontour = contours.at(4);
			for (int i = 0; i < fifthcontour.size(); i++) {
			Point coordinate_i_ofcontour = fifthcontour.size();
			cout << endl << "contour with coordinates: x = " << coordinate_i_ofcontour.x << " y = " << coordinate_i_ofcontour.y;
			}*/
     vector<Vec4i> hierarchy;
     RNG rng(12345);
     findContours( gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

     /// Draw contours
	 Mat drawing = Mat::zeros( gray.size(), CV_8UC3 );

	 for(unsigned int i=0; i<contours.size(); i++)
	{

		for(unsigned int j=0; j<contours[i].size(); j++)
		{
         //cout << "Point(x,y)=" << contours[i][j].x << "," << contours[i][j].y << endl;
		 //cout<< i<<","<<j<< endl;
			if (i==0 && j>50 && j<53){
			p1=1;
			korx = contours[i][j].x;
			kory = contours[i][j].y;
			circle(drawing,cvPoint(korx,kory),20,100,3,2,0);
			line(drawing,cvPoint(273,0),cvPoint(273,480),255,2,30,0); //garis pada layar
			line(drawing,cvPoint(366,0),cvPoint(366,480),255,2,30,0); // garis pada layar
			line(drawing,cvPoint(0,180),cvPoint(640,180),255,2,30,0);
			line(drawing,cvPoint(0,300),cvPoint(640,300),255,2,30,0); // garis pada layar
			}
			
			else{
			p2=1;
			}

		}

		for( int i = 0; i< contours.size(); i++ )
		{

         Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
         drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );

         ////////////////////
           vector<Moments> mu(contours.size() );
            for( int i = 0; i < contours.size(); i++ )
               { mu[i] = moments( contours[i], false ); }

            ///  Get the mass centers:
            vector<Point2f> mc( contours.size() );
            for( int i = 0; i < contours.size(); i++ )
               { mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }

		 ///////////////////
         //cout<<"Center = "<<mc[i].x << ","<< mc[i].y<<endl;
		 //if (i==1){
		 //korx = mc[i].x;
		 //kory = mc[i].y;
		 //circle(drawing,cvPoint(korx,kory),5,100,3,2,0);
		 //}
		}

     //imshow( "Result window", drawing );
     // waitKey(0);

	}
 }

void gerak(){
	p1=0;
	
	if(korx<273){
		b=a+10;
		a=b;
			if ( a <= 0 ){
			a = 0;
			}
			else if ( a >= 1023 ){
			a = 1023;
			}
		cout << a << endl;
		dxl_write_word(20,30,a);
	}
	else if(korx>366){
		c=a-10;
		a=c;
			if ( a <= 0 ){
			a = 0;
			}
			else if ( a >= 1023 ){
			a = 1023;
			}
		cout << a << endl;
		dxl_write_word(20,30,a);
	}
	else{
			if ( a <= 0 ){
			a = 0;
			}
			else if ( a >= 1023 ){
			a = 1023;
			}
		cout << a << endl;
		dxl_write_word(20,30,a);
	}
}

void bola(){

  Mat imgLab;
  cvtColor(imgOriginal, imgLab, COLOR_BGR2Lab); //Convert the captured frame from BGR to HSV
  
  Mat imgThresh;
  //threshold(imgLab,imgThresh,215,255,0);
  inRange(imgLab, Scalar(117, 130, 160), Scalar(235, 172, 256), imgThresh); //Threshold the image
  //inRange(imgLab, Scalar(0, 132, 0), Scalar(254, 256, 256), imgThresh); //Threshold the image
  GaussianBlur(imgThresh, imgThresh,Size(9,9), 1.5);	//ngeblur warna pada kamera yang sudah terproses agar mudah di deteksi
  
  //morphological opening (remove small objects from the foreground)
  erode(imgThresh, imgThresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  dilate(imgThresh, imgThresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

  //morphological closing (fill small holes in the foreground)
  dilate(imgThresh, imgThresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  erode(imgThresh, imgThresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
	
  //line(matWebCam,cvPoint(213,0),cvPoint(213,480),255,2,30,0); //garis pada layar
  //line(matWebCam,cvPoint(426,0),cvPoint(426,480),255,2,30,0); // garis pada layar
  //line(matWebCam,cvPoint(0,120),cvPoint(640,120),255,2,30,0);
  //line(matWebCam,cvPoint(0,360),cvPoint(640,360),255,2,30,0); // garis pada layar
  //imshow("Mantap", imgTresh);

  Moments moment = moments (imgThresh); // fungsi moment untuk mengetahui luas objek yang terdeteksi
	
	area = moment.m00;
	if(area >= 80000){
		cout << "Ketemu Bola" << endl;
		/*p1=1;
		 korx = moment.m10/area;
		 kory = moment.m01/area;*/
	}
	else{
		x=1;
	}
}

 int main( int argc, char** argv )
 {
	dxl_initialize(0,1);
	dxl_write_word(20,32,1023);
	dxl_write_word(20,30,a);

	VideoCapture cap(0); //capture the video from web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }

    //namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
    //namedWindow("Thresholded Image",CV_WINDOW_AUTOSIZE);

    while (true)
    {
		cap.read(imgOriginal);

		/*bool bSuccess = cap.read(imgOriginal); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }*/

		bola ();

		if( x==1 ){
			contour ();

			if(p1==1){
				//gerak();
				cout << "gerak" << endl;
				cout << "korx" << korx << endl;
			}
			else if(p2==1){
				p2=0;
				cout << "Tidak Ada Garis" <<endl;
			}
		}
	}

   return 0;

}

