#ifndef COBARDAN_C
#define COBARDAN_C

#include "/home/pi/SRG/Bola2Servo/library/allLib.h"
#include "/home/pi/SRG/Bola2Servo/kamera.cpp"

void sensen(){

        string status;
        enableIMU();
        nilaisensor=bacaACC3(Pacc_raw);
        //cout<<status<<endl;
        //bacaMAG(Pmag_raw, 1);
        //nilaisensor = AccXangle;
//cout<<"a  "<<nilaisensor<<endl;
//sleep(1);

}


void berdiri(){

        double x,y,z,sudutX,sudutY,sudutZ,x2,y2,z2,sudutX2,sudutY2,sudutZ2,sudutNgurang;
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
        x=-10.4;// tinggi kaki kanan //-13.4
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

        dxl_write_word(3,30,300);
        dxl_write_word(4,30,724);
        // inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,50,'2');
         inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,512,512,'2',500,500,250,780,500,500);
        cout<<"Masukkan Speed: ";
        //cin>>speed;
        sleep(3);//5
         //kirimPacketInverse(x,y);
        //cin>>speed;
        //for(int i=1;i<=10;i++){
		}
		
void jalan(){
	 double x,y,z,sudutX,sudutY,sudutZ,x2,y2,z2,sudutX2,sudutY2,sudutZ2,sudutNgurang;
        int speed, com7, com8;
			//-----------------------------------------------------------------------------
							        // MIRING KANAN//
        f2=0;
        while(f2<=90.0)
         //for(int i=0;i<=38;i++)
                {f2=f2+a;
        //cout<<"Masukkan X: ";
         sudutNgurang=f2;

        x=-10.4;//-2*sin(sudutNgurang*3.14/180)*2;
        y=1*sin(sudutNgurang*3.14/180);//
        z=0; //2.5

        sudutX=-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=-5;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-10.4;//+sin(sudutNgurang*3.14/180)*2;
        y2=1*sin(sudutNgurang*3.14/180);//-1.5
        z2=0;

        sudutX2=-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=-5;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));

        speed=100;//cos(sudutNgurang*3.14/360);

        //inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
         inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);
//      usleep(1000);
//         cout<<"Masukkan sudut X: "<<f2<<endl;
        }
		
        f2=0;
	//sleep(5); 
	usleep(5000);
       							 //  ANGKAT KAKI KIRI DAN MENDARAT //
 	cout<<"Masukkan sudut X: ";
         //for(int i=0;i<=76;i++)
    while(f2<=180){
		f2=f2+(0.15);

	sudutNgurang=f2;
        x=-10.4+0*sin(sudutNgurang*3.14/180); //+2
        y=1+2*sin(sudutNgurang*3.14/180);//cos(sudutNgurang*3.14/360);//1.5
        z=-0.5+0.5*cos(sudutNgurang*3.14/180); //0+0.5-0.5*cos(sudutNgurang*3.14/180);1

        sudutX=-2;//+8*sin(sudutNgurang*3.14/180);//*(pow(sin(sudutNgurang*3.14/180),2));*//0
        sudutY=-5;//-2*sin(sudutNgurang*3.14/360); /-3
        sudutZ=0;//-0.5+0.5*cos(sudutNgurang*3.14/180);//1*sin(sudutNgurang*3.14/180)*1.4;;//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-10.4+1*sin(sudutNgurang*3.14/180); //-11.4-0
        y2=1;//sin(sudutNgurang*3.14/180);// + pidy;//sin(sudutNgurang*3.14/180);//2.5+2
        z2=0.5-0.5*cos(sudutNgurang*3.14/180);//-0.5 //+0.5

        sudutX2=-2+20*sin(sudutNgurang*3.14/180);// - pidx;/*(pow(sin(sudutNgurang*3.14/180),2));*/-2 //9+16
        sudutY2=-5;//-2*cos(sudutNgurang*3.14/360);//-3
    	sudutZ2=0;//-1+1*cos(sudutNgurang*3.14/180);//-3*(pow(sin(sudutNgurang*3.14/180),2))//0
        speed=100;//+50*cos(sudutNgurang*3.14/360);

        //inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
        //baca sensor

	 inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);
        //sensen();
