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
	
	for(int i = 0; i < 8; ++i){
		cube[i] = malloc(4*sizeof(float));
	}

	int indexN = 8*7;
	int** indices = malloc(indexN*sizeof(int*));
	for(int i = 0; i < indexN; ++i){
		indices[i] = malloc(2 * sizeof(int));
		indices[i][0] = 0;
		indices[i][1] = 0;
	}
	
	int c = 0; // em tese isso gera um cubo
	for(int x = -1; x < 2; x+=2){
		for(int y = -1; y < 2; y+=2){
			for(int z = -1; z < 2; z+=2){
				cube[c][0] = (float) x;
				cube[c][1] = (float) y;
				cube[c][2] = (float) z;
				cube[c][3] = 0;
				printw("cube[%d] = (%d %d %d)\n",c,x,y,z);
				c++; // :o
			}
		}
	}

	move(0,0);

	c = 0;
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(i == j){continue;}
			int deg = 
			(cube[i][0] == cube[j][0]) +
			(cube[i][1] == cube[j][1]) +
			(cube[i][2] == cube[j][2]);
			// printw("deg=%d\n",deg);
			if(deg == 2){
				printw("edge [%d -> %d]: (%.3f %.3f %.3f) -> (%.3f %.3f %.3f)\n", i,j,
					cube[i][0],cube[i][1],cube[i][2],
					cube[j][0],cube[j][1],cube[j][2]);
				indices[c][0] = i;
				indices[c][1] = j;
				c++;
			}
		}
	}

	indexN = c;

	// int the[] = {
	// 	0, 1, 2,  1, 3, 4,  5, 6, 7,
    //     8, 9, 10,  2, 4, 8,  11, 8, 6,
    //     0, 12, 1,  1, 13, 3,  5, 11, 6,
    //     8, 4, 9,  2, 1, 4,  11, 2, 8
	// };

	// getch();

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

	//  0  1  2  3
	//  4  5  6  7
	//  8  9 10 11
	// 12 13 14 15

	float rotation[] = {0,0,0,0};

	for(int i = 0; i < 16*1200; ++i){
		rotation[0] += 0.1F;
		rotation[1] += 0.12F;
		// rotation[2] += 0.1F;
		float* rotationMatrix = malloc(16*sizeof(float));
		genRotationMatrix(rotationMatrix,rotation);

		// debugMat4(rotationMatrix);
		// getch();

		clear();
		printw("F %d",i);
		renderModel(cube,8,indices,indexN,rotationMatrix);
		// getch();
		refresh();
		if(DEBUG_DRAW){
			getch();
		} else {
			usleep(10000*10);
		}
	}

	endwin();
	
	return 0;
}
