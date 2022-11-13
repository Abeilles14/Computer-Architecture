#include "matmul_opt1.h"
#include <string.h>
#include <stdlib.h>

// #define VECTOR_SIZE 32

void matmul_opt1(unsigned long long int* mat_a, unsigned long long int* mat_b, unsigned long long int* mat_c, unsigned long long int matrix_size){
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

    // REORDER
    // for(unsigned long long int j=0; j<matrix_size; j++){
    //     for(unsigned long long int k=0; k<matrix_size; k++){
    //         for(unsigned long long int i=0; i<matrix_size; i++){
    //             mat_c[j*matrix_size + i] += mat_a[k*matrix_size + i] * mat_b[j*matrix_size + k];
    //         }
    //     }
    // }

    // Transpose
    // unsigned long long int new_mat_b [matrix_size * matrix_size];

    // for (int i=0; i < matrix_size; i++) {
    //     for (int j=0; j < matrix_size; j++) {
    //         new_mat_b[j * matrix_size + i] = mat_b[i * matrix_size + j];
    //     }
    // }
    
    // // reorder
    // for (int j = 0; j < matrix_size; j++) {
    //     for (int k = 0; k < matrix_size; k++) {
    //         for (int i = 0; i < matrix_size; i++) {
    //             mat_c[j*matrix_size + i] += mat_a[k*matrix_size + i] * mat_b[j*matrix_size + k];
    //         }
    //     }
    // }
}

// Vectorize
// a vector of 256 / 32 = 8 floats
// typedef float vec __attribute__ (( vector_size(32) ));

// // a helper function that allocates n vectors and initializes them with zeros
// vec* alloc(int n) {
//     vec* ptr = (vec*) aligned_alloc(32, 32 * n);
//     memset(ptr, 0, 32 * n);
//     return ptr;
// }

// void matmul_opt1(unsigned long long int* mat_a, unsigned long long int* mat_b, unsigned long long int* mat_c, unsigned long long int matrix_size){
//     int nB = (matrix_size + 7) / 8; // number of 8-element vectors in a row (rounded up)

//     vec *mat_a_new = alloc(matrix_size * nB);
//     vec *mat_b_new = alloc(matrix_size * nB);

//     // move both matrices to the aligned region
//     for (int i = 0; i < matrix_size; i++) {
//         for (int j = 0; j < matrix_size; j++) {
//             mat_a_new[i * nB + j / 8][j % 8] = mat_a[i * matrix_size + j];
//             mat_b_new[i * nB + j / 8][j % 8] = mat_b[j * matrix_size + i]; // <- b is still transposed
//         }
//     }

//     for (int i = 0; i < matrix_size; i++) {
//         for (int j = 0; j < matrix_size; j++) {
//             vec s = {}; // initialize the accumulator with zeros

//             // vertical summation
//             for (int k = 0; k < nB; k++)
//                 s += mat_a_new[i * nB + k] * mat_b_new[j * nB + k];
            
//             // horizontal summation
//             for (int k = 0; k < 8; k++)
//                 mat_c[i * matrix_size + j] += s[k];
//         }
//     }

//     free(mat_a_new);
//     free(mat_b_new);
// }

// Transpose
// void matmul_opt1(unsigned long long int* mat_a, unsigned long long int* mat_b, unsigned long long int* mat_c, unsigned long long int matrix_size){
//     unsigned long long int new_mat_b [matrix_size * matrix_size];

//     for (int i=0; i < matrix_size; i++) {
//         for (int j=0; j < matrix_size; j++) {
//             new_mat_b[j * matrix_size + i] = mat_b[i * matrix_size + j];
//         }
//     }
    
//     for (int i = 0; i < matrix_size; i++) {
//         for (int j = 0; j < matrix_size; j++) {
//             for (int k = 0; k < matrix_size; k++) {
//                 mat_c[j*matrix_size + i] += mat_a[k*matrix_size + i] * mat_b[j*matrix_size + k];
//             }
//         }
//     }
// }
