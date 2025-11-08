#ifndef UTILS_C
#define UTILS_C

#include<stdlib.h>
#include"Math.c"

void renderChar(int x, int y, char c){
	printf(">> %d %d",x,y);
	move(1,1);
	//move(y,x);
	//addch(c);
}

void render3D(float x, float y, float z, float* matrix, float scalarEnd, float addEnd){
	float* vec3 = malloc(4*sizeof(float));
	float* dest = malloc(4*sizeof(float));

	vec3[0] = x; vec3[1] = y; vec3[2] = z; vec3[3] = 0;
	//printf("espaço %f %f %f\n",x,y,z);

	productVec4Mat4(vec3,matrix,dest);
	
	//printf("matriciado %f %f %f",dest[0],dest[1],dest[2]);

	vec4TimesScalar(dest,scalarEnd);
	vec4PlusScalar(dest,addEnd);
	
	//printf("renderAt %f %f",dest[0],dest[1]);
	renderChar((int)dest[0], (int)dest[1], 'O');
	//printf("Renderizando em %f f\n",dest[0],dest[1]);

	free(dest);
	free(vec3);
}

void renderModel(float** vertices, int vertexNumber, int** indices, int indexNumber, float* matrix){
	for(int i = 0; i < vertexNumber; i++){
		render3D(vertices[i][0],vertices[i][1],vertices[i][2],matrix, 10, 4);
	}
}

#endif //UTILS_C
