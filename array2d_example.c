/* 
 * This file is part of the C Array Macros distribution (https://github.com/joaoantoniocardoso/c_array_macros).
 * Copyright (c) 2019 João Antônio Cardoso.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include "array_macros.h"

// Selects REVERSE or DIRECT order for processing loops:
#define SUM ARRAY2D_SUM_REVERSE
#define SUB ARRAY2D_SUB_REVERSE
#define MUL ARRAY2D_MUL_REVERSE
#define GAIN ARRAY2D_GAIN_REVERSE
#define COPY ARRAY2D_COPY_REVERSE
#define ZERO ARRAY2D_ZERO_REVERSE
#define INT ARRAY2D_GAINSUM_REVERSE
#define MULSUM ARRAY2D_MULSUM_REVERSE

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

float E[2][2];
float F[2][2];

float d = 2.12;

int main(void)
{
    // Initialize local indexes (i,j,h) for array2d macros
    ARRAY2D_INDEX_INIT();

    // Temporary arrays
    float T1[2][2], T2[2][2];
    
    // E = A*B + C*d
    MUL(A, B, T1);          // T1 = A*B :
    GAIN(C, d, T2);         // T2 = C*d :
    SUM(T1, T2, E);         // E = T1 * T2 :

    // F = E = A*B + C*d
    COPY(E, F);
    
    // T2 = 0
    ZERO(F);
    // F -= E = 0
    SUB(F, E, F);

    // F = A*B + C*d
    MUL(A, B, F);           // F = A*B
    INT(C, d, F);           // F += C*d

    // F = A*B + C*d
    GAIN(C, d, F);           // F = C*d
    MULSUM(A, B, F);         // F += A*B

    // PRINT
    printf("RESULT:\n");
    for(i = 0; i < ARRAY2D_ROWS(E); i++){
        for(j = 0; j < ARRAY2D_COLS(E); j++){
            printf("\tE[%d][%d] = F[%d][%d] = %f = %f\n", 
                i, j, i, j, 
                E[i][j],
                F[i][j]);
        }
    }

    return 0;
}