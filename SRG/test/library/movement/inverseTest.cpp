#ifndef INVERSETEST_C
#define INVERSETEST_C

//#include "/home/pi/systemTest/library/allLib.h"
#include "/home/pi/systemTest/library/movement/moveArray.h"
#include "/home/pi/systemTest/library/dynamixel/syncWrite.cpp"

int main(){

if(dxl_initialize(0,1)==0){
        cout<<"Error connecting"<<endl;
        return 0;
    }
    
else{
		cout<<"connect success!"<<endl;
	}

while(1){
	double x,y,z,sudutX,sudutY,sudutZ,x2,y2,z2,sudutX2,sudutY2,sudutZ2,sudutNgurang;
	int speed;

/*        cout<<"Masukkan sudut X: ";
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
        x=-10;//-sin(sudutNgurang*3.14/180)*2;
        y=0;
        z=0;
        sudutX=0;
        sudutY=9;
        sudutZ=0;
        x2=-10;
        y2=0;
        z2=0;
        sudutX2=0;
        sudutY2=8;
        sudutZ2=0;

	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,50,'2');
	cout<<"Masukkan Speed: ";
	//cin>>speed;
	sleep(5);
		//kirimPacketInverse(x,y);

	//for(int i=1;i<=10;i++){
	// MIRING //
	
     	
	 for(int i=0;i<=38;i++){
       	
	 sudutNgurang=2.4*i;
        x=-10;//-sin(sudutNgurang*3.14/180)*2;
        y=-1.5*sin(sudutNgurang*3.14/180);//2.4
        z=0;
        sudutX=1.5*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=9;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//3*(pow(sin(sudutNgurang*3.14/180),2));
	x2=-10;//+sin(sudutNgurang*3.14/180)*2;
      	y2=-1.5*sin(sudutNgurang*3.14/180);//2.4
      	z2=0;
        sudutX2=-1.5*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=9;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));

	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');
//	sleep(1);
	}
	
	usleep(100);	
	//  ANKAT KAKI DAN MENDARAT //

	 for(int i=0;i<=76;i++){
	 sudutNgurang=2.4*i;
	x=-10-sin(sudutNgurang*3.14/180)*1.4;
        y=-1.5;//cos(sudutNgurang*3.14/360);//2.4
        z=-0.5+0.5*cos(sudutNgurang*3.14/180);
	sudutX=1.5-7*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/	
	sudutY=9;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//-1+1*cos(sudutNgurang*3.14/180);//1*sin(sudutNgurang*3.14/180)*1.4;;//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10+sin(sudutNgurang*3.14/180)*1.7;
      	y2=-1.5;//sin(sudutNgurang*3.14/180);//2.4
      	z2=0.5-0.5*cos(sudutNgurang*3.14/180);
        sudutX2=1;//8*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=9+1*sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-0.5+0.5*cos(sudutNgurang*3.14/180);//-3*(pow(sin(sudutNgurang*3.14/180),2));
  	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');
		}
	usleep(100);
	// BALIKIN MIRING //

        for(int i=0;i<=38;i++){
	 sudutNgurang=2.4*i;
        x=-10;//-sin(sudutNgurang*3.14/180)*2;
        y=-1.5+1.5*sin(sudutNgurang*3.14/180);//2.4
        z=-1;
        sudutX=1.5-1.5*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=9;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//-2;//2;//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10;//+sin(sudutNgurang*3.14/180)*2;
        y2=-1.5+1.5*sin(sudutNgurang*3.14/180);//2.4
        z2=1;//.2;
        sudutX2=1.5-1.5*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=9;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-2;//-3*(pow(sin(sudutNgurang*3.14/180),2 
	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');     
 }
	usleep(100);
	// MIRING //	
for(int j=0;j<=7;j++){


	for(int i=0;i<=38;i++){
	 sudutNgurang=2.4*i;
        x=-10;//+sin(sudutNgurang*3.14/180)*2;
        y=1*sin(sudutNgurang*3.14/180);//2.4
        z=-0.8;//cos(sudutNgurang*3.14/180);
        sudutX=-1.5*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=9;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//2;//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10;//-sin(sudutNgurang*3.14/180)*2.4;
        y2=1*sin(sudutNgurang*3.14/180);//2.4
        z2=1;//cos(sudutNgurang*3.14/180);
        sudutX2=-1.5*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=9;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-2;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');      
		}
        usleep(100);
	//ANGKAT KAKI DAN MENDARAT//

	for(int i=0;i<=76;i++){
 	 sudutNgurang=2.4*i;
        x=-10+sin(sudutNgurang*3.14/180)*3;
        y=1;//sin(sudutNgurang*3.14/180);//2.4
        z=-1*cos(sudutNgurang*3.14/180);
        sudutX=-1.8;//-8*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=9+1*sin(sudutNgurang*3.14/180);//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//-1-1*cos(sudutNgurang*3.14/180);//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10-sin(sudutNgurang*3.14/180)*1.5;
        y2=1;//sin(sudutNgurang*3.14/180);//2.4
        z2=1*cos(sudutNgurang*3.14/180);
        sudutX2=-1.5+8*sin(sudutNgurang*3.14/180);//sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=9;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-1-1*cos(sudutNgurang*3.14/180);//-3*(pow(sin(sudutNgurang*3.14/180),2));
  	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');

			}

	usleep(100);
	// BALIKIN MIRING//
	
	for(int i=0;i<=38;i++){
         sudutNgurang=2.4*i;
        x=-10;//+sin(sudutNgurang*3.14/180)*1.4;
        y=1-1*sin(sudutNgurang*3.14/180);//2.4
        z=1;//cos(sudutNgurang*3.14/180);
	sudutX=-1.5+1.5*sin(sudutNgurang*3.14/180);
        sudutY=9;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10;//-sin(sudutNgurang*3.14/180)*1.4;
        y2=1-1*sin(sudutNgurang*3.14/180);//2.4
        z2=-1;//cos(sudutNgurang*3.14/180);
	sudutX2=-1.5+1.5*sin(sudutNgurang*3.14/180);
        sudutY2=9;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');

		}
		usleep(100);
   // MIRING //


	for(int i=0;i<=38;i++){
         sudutNgurang=2.4*i;
        x=-10;//+sin(sudutNgurang*3.14/180)*2;
        y=-1*sin(sudutNgurang*3.14/180);//2.4
        z=1;//cos(sudutNgurang*3.14/180);
        sudutX=1.5*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=9;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10;//-sin(sudutNgurang*3.14/180)*2.4;
        y2=-1*sin(sudutNgurang*3.14/180);//2.4
        z2=-1;//cos(sudutNgurang*3.14/180);
        sudutX2=1.5*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=9;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');
			}

   usleep(100);
        //ANGKAT KAKI DAN MENDARAT//

        for(int i=0;i<=76;i++){
         sudutNgurang=2.4*i;
        x=-10-sin(sudutNgurang*3.14/180)*1.5;
        y=-1;//sin(sudutNgurang*3.14/180);//2.4
        z=1*cos(sudutNgurang*3.14/180);
        sudutX=1.5-8*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=9;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//-1+1*cos(sudutNgurang*3.14/180);//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10+sin(sudutNgurang*3.14/180)*1.5;
        y2=-1;//sin(sudutNgurang*3.14/180);//2.4
        z2=-1*cos(sudutNgurang*3.14/180);
        sudutX2=1.5;//+6*sin(sudutNgurang*3.14/180);//sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=9+1*sin(sudutNgurang*3.14/180);//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-1+1*cos(sudutNgurang*3.14/180);//-3*(pow(sin(sudutNgurang*3.14/180),2));
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');

			}

   usleep(100);
        // BALIKIN MIRING//

        for(int i=0;i<=38;i++){
         sudutNgurang=2.4*i;
        x=-10;//+sin(sudutNgurang*3.14/180)*1.4;
        y=-1+1*sin(sudutNgurang*3.14/180);//2.4
        z=-1;//cos(sudutNgurang*3.14/180);
        sudutX=1.5-1.5*sin(sudutNgurang*3.14/180);
        sudutY=9;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//-2;//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10;//-sin(sudutNgurang*3.14/180)*1.4;
        y2=-1+1*sin(sudutNgurang*3.14/180);//2.4
        z2=1;//cos(sudutNgurang*3.14/180);
        sudutX=1.5-1.5*sin(sudutNgurang*3.14/180);
        sudutY2=9;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,'2');

		}
	usleep(100);
	}
	sleep(3);
}
}

#endif