//              if(i>46){
                        //PID x
                        // P x
                              // P y
}
     usleep(50000);

        f2=0;
         //cout<<"Masukkan sudut X: ";
								        // BALIKIN MIRING //
 	//for(int i=0;i<=38;i++)
        while(f2<=90)
        {f2=f2+a;
         sudutNgurang=f2;
        x=-10.4;//-sin(sudutNgurang*3.14/180)*2;
        y=1-1*sin(sudutNgurang*3.14/180);//2.4
        z=-1;

        sudutX=-2+2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=-5;//+2*sin(sudutNgurang*3.14/180);
        sudutZ=0;//-2;//2;//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-10.4;//+sin(sudutNgurang*3.14/180)*2;
        y2=1-1*sin(sudutNgurang*3.14/180);//2.4
        z2=1;//0.2;//.2;

        sudutX2=-2+2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=-5;//+2*sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-2;//-3*(pow(sin(sudutNgurang*3.14/180),2
        speed=100;//cos(sudutNgurang*3.14/360);

//      inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
         inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);
        //usleep(1000);
//       cout<<"Masukkan sudut X: ";
                }
        f2=0;

         //cout<<"Masukkan sudut X: ";
        sleep(1);
							        // MIRING KIRI//
     //   for(int j=0;j<=76;j++){
        while(f2<=90)

        {f2=f2+a;
        sudutNgurang=f2;
        x=-10.4;//+sin(sudutNgurang*3.14/180)*2;
        y=-1*sin(sudutNgurang*3.14/180);//2.4
        z=-1;//0.5;//cos(sudutNgurang*3.14/180);

        sudutX=2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
 	sudutY=-5;//+1*sin(sudutNgurang*3.14/180);
        sudutZ=0;//2;//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-10.4;//-sin(sudutNgurang*3.14/180)*2.4;
        y2=-1*sin(sudutNgurang*3.14/180);//2.4
        z2=1;//0.2;//cos(sudutNgurang*3.14/180);

        sudutX2=2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=-5;//+1*sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-2;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        speed=100;//cos(sudutNgurang*3.14/360);
//      inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);
                        }
        usleep(5000);
						        //ANGKAT KAKI KANAN DAN MENDARAT/
        f2=0;
        //======================
        outdx = 0;
        outdy = 0;
        edysblm = 0;
        edxsblm = 0;
        pidx = 0;
        pidy= 0;
        //==================

        while(f2<=180){
        f2=f2+0.08;
        sudutNgurang=f2;
        x=-10.4+1*sin(sudutNgurang*3.14/180);
        y=-1+0*sin(sudutNgurang*3.14/180);//1+1*sin(sudutNgurang*3.14/180);//- pidy;//2.4
        z=-1+1.5*sin(0.5*sudutNgurang*3.14/180);

        sudutX=2+10*sin(sudutNgurang*3.14/180);//- pidx;/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=-5;//sin(2*sudutNgurang*3.14/360);//+sin(sudutNgurang*3.14/180);
        // speed=200*cos(sudutNgurang*3.14*0.5/180);
        sudutZ=0;//-0.5-0.5*cos(sudutNgurang*3.14/180);//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-10.4+0*sin(sudutNgurang*3.14/180);
        y2=-1-1*sin(sudutNgurang*3.14/180);//2.4
        z2=1-1.5*sin(0.5*sudutNgurang*3.14/180);
 	//z2=-1*cos(sudutNgurang*3.14/180);

        sudutX2=2;//2+12*sin(sudutNgurang*3.14/180);//sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=-5;//sin(2*sudutNgurang*3.14/360);
        sudutZ2=0;//-1-1*cos(sudutNgurang*3.14/180);//-3*(pow(sin(sudutNgurang*3.14/180),2));
        speed=100;//+50*cos(sudutNgurang*3.14/360);
 	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);
//      inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
//		usleep(500);    
    }
        usleep(50000);
        f2=0;
						        // BALIKIN MIRING//

        while(f2<=90){
        f2=f2+a;
        sudutNgurang=f2;
        x=-10.4;//+sin(sudutNgurang*3.14/180)*1.4;
        y=-1+1*sin(sudutNgurang*3.14/180);//2.4
        z=0.5;//cos(sudutNgurang*3.14/180);

        sudutX=2-2*sin(sudutNgurang*3.14/180);
        sudutY=-5;//-1*sin(sudutNgurang*3.14/180);
        sudutZ=0;//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-10.4;//-sin(sudutNgurang*3.14/180)*1.4;
        y2=-1+1*sin(sudutNgurang*3.14/180);//2.4
        z2=-0.5;//cos(sudutNgurang*3.14/180);

        sudutX2=2-2*sin(sudutNgurang*3.14/180);
        sudutY2=-5;//-1*sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        speed=100;//cos(sudutNgurang*3.14/360);

//      inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);

                }
                f2=0;
                //usleep(500000);
                sleep(1);
							        // MIRING KANAN //
