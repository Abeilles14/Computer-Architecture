#include "matmul_opt2.h"

#define CACHE_LINE_SIZE 64

void matmul_opt2(unsigned long long int* mat_a, unsigned long long int* mat_b, unsigned long long int* mat_c, unsigned long long int matrix_size){
    const int block_size = CACHE_LINE_SIZE / sizeof(unsigned long long int);
    
    for(int jj=0; jj < matrix_size; jj += block_size){
        for(int kk=0; kk < matrix_size; kk += block_size){
                for(int i=0; i < matrix_size; i++){
                        for(int j=jj; j < ((jj + block_size) > matrix_size ? matrix_size : (jj + block_size)); j++){
                                unsigned long long int temp = 0;
                                
                                for(int k=kk; k < ((kk + block_size) > matrix_size ? matrix_size : (kk + block_size)); k++){
                                        temp += mat_a[i * matrix_size + k] * mat_b[k*matrix_size + j];
                                }
                                mat_c[i * matrix_size + j] += temp;
                        }
                }
        }
}
}