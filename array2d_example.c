#include <stdio.h>
#include "array_macros.h"

// Selects REVERSE or DIRECT order for processing loops:
#define SUM ARRAY2D_SUM_REVERSE
#define MUL ARRAY2D_MUL_REVERSE
#define GAIN ARRAY2D_GAIN_REVERSE

float A[2][3] = {
    {0, 1, 2},
    {3, 4, 5}
};

float B[3][2] = {
    {0, 1},
    {2, 3},
    {4, 5}
};

float C[2][2] = {
    {10, 12}, 
    {16, 11}
};

float d = 2;

float E[2][2];

int main(void)
{
    // Initialize local indexes (i,j,h) for array2d macros
    ARRAY2D_INDEX_INIT();

    // Temporary arrays
    float T1[2][2], T2[2][2];

    // T1 = A*B :
    MUL(A, B, T1);

    // T2 = C*d :
    GAIN(C, d, T2);

    // E = A*B + C*d = T1 * T2 :
    SUM(T1, T2, E);

    // PRINT
    printf("RESULT:\n");
    for(i = 0; i < ARRAY2D_ROWS(E); i++){
        for(j = 0; j < ARRAY2D_COLS(E); j++){
            printf("\tE[%d][%d] = %f\n", i, j, 
                E[i][j]);
        }
    }

    return 0;
}