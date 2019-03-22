
#ifndef PUTARKANAN1_CPP
#define PUTARKANAN1_CPP

#include "/home/pi/SRG/Bola2Servo/library/allLib.h"
#include "/home/pi/SRG/Bola2Servo/kamera.cpp"

void putarkanan(){
	
        double x,y,z,sudutX,sudutY,sudutZ,x2,y2,z2,sudutX2,sudutY2,sudutZ2,sudutNgurang;
        int speed, com7, com8;
       						 // MIRING //
        x=-10.4;
        y=0;// miring kaki
        z=0;// langkah kaki //0

        sudutX=0;//miring badan
        sudutY=-5;//kebungkukan badan //-4
        sudutZ=0;//putaran badan

        x2=-10.4; //tinggi kaki kiri
        y2=0;//3;
        z2=0;

        sudutX2=0;//-6;
        sudutY2=-5; //-4
        sudutZ2=0;

//        dxl_write_word(3,30,300);
  //      dxl_write_word(4,30,724);
        // inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,50,'2');
         inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,512,512,'2',500,500,250,780,500,500);
        cout<<"Masukkan Speed: ";
        //cin>>speed;
		
//	sleep(1);//5

        f2=0;
        while(f2<=90.0)
   {	
        f2=f2+0.1;
        sudutNgurang=f2;
        x=-10.4;//-2*sin(sudutNgurang*3.14/180)*2;
        y=-1*sin(sudutNgurang*3.14/180);//2.4
        z=0;
        sudutX=2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=-5;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//3*(pow(sin(sudutNgurang*3.14/180),2));
        x2=-10.4;//+sin(sudutNgurang*3.14/180)*2;
	y2=-1*sin(sudutNgurang*3.14/180);//2.4
        z2=0;
        sudutX2=2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=-5;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        speed=50;//cos(sudutNgurang*3.14/360);
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);
		
   }
        f2=0;
	//sleep(5000);
        usleep(1000);
// ------------------  ANKAT KAKI DAN MENDARAT //
        while(f2<=180)
        {
                f2=f2+a;
                sudutNgurang=f2;
                x=-10.4+2*sin(sudutNgurang*3.14/180);
		y=-1-0*sin(sudutNgurang*3.14/180);//cos(sudutNgurang*3.14/360);//2.4
                z=0;//0+0.8-0.8*cos(sudutNgurang*3.14/180);
                sudutX=2+30*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
                sudutY=-5;//+6*sin(sudutNgurang*3.14/360);
                sudutZ=512+40*sin(sudutNgurang*3.14/360);;//+20*sin(sudutNgurang*3.14/360);//1*sin(sudutNgurang*3.14/180)*1.4;;//3*(pow(sin(sudutNgurang*3.14/180),2));
                x2=-10.4;//+2*sin(sudutNgurang*3.14/180);
                y2=-1;//-1*sin(sudutNgurang*3.14/180);// + pidy;//sin(sudutNgurang*3.14/180);//2.4
                z2=0;//-0.8+0.8*cos(sudutNgurang*3.14/180);
                sudutX2=2+20*sin(sudutNgurang*3.14/180);// - pidx;/*(pow(sin(sudutNgurang*3.14/180),2));*/
                sudutY2=-5;//-4*sin(sudutNgurang*3.14/360);
                sudutZ2=512;//-40*cos(sudutNgurang*3.14/360);//-3*(pow(sin(sudutNgurang*3.14/180),2));
                speed=50;//+50*cos(sudutNgurang*3.14/360);
                inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500);
			
        }

        f2=0;
	//sleep(5000);
        usleep(1000);
// --------------------------- BALIKIN MIRING //
        while(f2<=90)
        {
                f2=f2+a;
                sudutNgurang=f2;
                x=-10.4;//-sin(sudutNgurang*3.14/180)*2;
                y=-1+1*sin(sudutNgurang*3.14/180);//2.4
                z=0;//1.6;
                sudutX=2-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
                sudutY=-5;//-6*sin(sudutNgurang*3.14/180);
                sudutZ=552;//-2;//2;//3*(pow(sin(sudutNgurang*3.14/180),2));
                x2=-10.4;//+sin(sudutNgurang*3.14/180)*2;
                y2=-1+1*sin(sudutNgurang*3.14/180);//2.4
                z2=0;//-1.6;//0.2;//.2;
                sudutX2=2-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
                sudutY2=-5;//+4*sin(sudutNgurang*3.14/180);
                sudutZ2=512;//-2;//-3*(pow(sin(sudutNgurang*3.14/180),2
                speed=100;//cos(sudutNgurang*3.14/360);
                inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500);
		
 }
        f2=0;
	//sleep(5000);
        sleep(1);

