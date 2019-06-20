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
#include "timing_macros.h"

void array2d_test(void)
{
    printf("Test::array2d_test\n");

    int rows = 2;
    int cols = 3;

    float a[2][3][1] = {
        {0, 1, 2},
        {3, 4, 5}
    };

    TIC();
    int rows_ = ARRAY2D_ROWS(a);
    TAC();

    printf("\trows: %d ?= %d", rows_, rows);
    if(rows_ == rows){
        printf(" ----> ok!\n");
    }else{
        printf(" ----> failed! :(\n");
    }
    TOC();

    TIC();
    int cols_ = ARRAY2D_COLS(a);
    TAC();

    printf("\tcols: %d ?= %d", cols_, cols);
    if(cols_ == cols){
        printf(" ----> ok!\n");
    }else{
        printf(" ----> failed! :(\n");
    }
    TOC();

    printf("---\n");
}

void arraynd_test(void)
{
    printf("Test::arraynd_test\n");

    int samples = 4;
    int rows = 2;
    int cols = 3;

    float a[4][2][3] = {
        // SAMPLE 0
        {{1, 2, 3}, 
        {4, 5, 6}},
        // SAMPLE 1
        {{1, 2, 3}, 
        {4, 5, 6}},
        // SAMPLE 2
        {{1, 2, 3}, 
        {4, 5, 6}},
        // SAMPLE 3
        {{1, 2, 3}, 
        {4, 5, 6}},
    };

    TIC();
    int rows_ = ARRAYND_ROWS(a);
    TAC();
    
    printf("\trows: %d ?= %d", rows_, rows);
    if(rows_ == rows){
        printf(" ----> ok!\n");
    }else{
        printf(" ----> failed! :(\n");
    }
    TOC();

    TIC();
    int cols_ = ARRAYND_COLS(a);
    TAC();

    printf("\tcols: %d ?= %d", cols_, cols);
    if(cols_ == cols){
        printf(" ----> ok!\n");
    }else{
        printf(" ----> failed! :(\n");
    }
    TOC();

    TIC();
    int samples_ = ARRAYND_SAMPLES(a);
    TAC();

    printf("\tsamples: %d ?= %d", samples_, samples);
    if(samples_ == samples){
        printf(" ----> ok!\n");
    }else{
        printf(" ----> failed! :(\n");
    }
    TOC();

    printf("---\n");
}

void arraynd_loop_reverse(void)
{
    printf("Test::arraynd_loop_reverse\n");

    float a[2][2][2] = {
        // Amostra 0
        {{0, 1}, 
         {2, 3}},
        // Amostra 1
        {{10, 11}, 
         {12, 13}},
    };
    
    int i, j, k;
    TIC();
    for(k = ARRAYND_SAMPLES(a); k--;){
        for(i = ARRAYND_ROWS(a); i--;){
            for(j = ARRAYND_COLS(a); j--;){
                printf("\ta[%d][%d][%d] = %f\n", k, i, j, a[k][i][j]);
            }
        }
    }
    TAC();
    TOC();

    printf("\n---\n");
}

void arraynd_loop(void)
{
    printf("Test::arraynd_loop\n");

    float a[2][2][2] = {
        // Amostra 0
        {{0, 1}, 
         {2, 3}},
        // Amostra 1
        {{10, 11}, 
         {12, 13}},
    };
    
    int i, j, k;
    TIC();
    for(k = 0; k < ARRAYND_SAMPLES(a); k++){
        for(i = 0; i < ARRAYND_ROWS(a); i++){
            for(j = 0; j < ARRAYND_COLS(a); j++){
                printf("\ta[%d][%d][%d] = %f\n", k, i, j, a[k][i][j]);
            }
        }
    }
    TAC();
    TOC();

    printf("\n---\n");
}

