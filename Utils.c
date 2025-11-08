#ifndef UTILS_C
#define UTILS_C

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include"Math.c"

#define FULL_CHAR 'O'
#define DEBUG_DRAW false

int C = 0;

void renderChar(int x, int y, char c){
	move(y,2*x);
	addch(c);
	if(DEBUG_DRAW){
		move(0,30);
		printw("DRAWCALL_%4d[%3d %3d]",C,x,y); refresh();
		usleep(1000*10);
		C++;
	}
}

void renderLine(int bx, int by, int ex, int ey, char c){
	int dx = (ex - bx);
	int dy = (ey - by);

	if(bx == ex && by == ey){
		renderChar(bx,by,c);
		return;
	}
	
	if(DEBUG_DRAW){
		move(2, 2);
		printw("%d %d -> %d %d\ndx=%d\ndy=%d\n\n",bx,by,ex,ey,dx,dy);
	}
	for(int x = bx; dx != 0 && x <= ex; ++x){
		float d = dy/(float)dx;
		renderChar(x,(int)(by+(x-bx)*d),c);
	}
	for(int y = by; dy != 0 && y < ey; ++y){
		float d = dx/(float)dy;
		renderChar((int)(bx+(y-by)*d),y,c);
	}
	if(DEBUG_DRAW){
		refresh();
		usleep(1000 * 100);
	};
	
}

void render3DLine(float bx, float by, float bz, float ex, float ey, float ez, float* matrix, float scalar, float add){
	
	float* beg = malloc(4*sizeof(float));
	float* end = malloc(4*sizeof(float));
	float* buffer = malloc(4*sizeof(float));

	beg[0] = bx; beg[1] = by; beg[2] = bz; beg[3] = 0;
	end[0] = ex; end[1] = ey; end[2] = ez; end[3] = 0;

	productVec4Mat4(beg,matrix,buffer);
	vec4Copy(buffer,beg);
	productVec4Mat4(end,matrix,buffer);
	vec4Copy(buffer,end);

	vec4TimesScalar(beg, scalar);
	vec4TimesScalar(end, scalar);

	vec4Plus(beg,add);
	vec4Plus(end,add);

	renderLine((int)beg[0], (int)beg[1],  (int)end[0], (int)end[1], FULL_CHAR);

	free(beg); free(end); free(buffer);
}

void render3D(float x, float y, float z, float* matrix, float scalar, float add){
	float* vec3 = malloc(4*sizeof(float));
	float* dest = malloc(4*sizeof(float));

	vec3[0] = x; vec3[1] = y; vec3[2] = z; vec3[3] = 0;

	productVec4Mat4(vec3,matrix,dest);
	
	vec4TimesScalar(dest,scalar);
	vec4Plus(dest,add);
	
	renderChar((int)dest[0], (int)dest[1], 'A');

	free(dest);
	free(vec3);
}

void renderModel(float** vertices, int vertexNumber, int** indices, int indexNumber, float* matrix){
	for(int i = 0; i < indexNumber; ++i){
		float* v1 = vertices[indices[i][0]];
		float* v2 = vertices[indices[i][1]];
		render3DLine(v1[0], v1[1], v1[2], v2[0], v2[1], v2[2], matrix, 10,20);
		if(DEBUG_DRAW){
			move(6,0);
			printw("(%f %f %f)->(%f %f %f)\n",v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
		}
	}

	for(int i = 0; i < vertexNumber; i++){
		render3D(vertices[i][0],vertices[i][1],vertices[i][2],matrix, 10, 20);
	}
}

#endif //UTILS_C