// ----------------------------- MIRING //
                while(f2<=90)
                {
                        f2=f2+a;
                        sudutNgurang=f2;
                        x=-10.4;//+sin(sudutNgurang*3.14/180)*2;
                        y=1*sin(sudutNgurang*3.14/180);//2.4
                        z=0;//0.5;//cos(sudutNgurang*3.14/180);
                        sudutX=-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
                        sudutY=-5;//+1*sin(sudutNgurang*3.14/180);
                        sudutZ=552;//2;//3*(pow(sin(sudutNgurang*3.14/180),2));
                        x2=-10.4;//-sin(sudutNgurang*3.14/180)*2.4;
                        y2=1*sin(sudutNgurang*3.14/180);//2.4
                        z2=0;//0.2;//cos(sudutNgurang*3.14/180);
                        sudutX2=-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
                        sudutY2=-5;//+1*sin(sudutNgurang*3.14/180);
                        sudutZ2=512;//-2;//-3*(pow(sin(sudutNgurang*3.14/180),2));
                        speed=100;//cos(sudutNgurang*3.14/360);
                        inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500);
				
                }
		//sleep(5000);
                usleep(1000);
// ------------------------ ANGKAT KAKI DAN MENDARAT/
                f2=0;

                while(f2<=180){
					
                        f2=f2+a;
                        sudutNgurang=f2;
                        x=-10.4+0*sin(sudutNgurang*3.14/180);
                        y=1;//+3*sin(sudutNgurang*3.14/180);//- pidy;//2.4
                        z=0;//-0.4-0.4*cos(sudutNgurang*3.14/180);
			sudutX=-2+13*sin(sudutNgurang*3.14/180);//- pidx;/*(pow(sin(sudutNgurang*3.14/180),2));*/
                        sudutY=-5;//-4*sin(sudutNgurang*3.14/360);//+sin(sudutNgurang*3.14/180);
                        //speed=200*cos(sudutNgurang*3.14*0.5/180);
                        sudutZ=552-40*sin(sudutNgurang*3.14/360);//3*(pow(sin(sudutNgurang*3.14/180),2));
                        x2=-10.4+2*sin(sudutNgurang*3.14/180);
                        y2=1+0*sin(sudutNgurang*3.14/180);//2.4
                        z2=0.4-0.4*cos(sudutNgurang*3.14/180);
                        sudutX2=-2+16*sin(sudutNgurang*3.14/180);//sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
                        sudutY2=-5;//+2*sin(sudutNgurang*3.14/360);
                        sudutZ2=512;//+40*sin(sudutNgurang*3.14/360);//-3*(pow(sin(sudutNgurang*3.14/180),2));
                        speed=100;//+50*sin(sudutNgurang*3.14/180);
                        inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500);
					
                }usleep(5000);
                f2=0;
                // BALIKIN MIRING//

                while(f2<=90){
				
                        f2=f2+a;
                        sudutNgurang=f2;
                        x=-10.4;//+sin(sudutNgurang*3.14/180)*1.4;
                        y=-1+1*sin(sudutNgurang*3.14/180);//2.4
                        z=0;//cos(sudutNgurang*3.14/180);
                        sudutX=2-2*sin(sudutNgurang*3.14/180);
                        sudutY=-5;//-4+4*sin(sudutNgurang*3.14/180);
                        sudutZ=512;//3*(pow(sin(sudutNgurang*3.14/180),2));
                        x2=-10.4;//-sin(sudutNgurang*3.14/180)*1.4;
                        y2=-1+1*sin(sudutNgurang*3.14/180);//2.4
                        z2=0.8;//cos(sudutNgurang*3.14/180);
                        sudutX2=2-2*sin(sudutNgurang*3.14/180);
                        sudutY2=-5;//+2*sin(sudutNgurang*3.14/180);
                        sudutZ2=512;//-3*(pow(sin(sudutNgurang*3.14/180),2));
                        speed=100;//cos(sudutNgurang*3.14/360);
                        //inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
                        inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500);
					
						}

                f2=0;
                sleep(1);

        //      int id[] = {20};
        //      int data1[][18] = {512};
        //      int delay1[] = {1000};
        //      int speed1[] = {100};
//              kirimPacketGerak(1, 1, 1, id, data1, 1, delay1, speed1);

}

#endif


