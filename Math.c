#ifndef MATH_C
#define MATH_C

void vec4Mat4(float* vector, float* matrix, float* dest){
    for (int i = 0; i < 16; i++) {
        int c = i%4, r = i/4;
        dest[r] += vector[c] * matrix[r * 4 + c];
    }
}

#endif //MATH_C