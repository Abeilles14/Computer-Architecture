#include "matmul_opt1.h"
#include <string.h>

// Transposition
void matmul_opt1(unsigned long long int* mat_a, unsigned long long int* mat_b, unsigned long long int* mat_c, unsigned long long int matrix_size){
    unsigned long long int new_mat_b [matrix_size * matrix_size];

    for (int i=0; i < matrix_size; i++) {
        for (int j=0; j < matrix_size; j++) {
            new_mat_b[i * matrix_size + j] = mat_b[j * matrix_size + i];
        }
    }
    
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            for (int k = 0; k < matrix_size; k++) {
                mat_c[i * matrix_size + j] += mat_a[i * matrix_size + k] * new_mat_b[j * matrix_size + k];
            }
        }
    }
}
