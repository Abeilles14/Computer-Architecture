#include "matmul_opt2.h"

void matmul_opt2(unsigned long long int* mat_a, unsigned long long int* mat_b, unsigned long long int* mat_c, unsigned long long int matrix_size){
    // TRANSPOSE
    unsigned long long int new_mat_b [matrix_size * matrix_size];

    for (int i=0; i < matrix_size; i++) {
        for (int j=0; j < matrix_size; j++) {
            new_mat_b[j * matrix_size + i] = mat_b[i * matrix_size + j];
        }
    }
    
    // REORDER
    for (int j = 0; j < matrix_size; j++) {
        for (int k = 0; k < matrix_size; k++) {
            for (int i = 0; i < matrix_size; i++) {
                mat_c[j*matrix_size + i] += mat_a[k*matrix_size + i] * mat_b[j*matrix_size + k];
            }
        }
    }
}
