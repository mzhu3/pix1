#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int r,g,b;
  char info[20];
  int fd = open("pic.ppm", O_CREAT|O_TRUNC|O_WRONLY, 0644);
  snprintf(info,sizeof(info),"P3\n500 500 255\n");
  write(fd,info,strlen(info));
  int xcor,ycor,temp1;
  int centerX = 250;
  int centerY = 250;
  int radius = 100;
  for(xcor = 0; xcor < 500;xcor++){
    for(ycor= 0; ycor <500;ycor++){
      temp1 = ((xcor-centerX)*(xcor-centerX))+((ycor-centerY)*(ycor-centerY));
      if((radius * radius) <= temp1){
	r = (xcor+ycor)%256;
	g = (xcor+ycor)%256;
	b = 0;
	sprintf(info,"%d %d %d\n",r,g,b);
	write(fd,info,strlen(info));
      }
      else{
	r = (xcor*ycor)%256;
	g = (xcor*xcor)%256;
	b = (ycor*ycor)%256;;
	sprintf(info,"%d %d %d\n",r,g,b);
	write(fd,info,strlen(info));
      }
    }
  }      
  close(fd);
  return 0;
}