void array2d_sum_macro(void)
{
    printf("Test::array2d_sum_macro\n");

    float a[2][2] = {
        {0, 1}, 
        {2, 3}
    };

    float b[2][2] = {
        {10, 12}, 
        {16, 11}
    };

    float expected_result[2][2] = {
        {10, 13}, 
        {18, 14}
    };

    float result[ARRAY2D_ROWS(a)][ARRAY2D_COLS(a)];

    // PROCESS IN DIRECT ORDER
    printf("Direct Order\n");
    ARRAY2D_INDEX_INIT();
    TIC();
    ARRAY2D_SUM_DIRECT(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(i = 0; i < ARRAY2D_ROWS(a); i++){
        for(j = 0; j < ARRAY2D_COLS(a); j++){
            printf("\tresult[%d][%d] = %f ?= %f", i, j, 
                result[i][j],
                expected_result[i][j]);
            if(result[i][j] == expected_result[i][j]){
                printf(" ----> ok!\n");
            }else{
                printf(" ----> failed! :(\n");
            }
        }
    }
    TOC();

    // PROCESS IN REVERSE ORDER
    printf("Reverse Order\n");
    TIC();
    ARRAY2D_SUM_REVERSE(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(i = 0; i < ARRAY2D_ROWS(a); i++){
        for(j = 0; j < ARRAY2D_COLS(a); j++){
            printf("\tresult[%d][%d] = %f ?= %f", i, j, 
                result[i][j],
                expected_result[i][j]);
            if(result[i][j] == expected_result[i][j]){
                printf(" ----> ok!\n");
            }else{
                printf(" ----> failed! :(\n");
            }
        }
    }
    TOC();

    printf("---\n");
}

void arraynd_sum_macro(void)
{
    printf("Test::arraynd_sum_macro\n");

    float a[2][2][2] = {
        // Amostra 0
        {{0, 1}, 
         {2, 3}},
        // Amostra 1
        {{10, 11}, 
         {12, 13}},
    };

    float b[2][2][2] = {
        // Amostra 0
        {{0, 2}, 
         {6, 1}},
        // Amostra 1
        {{10, 12}, 
         {16, 11}},
    };

    float expected_result[2][2][2] = {
        // Amostra 0
        {{0, 3}, 
         {8, 4}},
        // Amostra 1
        {{20, 23}, 
         {28, 24}},
    };

    float result[ARRAYND_SAMPLES(a)][ARRAYND_ROWS(a)][ARRAYND_COLS(a)];

    // PROCESS IN DIRECT ORDER
    printf("Direct Order\n");
    ARRAYND_INDEX_INIT();
    TIC();
    ARRAYND_SUM_DIRECT(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(k = 0; k < ARRAYND_SAMPLES(a); k++){
        for(i = 0; i < ARRAYND_ROWS(a); i++){
            for(j = 0; j < ARRAYND_COLS(a); j++){
                printf("\tresult[%d][%d][%d] = %f ?= %f", k, i, j, 
                    result[k][i][j],
                    expected_result[k][i][j]);
                if(result[k][i][j] == expected_result[k][i][j]){
                    printf(" ----> ok!\n");
                }else{
                    printf(" ----> failed! :(\n");
                }
            }
        }
    }
    TOC();

    // PROCESS IN REVERSE ORDER
    printf("Reverse Order\n");
    TIC();
    ARRAYND_SUM_REVERSE(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(k = 0; k < ARRAYND_SAMPLES(a); k++){
        for(i = 0; i < ARRAYND_ROWS(a); i++){
            for(j = 0; j < ARRAYND_COLS(a); j++){
                printf("\tresult[%d][%d][%d] = %f ?= %f", k, i, j, 
                    result[k][i][j],
                    expected_result[k][i][j]);
                if(result[k][i][j] == expected_result[k][i][j]){
                    printf(" ----> ok!\n");
                }else{
                    printf(" ----> failed! :(\n");
                }
            }
        }
    }
    TOC();

    printf("---\n");
}

void array2d_gain_macro(void)
{
    printf("Test::array2d_gain_macro\n");

    float a[2][3] = {
        {1, 2, 3}, 
        {4, 5, 6}
    };

    float b = 2;

    float expected_result[2][3] = {
        {2, 4, 6}, 
        {8, 10, 12}
    };

    float result[ARRAY2D_ROWS(a)][ARRAY2D_COLS(a)];

    // NORMAL ORDER
    printf("Direct Order\n");
    ARRAY2D_INDEX_INIT();
    TIC();
    ARRAY2D_GAIN_DIRECT(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(i = 0; i < ARRAY2D_ROWS(result); i++){
        for(j = 0; j < ARRAY2D_COLS(result); j++){
            printf("\tresult[%d][%d] = %f ?= %f", i, j, 
                result[i][j],
                expected_result[i][j]);
            if(result[i][j] == expected_result[i][j]){
                printf(" ----> ok!\n");
            }else{
                printf(" ----> failed! :(\n");
            }
        }
    }
    TOC();

    printf("---\n");

    // REVERSE ORDER
    printf("Reverse Order\n");
    TIC();
    ARRAY2D_GAIN_REVERSE(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(i = 0; i < ARRAY2D_ROWS(result); i++){
        for(j = 0; j < ARRAY2D_COLS(result); j++){
            printf("\tresult[%d][%d] = %f ?= %f", i, j, 
                result[i][j],
                expected_result[i][j]);
            if(result[i][j] == expected_result[i][j]){
                printf(" ----> ok!\n");
            }else{
                printf(" ----> failed! :(\n");
            }
        }
    }
    TOC();

    printf("---\n");

}


void arraynd_gain_macro(void)
{
    printf("Test::arraynd_gain_macro\n");

    float a[4][2][3] = {
        // SAMPLE 0
        {{1, 2, 3}, 
         {4, 5, 6}},
        // SAMPLE 1
        {{1, 2, 3}, 
         {4, 5, 6}},
        // SAMPLE 2
        {{1, 2, 3}, 
         {4, 5, 6}},
        // SAMPLE 3
        {{1, 2, 3}, 
         {4, 5, 6}}
    };

    float b = 2;

    float expected_result[4][2][3] = {
        // Amostra 0
        {{2, 4, 6}, 
         {8, 10, 12}},
        // Amostra 1
        {{2, 4, 6}, 
         {8, 10, 12}},
        // Amostra 2
        {{2, 4, 6}, 
         {8, 10, 12}},
        // Amostra 3
        {{2, 4, 6}, 
         {8, 10, 12}},
    };

    float result[ARRAYND_SAMPLES(a)][ARRAYND_ROWS(a)][ARRAYND_COLS(a)];

    // NORMAL ORDER
    printf("Direct Order\n");
    ARRAYND_INDEX_INIT();
    TIC();
    ARRAYND_GAIN_DIRECT(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(k = 0; k < ARRAYND_SAMPLES(result); k++){
        for(i = 0; i < ARRAYND_ROWS(result); i++){
            for(j = 0; j < ARRAYND_COLS(result); j++){
                printf("\tresult[%d][%d][%d] = %f ?= %f", k, i, j, 
                    result[k][i][j],
                    expected_result[k][i][j]);
                if(result[k][i][j] == expected_result[k][i][j]){
                    printf(" ----> ok!\n");
                }else{
                    printf(" ----> failed! :(\n");
                }
            }
        }
    }
    TOC();

    printf("---\n");

    // REVERSE ORDER
    printf("Reverse Order\n");
    TIC();
    ARRAYND_GAIN_REVERSE(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(k = 0; k < ARRAYND_SAMPLES(result); k++){
        for(i = 0; i < ARRAYND_ROWS(result); i++){
            for(j = 0; j < ARRAYND_COLS(result); j++){
                printf("\tresult[%d][%d][%d] = %f ?= %f", k, i, j, 
                    result[k][i][j],
                    expected_result[k][i][j]);
                if(result[k][i][j] == expected_result[k][i][j]){
                    printf(" ----> ok!\n");
                }else{
                    printf(" ----> failed! :(\n");
                }
            }
        }
    }
    TOC();

    printf("---\n");

}

void array2d_mul_macro(void)
{
    printf("Test::array2d_mul_macro\n");

    float a[2][3] = {
        // Amostra 0
        {1, 2, 3}, 
        {4, 5, 6}
    };

    float b[3][2] = {
        // Amostra 0
        {7, 8}, 
        {9, 10},
        {11, 12}
    };

    float expected_result[2][2] = {
        // Amostra 0
        {58, 64}, 
        {139, 154}
    };

    float result[ARRAY2D_ROWS(a)][ARRAY2D_COLS(b)];

    // NORMAL ORDER
    printf("Direct Order\n");
    ARRAY2D_INDEX_INIT();
    TIC();
    ARRAY2D_MUL_DIRECT(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(i = 0; i < ARRAY2D_ROWS(result); i++){
        for(j = 0; j < ARRAY2D_COLS(result); j++){
            printf("\tresult[%d][%d] = %f ?= %f", i, j, 
                result[i][j],
                expected_result[i][j]);
            if(result[i][j] == expected_result[i][j]){
                printf(" ----> ok!\n");
            }else{
                printf(" ----> failed! :(\n");
            }
        }
    }
    TOC();

    printf("---\n");

    // REVERSE ORDER
    printf("Reverse Order\n");
    TIC();
    ARRAY2D_MUL_REVERSE(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(i = 0; i < ARRAY2D_ROWS(result); i++){
        for(j = 0; j < ARRAY2D_COLS(result); j++){
            printf("\tresult[%d][%d] = %f ?= %f", i, j, 
                result[i][j],
                expected_result[i][j]);
            if(result[i][j] == expected_result[i][j]){
                printf(" ----> ok!\n");
            }else{
                printf(" ----> failed! :(\n");
            }
        }
    }
    TOC();

    printf("---\n");

}

void arraynd_mul_macro(void)
{
    printf("Test::arraynd_mul_macro\n");

    float a[4][2][3] = {
        // SAMPLE 0
        {{1, 2, 3}, 
         {4, 5, 6}},
        // SAMPLE 1
        {{1, 2, 3}, 
         {4, 5, 6}},
        // SAMPLE 2
        {{1, 2, 3}, 
         {4, 5, 6}},
        // SAMPLE 3
        {{1, 2, 3}, 
         {4, 5, 6}}
    };

    float b[4][3][2] = {
        // Amostra 0
        {{7, 8}, 
         {9, 10},
         {11, 12}},
        // Amostra 1
        {{7, 8}, 
         {9, 10},
         {11, 12}},
        // Amostra 2
        {{7, 8}, 
         {9, 10},
         {11, 12}},
        // Amostra 3
        {{7, 8}, 
         {9, 10},
         {11, 12}}
    };

    float expected_result[4][2][2] = {
        // Amostra 0
        {{58, 64}, 
         {139, 154}},
        // Amostra 1
        {{58, 64}, 
         {139, 154}},
        // Amostra 2
        {{58, 64}, 
         {139, 154}},
        // Amostra 3
        {{58, 64}, 
         {139, 154}}
    };

    float result[ARRAYND_SAMPLES(a)][ARRAYND_ROWS(a)][ARRAYND_COLS(b)];

    // NORMAL ORDER
    printf("Direct Order\n");
    ARRAYND_INDEX_INIT();
    TIC();
    ARRAYND_MUL_DIRECT(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(k = 0; k < ARRAYND_SAMPLES(result); k++){
        for(i = 0; i < ARRAYND_ROWS(result); i++){
            for(j = 0; j < ARRAYND_COLS(result); j++){
                printf("\tresult[%d][%d][%d] = %f ?= %f", k, i, j, 
                    result[k][i][j],
                    expected_result[k][i][j]);
                if(result[k][i][j] == expected_result[k][i][j]){
                    printf(" ----> ok!\n");
                }else{
                    printf(" ----> failed! :(\n");
                }
            }
        }
    }
    TOC();

    printf("---\n");

    // REVERSE ORDER
    printf("Reverse Order\n");
    TIC();
    ARRAYND_MUL_REVERSE(a, b, result);
    TAC();

    // PRINT AND ASSERT
    for(k = 0; k < ARRAYND_SAMPLES(result); k++){
        for(i = 0; i < ARRAYND_ROWS(result); i++){
            for(j = 0; j < ARRAYND_COLS(result); j++){
                printf("\tresult[%d][%d][%d] = %f ?= %f", k, i, j, 
                    result[k][i][j],
                    expected_result[k][i][j]);
                if(result[k][i][j] == expected_result[k][i][j]){
                    printf(" ----> ok!\n");
                }else{
                    printf(" ----> failed! :(\n");
                }
            }
        }
    }
    TOC();

    printf("---\n");

}


int main(void)
{
    array2d_test();
    arraynd_test();

    arraynd_loop();
    arraynd_loop_reverse();

    array2d_sum_macro();
    arraynd_sum_macro();

    array2d_gain_macro();
    arraynd_gain_macro();

    array2d_mul_macro();
    arraynd_mul_macro();

    return 0;
}