#include "erpc_matrix_multiply.h"
#include <stdio.h>

void erpcMatrixMultiply(Matrix matrix1, Matrix matrix2, Matrix result_matrix) {
    #if 1    
    int i, j, k;
    for (i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            for(k = 0; k < 5; k++) {
                //printf("%d %d %d\n",result_matrix[i][j], matrix1[i][k], matrix2[k][j]);
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            
        } 
    }
    #endif
}