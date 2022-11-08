#include "matmul_basic.h"

void matmul_basic(unsigned long long int* mat_a, unsigned long long int* mat_b, unsigned long long int* mat_c, unsigned long long int matrix_size){
    for(unsigned long long int i=0; i<matrix_size; i++){
        for(unsigned long long int j=0; j<matrix_size; j++){
            for(unsigned long long int k=0; k<matrix_size; k++){
                mat_c[j*matrix_size + i] += mat_a[k*matrix_size + i] * mat_b[j*matrix_size + k];
            }
        }
    }
}