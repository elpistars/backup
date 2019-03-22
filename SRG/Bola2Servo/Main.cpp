#ifndef MAIN_CPP
#define MAIN_CPP

#include "/home/pi/SRG/Bola2Servo/library/allLib.h"
#include "/home/pi/SRG/Bola2Servo/putarkanan.cpp"
#include "/home/pi/SRG/Bola2Servo/putarkanan1.cpp"
#include "/home/pi/SRG/Bola2Servo/cobardan.cpp"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h> 
#include <sys/types.h> 

int com = 0;
int cmd_img=0;
int main (){
	char * myfifo= "/tmp/myfifo";
	int pipe_stat;
	int status, pidpro;
	int fd;
	dxl_initialize(0,1);
	dxl_write_word(19,32,800);
	dxl_write_word(20,32,800);
	a_image=380;
	b_image=512;
	dxl_write_word(19,30,a_image);
	dxl_write_word(20,30,b_image);
	mkfifo(myfifo,0666);

    if(!cap.isOpened()) // kondisi dimana jika kamera tidak terdeteksi maka program akan tertutup
    	return -1;
    berdiri();	
    pidpro = fork();
    while(1){
	if (pidpro == -1)
	{
		perror("Trouble");
		exit(2);
	}
        else if (pidpro != 0)
	{
		fd=open(myfifo,O_RDONLY);	
		read(fd, &cmd_img, sizeof(cmd_img)); 
		cout<<"cmd_img: "<<cmd_img<<endl<<endl;
		close(fd);
		//cmd_img=2;
		switch(cmd_img){
			case 0:
				berdiri();
				break;
			case 1:
				jalan();
				break;
			case 2:
				putarkanan();
				break;
			case 3:
				putarkiri();
				break;	
		}
	}
	else{
		fd=open(myfifo,O_WRONLY);
		lihat();
		write(fd, &comimage, sizeof(comimage));
		close(fd);
	}

/*
if(com==0){
	lihat();//kl ingin tuning impro coment aj switchnya
	com=1;
	}
else{
	switch(comimage){
	case 0:
		berdiri();
		break;
	case 1:
		jalan();
		break;
	case 2:
		putarkanan();
		break;
		
	case 3:
		putarkiri();
		break;	
	}
	com=0;
	}*/
    }
return(0);
}

#endif
