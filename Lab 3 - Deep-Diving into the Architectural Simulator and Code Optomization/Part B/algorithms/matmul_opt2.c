#include "matmul_opt2.h"
#include <string.h>
#include <stdlib.h>

#define CACHE_LINE_SIZE 64
#define BLOCK_SIZE CACHE_LINE_SIZE/sizeof(unsigned long long int)

void matmul_opt2(unsigned long long int* mat_a, unsigned long long int* mat_b, unsigned long long int* mat_c, unsigned long long int matrix_size){
    // BLOCKING
    for (unsigned long long int i = 0; i < matrix_size; i += BLOCK_SIZE) {
         for (unsigned long long int j = 0; j < matrix_size; j += BLOCK_SIZE) {
             mat_c[i*matrix_size+j] = 0;
             for (unsigned long long int k = 0; k < matrix_size; k += BLOCK_SIZE) {
                 for (unsigned long long int x = i; x < ((i + BLOCK_SIZE) > matrix_size ? matrix_size : (i + BLOCK_SIZE)); x++) {
                     for (unsigned long long int y = j; y < ((j + BLOCK_SIZE) > matrix_size ? matrix_size : (j + BLOCK_SIZE)); y++) {
                         for (unsigned long long int z = k; z < ((k + BLOCK_SIZE) > matrix_size ? matrix_size : (k + BLOCK_SIZE)); z++) {

                             mat_c[x*matrix_size + y] += mat_a[z*matrix_size + y] * mat_b[x*matrix_size  + z];

                         }
                     } 
                 }
             }
         }
     }
}
