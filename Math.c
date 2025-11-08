#ifndef MATH_C
#define MATH_C

#include<ncurses.h>

void productVec4Mat4(float* vector, float* matrix, float* dest){
    for(int i = 0; i < 4; i++){
		dest[i] = 0;
    }	
    for (int i = 0; i < 16; i++) {
        int c = i%4, r = i/4;
        dest[r] += vector[c] * matrix[r * 4 + c];
    }
}

void vec4TimesScalar(float* vector, float scalar){
	for(int i = 0; i < 4; ++i){
		vector[i] *= scalar;
	}
}

void vec4Plus(float* vector, float add){
	for(int i = 0; i < 4; ++i){
		vector[i] += add;
	}
}

void genRotationMatrix(float* dest, float* axis){
	for(int i = 0; i < 16; ++i){
		dest[i] = (i%4 == i/4) ? 1 : 0;
	}	
}

void vec4Copy(float* from, float* dest){
	for(int i = 0; i < 4; ++i){
		dest[i] = from[i];
	}
}

void debugMat4(float* debug){
	// 0  1  2  3
	// 4  5  6  7
	// 8  9  10 11
	// 12 13 14 15

	printw("\nMat:\n");
	for(int i = 0; i < 16; ++i){
		int c = i%4; int r = i/4;
		printw("%f ",debug[i]);
		if(c == 3){
			printw("\n");
		}
	}
}

#endif //MATH_C
