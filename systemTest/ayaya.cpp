#ifndef AYAYA_C
#define AYAYA_C

#include "/home/pi/systemTest/ayachan.cpp"
#include "/home/pi/systemTest/library/allLib.h"
#include "/home/pi/systemTest/library/dynamixel/syncWrite.cpp"
//#include "/home/pi/systemTest/searchimage.cpp"
//#include "/home/pi/systemTest/pointImage.cpp"

using namespace std;

int comsen=0;
int comnentu=0;

pthread_mutex_t lock;
pthread_t thread1,thread2,thread3,thread4,thread5;
//void *geraklurus(void *arg){
void geraklurus(){
//com=0;	
			
switch(comnentu){
	case 0:
		berdiri();
		comnentu=3;
		comkan=1;
		break;
	case 1:
		switch(comger){
			case 1:
				miring();
				comnentu=1;
                		comger=2;
				break;
			case 2:
				miring2();
				comnentu=1;
                		comger=3;
				break;
			case 3:
				miring3();
				comnentu=1;
		                comger=1;
				break;
		}
	case 2:
		switch(comkir){
			case 1:
				kiriputar1();
				comnentu=2;
		                comkir=2;
				break;
			case 2:
				kiriputar2();
				comnentu=2;
		                comkir=1;
				break;
			}
	case 3:
		switch(comkan){
			case 1:
				kananputar1();
				comnentu=3;
                		comkan=2;
				break;
			case 2:
				kananputar2();
				comnentu=3;
                		comkan=1;
				break;
			}
}
//comcam=1;
}


int main(){
	
int result;
comger=0;
//com=1;
int i=0;


//=================Dynamixel========================	
    result = dxl_initialize(0,1);
    if(result == 1){
        printf("Sukses buka koneksi :)");}
	else{
        printf("Gagal buka koneksi :(");
    }
/*						
//=================ImageProc====================	
	dxl_write_word(20,30,450); // kamera ke posisi tengah
	dxl_write_word(19,30,512);
 
	if(!cap.isOpened()) // kondisi dimana jika kamera tidak terdeteksi maka program akan tertutup
     return -1;
//	cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
//	cap.set(CV_CAP_PROP_FRAME_HEIGHT,240);
	aimage=400;
	bimage=512;
	error_sblmDximage=0;
	error_sblmDyimage=0;
	dxl_write_word(19,32,512); // set speed servo 
	dxl_write_word(20,32,512);
//======================================================
*/
	

while(1){
		
		/*	pthread_mutex_init(&lock,NULL);
/*			if(comcam==1){
				pthread_create(&thread2,NULL,melihat,NULL);
				pthread_join(thread2,NULL);}
			if (com==1){
				//cout<<"gerak"<<endl;
				if(comimage==0){comnentu=0;}
				else if(comimage==1){comnentu=1;}
				else if(comimage==2){comnentu=2;}
				else if(comimage==3){comnentu=3;}
				cout<<"comimage : "<<comimage<<endl;*
				pthread_create(&thread1,NULL,geraklurus,NULL);
				pthread_join(thread1,NULL);
	//		} 
			pthread_mutex_destroy(&lock);*/
geraklurus();
        }		
}
#endif

