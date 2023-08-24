#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int main(){
    int gd=DETECT,gm;
    float x1,y1,x2,y2,s1,s2,dx,dy,p,temp,flag=0;
    int i;
    clrscr();
    initgraph(&gd,&gm,"..//BGI");
    printf("\nEnter the co-ordinates of point 1");
    scanf("%f %f",&x1,&y1);

    printf("\nEnter the co-ordinates of point 2");
    scanf("%f %f",&x2,&y2);

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if((x2-x1)<0){
       s1=-1;
    }else if(x2-x1){
       s1=1;
    }else{
       s1=0;
    }

    if((y2-y1)<0){
	s2=-1;
    }else if((y2-y1)>0){
	s2=1;
    }else{
       s2=0;
    }
    if(dy>dx){
	temp=dx;
	dx=dy;
	dy=temp;
	flag++;
    }

    //zero decision parameter
    p=2*dy-dx;


    for(i=1;i<=dx;i++){
    if(i%5==0){
      putpixel((int)x1,(int)y1,15);
    }else{
      putpixel((int)x1,(int)y1,0);
     // putpixel((int)x1+1,(int)y1+1,15);
     // putpixel((int)x1-1,(int)y1-1,15);
      delay(10);
      if(p<0){
	 if(flag==1){
	     y1=y1+s2;
	 }else{
	     x1=x1+s1;
	 }

	 p=p+2*dy;

      }else{
	  x1=x1+s1;
	  y1=y1+s2;

	  p=p+2*dy-2*dx;
      }
    }
    getch();
    closegraph();
    return 0;
}