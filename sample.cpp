#include "EasyBMP.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
using namespace std;
#define PI 3.14
#define WIDTH 1024
#define HEIGHT 768
#define AL 100000
float rain[AL][5]={};
int raincount=0;
float oldTime=0;
float deltaTime=0;
void shiftf(int j){
	for (int i=j+1;i<raincount; i++){
		for (int k=0;k<5;k++){
		rain[i-1][k]=rain[i][k];
	}}

}
EasyBMP::RGBColor black(0, 0, 0);  
	  EasyBMP::Image img(WIDTH, HEIGHT, "sample.bmp", black);
void fall(){
	deltaTime = (clock() - oldTime)/100000;
	double fps = (1.0 / deltaTime) * 1000.0;

	for(int i=0;i<raincount;i++){
		rain[i][0]=rain[i][0]+(deltaTime*5.0*((float)rain[i][2]*abs(cos((float)rain[i][3] / (2*PI)))));
		rain[i][1]=rain[i][1]+(deltaTime*5.0*((float)rain[i][2]*abs(sin((float)rain[i][3] / (2*PI)))));

	}
	int i=0;
	while (i< raincount){
		if (rain[i][0]<0 || rain[i][0]>WIDTH || rain[i][1]<0 || rain[i][1]>HEIGHT){
			shiftf(i);
			raincount-=1;
			i-=1;
		}
		i+=1;
	}

	
	oldTime = clock();

}
void plotLineHigh(int x0,int y0,int x1,int y1){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int xi = 1;
        if (dx < 0){
            xi = -1;
            dx = -dx;
        }
        int D = (2 * dx) - dy;
        int x = x0;

        for (int y=y0;y<y1+1;y++){
		if (x<=0 || x>=WIDTH || y<=0 || y>=HEIGHT){return;}
		img.SetPixel(x, y, EasyBMP::RGBColor(255, 255, 255));
            //oled.drawPixel(x,y,WHITE);
            if (D > 0){
                x = x + xi;
                D = D + (2 * (dx - dy));
            }else{
                D = D + 2*dx;
                };
        };
        };
void plotLineLow(int x0,int y0,int x1,int y1){
        int dx = x1 - x0;
        int dy = y1 - y0;
        int yi = 1;
        if (dy < 0){
            yi = -1;
            dy = -dy;
        }
        int D = (2 * dy) - dx;
        int y = y0;

        for (int x=x0;x<x1+1;x++){
		if (x<=0 || x>=WIDTH || y<=0 || y>=HEIGHT){return;}
		img.SetPixel(x, y, EasyBMP::RGBColor(255, 255, 255));
            //oled.drawPixel(x,y,WHITE);
            if (D > 0){
		y = y + yi;
                D = D + (2 * (dy - dx));
            }else{
                D = D + 2*dy;
        }
        }
        }


void line(int x0,int y0,int x1,int y1){
                if (abs(y1 - y0) < abs(x1 - x0)){
                        if (x0 > x1){
                                plotLineLow(x1, y1, x0, y0);
                        }else{
                                plotLineLow(x0, y0, x1, y1);
                        };
                }else{
                        if (y0 > y1){
                                plotLineHigh(x1, y1, x0, y0);
                        }else{
                                plotLineHigh(x0, y0, x1, y1);
                        };
                };
        };























	  
int main()
{
  	int start =clock();
	  // sizeX, sizeY, FileName, BackgroundColor
	  int frame=0;
	  while (true){
		char buf[50];
		sprintf( buf,"frame%d.bmp",frame);
	  	img=EasyBMP::Image(WIDTH, HEIGHT, buf, EasyBMP::RGBColor(0,0,0));
		int cur=clock()-start/100000;
		if (cur>1){ start=clock();
		  for(int i=0; i< rand()%100;i++){
		  if ( (raincount<AL)){
			raincount+=1;
		  	rain[raincount-1][0]=rand()%WIDTH;
			rain[raincount-1][1]=0;
			rain[raincount-1][2]=10+rand()%20;
			rain[raincount-1][3]=PI*500.0;
		  
		  }}
	 	fall();
	       for(int i=0; i<raincount;i++){
	       		line(rain[i][0],\
			rain[i][1],\
			rain[i][0]+(((float)rain[i][2]*abs(cos((float)rain[i][3] / (2*PI))))),\
			rain[i][1]+(((float)rain[i][2]*abs(sin((float)rain[i][3] / (2*PI)))))
			);
	       } 	
	       
	  img.Write();
	  for (int x=0; x<WIDTH;x++){
	  	for (int y=0; y<HEIGHT;y++){
		
		img.SetPixel(x, y, EasyBMP::RGBColor(0, 0, 0));
		
		}
	  
	  }}
	  }
	  return 0;
}
