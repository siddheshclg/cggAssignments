
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
void delay(unsigned int);

int main(){
	int gd  = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the operation to perform\n");
	printf("1.Translation\n2.Scaling\n3.Rotation");
	int choice;
	scanf("%d", &choice);
	if(choice == 1){
		printf("Before translation");
		line(150,200,275,100);
		line(275,100,400,200);
		rectangle(150,200,400,400);
		rectangle(255,340,295,400);
		rectangle(190,240,220,270);
		rectangle(330,240,360,270);
		delay(2000);
		cleardevice();
		printf("Enter the translating factor in x direction : ");
		int tx,ty;
		scanf("%d",&tx);
		printf("Enter the translating factor in y direction : ");
		scanf("%d",&ty);
		printf("After Translation");
		line(150+tx,200+ty,275+tx,100+ty);
		line(275+tx,100+ty,400+tx,200+ty);
		rectangle(150+tx,200+ty,400+tx,400+ty);
		rectangle(255+tx,340+ty,295+tx,400+ty);
		rectangle(190+tx,240+ty,220+tx,270+ty);
		rectangle(330+tx,240+ty,360+tx,270+ty);
	}else if(choice == 2){
		printf("Before scaling");
		line(150,200,275,100);
		line(275,100,400,200);
		rectangle(150,200,400,400);
		rectangle(255,340,295,400);
		rectangle(190,240,220,270);
		rectangle(330,240,360,270);
		delay(2000);
		cleardevice();
		printf("Enter the scaling factor in x direction : ");
		float sx,sy;
		scanf("%f",&sx);
		printf("Enter the scaling factor in y direction : ");
		scanf("%f",&sy);
		printf("After Scaling");
		line(sx*150,sy*200,sx*275,sy*100);
		line(sx*275,sy*100,sx*400,sy*200);
		rectangle(sx*150,sy*200,sx*400,sy*400);
		rectangle(sx*255,sy*340,sx*295,sy*400);
		rectangle(sx*190,sy*240,sx*220,sy*270);
		rectangle(sx*330,sy*240,sx*360,sy*270);
	}else{

	}
	getch();
	closegraph();
	return 0;
}