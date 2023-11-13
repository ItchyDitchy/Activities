#include<stdio.h>  
#include<conio.h>  
#include<graphics.h>  
#include<dos.h>

int main() {
    int gd=DETECT,gm;  
    initgraph(&gd,&gm,"c:\\tc\\bgi");  
    setbkcolor(9);  
    line(130,100,290,100);  
      
    line(165,100,165,155);  
    arc(150,155,100,0,15);  
    line(180,100,180,170);
	line(190,100,190,170);  
  
    circle(220,140,10);  
    line(220,130,255,130);  
    line(255,100,255,170);  
    line(265,100,265,170);  

    getch();

    return 0;
}