/*

         while(f2<=90){
        f2=f2+a;
        sudutNgurang=f2;
        x=-10.4;//+sin(sudutNgurang*3.14/180)*2;
        y=2*sin(sudutNgurang*3.14/180);//2.4;
        z=0.5;//cos(sudutNgurang*3.14/180);

        sudutX=-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
  /*      sudutY=-5;//+2*sin(sudutNgurang*3.14/180);
        sudutZ=0;//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-10.4;//-sin(sudutNgurang*3.14/180)*2.4;
        y2=2*sin(sudutNgurang*3.14/180);//2.4
        z2=-0.5;//-0.2;//cos(sudutNgurang*3.14/180);

        sudutX2=-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
    /*    sudutY2=-5;//+2*sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        speed=100;//cos(sudutNgurang*3.14/360);
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);
//      inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
                        }

   	usleep(5000);
        						//ANGKAT KAKI DAN MENDARAT//
        f2=0;
        //=======================
        outdx = 0;
        outdy = 0;
        edysblm = 0;
        edxsblm = 0;
        pidx = 0;
        pidy= 0;
        //=======================

        while(f2<=180){
        f2=f2+a;
        sudutNgurang=f2;

        x=-13.4;//+2*sin(sudutNgurang*3.14/180);
	y=2;//-0*sin(sudutNgurang*3.14/180);//2.4
        z=1-1*sin(2*sudutNgurang*3.14/180);

        sudutX=-2;//+12*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
    /*    sudutY=-5+0*sin(sudutNgurang*3.14/180);
        sudutZ=0;//cos(sudutNgurang*3.14/180);//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-13.4+1*sin(sudutNgurang*3.14/180)*1.5;
        y2=2;//-2*sin(sudutNgurang*3.14/180);//+pidy;//2.4
        z2=-1+1*sin(2*sudutNgurang*3.14/180);

        sudutX2=-2+16*sin(sudutNgurang*3.14/180);//- pidx;//sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
   /*     sudutY2=-5+0*sin(sudutNgurang*3.14/180);//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-1+1*cos(sudutNgurang*3.14/180);//-3*(pow(sin(sudutNgurang*3.14/180),2));
        speed=100;//1+100*cos(sudutNgurang*3.14/360);
	//        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
 	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500);
         //sensen();
	//      while(i>=26){
        //PID x
                // P x
       /* epx = setpointx - nilaisensor;
        outpx = kpx*epx;
        //D x
        edx = epx - edxsblm;
        outdx = kdx*edx;
        edxsblm = epx;

        pidx = outpx + outdx;//PID y
        // P y
        erry = cos(epx) + sin(epx);
        epy = setpointy - erry;
        outpy = kpy*epy;
        // D y
        edy = epy - edysblm;
        outdy = kdy*edy;
        edysblm = epy;

        pidy = outpy + outdy;
        //cout<<"a  "<<nilaisensor<<endl;
*/
	//usleep(5000);
 /*}
	f2=0;
   	usleep(5000);
        // BALIKIN MIRING//
        while(f2<=90){
        f2=f2+a;
        sudutNgurang=f2;

        x=-10.4;//+sin(sudutNgurang*3.14/180)*1.4;
        y=2-2*sin(sudutNgurang*3.14/180);//2.4
        z=0;//cos(sudutNgurang*3.14/180);

        sudutX=-2+2*sin(sudutNgurang*3.14/180);
        sudutY=-5;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//-2;//3*(pow(sin(sudutNgurang*3.14/180),2));

        x2=-10.4;//-sin(sudutNgurang*3.14/180)*1.4;
        y2=2-2*sin(sudutNgurang*3.14/180);//2.4
        z2=0;//0.2;//cos(sudutNgurang*3.14/180);

        sudutX2=-2+2*sin(sudutNgurang*3.14/180);
        sudutY2=-5;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));
        speed=50;//*cos(sudutNgurang*3.14/360);
//        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
        inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,512,512,'2',500,500,250,780,500,500);

                }*/
//   cout<<nilaisensor<<endl;
//sleep(500000);
//        usleep(80000);
       
    usleep(30000);
}

#endif


