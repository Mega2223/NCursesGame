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
	
	// if(true){
	// 	renderLine(10,10,30,30,'C');
	// 	renderLine(10,10,30,10,'C');
	// 	return 0;
	// }

	//for(int i = 0; i < 128; i++){
		//int ch = getch();
		//move(15+10*sin(i*0.1),i);
		//addch(ch | A_UNDERLINE);
	//}
	
	float** cube = malloc(8*sizeof(float*));
	int** indices = malloc((8*7)*sizeof(int*));

	for(int i = 0; i < 8; ++i){
		cube[i] = malloc(4*sizeof(float));
	}
	for(int i = 0; i < 8*7; ++i){
		indices[i] = malloc(2*sizeof(int));
		indices[i][0] = 0; indices[i][1] = 1;
	}
	
	int c = 0; // em tese isso gera um cubo
	for(int x = -1; x < 2; x+=2){
		for(int y = -1; y < 2; y+=2){
			for(int z = -1; z < 2; z+=2){
				cube[c][0] = (float) x;
				cube[c][1] = (float) y;
				cube[c][2] = (float) z;
				cube[c][3] = 0;
				// printw("%d %d %d [%d]\n",x,y,z,c);
				c++; // :o
			}
		}
	}
	//printw("c=%d\n",c);
	c = 0;
	for(int v1 = 0; v1 < 8;v1++){
		for(int v2 = 0; v2 < 8;v2++){
			if(v1 == v2){continue;}
			indices[c][0] = v1;
			indices[c][1] = v2;
			c++;
		}
	}

	//debugMat4(rotationMatrix);
	
	// if(false){
	// 	endwin();
	// 	debugMat4(rotationMatrix);
	// 	printf("\nCUBE:\n");
	// 	for(int i = 0; i < 8; ++i){
	// 		printf("%f %f %f\n",cube[i][0],cube[i][1],cube[i][2]);
	// 	}
	// 	return 0;
	// }

	// printf("\nue");

	for(int i = 0; i < 16; ++i){

		float* rotationMatrix = malloc(16*sizeof(float));
		genRotationMatrix(rotationMatrix,0);

		// 0  1  2  3
		// 4  5  6  7
		// 8  9  10 11
		// 12 13 14 15
		rotationMatrix[8] = .3;
		rotationMatrix[9] = .3;


		move(0,0);
		printw("F %d",i);
		refresh(); 
		renderModel(cube,8,indices,8*7,rotationMatrix);
		// getch();
		clear();
	}

	endwin();
	
	return 0;
}
