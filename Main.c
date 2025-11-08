//#include <stdio.h>
// #include <GLFW/glfw3.h>

#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include <stdio.h>
#include "Math.c"
#include "Utils.c"

int main(){
	//printf("olá mundo");
	
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();

	printw("Ola mundo :)\n");
	
	//for(int i = 0; i < 128; i++){
		//int ch = getch();
		//move(15+10*sin(i*0.1),i);
		//addch(ch | A_UNDERLINE);
	//}
	
	float** cube = malloc(8*sizeof(float*));
	for(int i = 0; i < 8; ++i){
		cube[i] = malloc(4*sizeof(float));
	}
	
	int c = 0; // em tese isso gera um cubo
	for(int x = -1; x < 2; x+=2){
		for(int y = -1; y < 2; y+=2){
			for(int z = -1; z < 2; z+=2){
				cube[c][0] = (float) x;
				cube[c][1] = (float) y;
				cube[c][2] = (float) z;
				cube[c][3] = 0;
				printw("%d %d %d [%d]\n",x,y,z,c);
				c++; // :o
			}
		}
	}
	printw("c=%d\n",c);
	
	float* rotationMatrix = malloc(16*sizeof(float));
	genRotationMatrix(rotationMatrix,0);
	//debugMat4(rotationMatrix);
	
	if(false){
		endwin();
		debugMat4(rotationMatrix);
		printf("\nCUBE:\n");
		for(int i = 0; i < 8; ++i){
			printf("%f %f %f\n",cube[i][0],cube[i][1],cube[i][2]);
		}
		return 0;
	}

	printf("\nue");

	for(int i = 0; i < 16; ++i){
		renderModel(cube,8,0,0,rotationMatrix);
		getch();
	}
	//int** lines = malloc(0);

	endwin();
	
	return 0;
}
