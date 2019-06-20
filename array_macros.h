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

#ifndef _ARRAY_MACROS_H_
#define _ARRAY_MACROS_H_

/*
* ARRAY2D aqui são MATRIZES:
*   x[k][i][j], onde:
*       i é a linha
*       j é a coluna
*
* ARRAYND aqui são MATRIZES NO TEMPO:
*   Interpretar como um vetor(tempo) de matrizes(x,y):
*       x[k][i][j], onde:
*       i é a linha
*       j é a coluna
*       k é a amostra no tempo
*/

// MACROS FOR ARRAYS:
#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))
#define ARRAY2D_ROWS(a) ARRAYSIZE(a)
#define ARRAY2D_COLS(a) ARRAYSIZE(a[0])
#define ARRAY2D_INDEX_INIT() int i, j, h
#define ARRAY2D_SUM_DIRECT(a, b, c) ({              \
    for(i = 0; i < ARRAY2D_ROWS(a); i++){           \
        for(j = 0; j < ARRAY2D_COLS(a); j++){       \
            c[i][j] = a[i][j] + b[i][j];            \
}   }   })
#define ARRAY2D_SUM_REVERSE(a, b, c) ({             \
    for(i = ARRAY2D_ROWS(a); i--;){                 \
        for(j = ARRAY2D_COLS(a); j--;){             \
            c[i][j] = a[i][j] + b[i][j];            \
}   }   })
#define ARRAY2D_GAIN_DIRECT(a, b, c) ({             \
    for(i = 0; i < ARRAY2D_ROWS(a); i++){           \
        for(j = 0; j < ARRAY2D_COLS(a); j++){       \
            c[i][j] = a[i][j] * b;                  \
}   }   })
#define ARRAY2D_GAIN_REVERSE(a, b, c) ({            \
    for(i = ARRAY2D_ROWS(a); i--;){                 \
        for(j = ARRAY2D_COLS(a); j--;){             \
            c[i][j] = a[i][j] * b;                  \
}   }   })
#define ARRAY2D_MUL_DIRECT(a, b, c) ({              \
    for(i = 0; i < ARRAY2D_ROWS(a); i++){           \
        for(j = 0; j < ARRAY2D_COLS(b); j++){       \
            c[i][j] = 0;                            \
            for(h = 0; h <= ARRAY2D_ROWS(a); h++){  \
                c[i][j] += a[i][h] * b[h][j];       \
}   }   }   })
#define ARRAY2D_MUL_REVERSE(a, b, c)({              \
    for(i = ARRAY2D_ROWS(a); i--;){                 \
        for(j = ARRAY2D_COLS(b); j--;){             \
            c[i][j] = 0;                            \
            for(h = ARRAY2D_ROWS(b); h--;){         \
                c[i][j] += a[i][h] * b[h][j];       \
}   }   }   })

// MACROS FOR VECTOR OF SAMPLES OF ARRAYS:
#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))
#define ARRAYND_SAMPLES(a) ARRAYSIZE(a)
#define ARRAYND_ROWS(a) ARRAYSIZE(a[0])
#define ARRAYND_COLS(a) ARRAYSIZE(a[0][0])
#define ARRAYND_INDEX_INIT() int i, j, k, h
#define ARRAYND_SUM_DIRECT(a, b, c) ({              \
    for(k = 0; k < ARRAYND_SAMPLES(a); k++){        \
        for(i = 0; i < ARRAYND_ROWS(a); i++){       \
            for(j = 0; j < ARRAYND_COLS(a); j++){   \
                c[k][i][j] =                        \
                    a[k][i][j] + b[k][i][j];        \
}   }   }   })
#define ARRAYND_SUM_REVERSE(a, b, c) ({             \
    for(k = ARRAYND_SAMPLES(a); k--;){              \
        for(i = ARRAYND_ROWS(a); i--;){             \
            for(j = ARRAYND_COLS(a); j--;){         \
                result[k][i][j] =                   \
                    a[k][i][j] + b[k][i][j];        \
}   }   }   })
#define ARRAYND_GAIN_DIRECT(a, b, c) ({             \
    for(k = 0; k < ARRAYND_SAMPLES(a); k++){        \
        for(i = 0; i < ARRAYND_ROWS(a); i++){       \
            for(j = 0; j < ARRAYND_COLS(a); j++){   \
                c[k][i][j] = a[k][i][j] * b;        \
}   }   }   })
#define ARRAYND_GAIN_REVERSE(a, b, c) ({            \
    for(k = 0; k < ARRAYND_SAMPLES(a); k++){        \
        for(i = ARRAYND_ROWS(a); i--;){             \
            for(j = ARRAYND_COLS(a); j--;){         \
                c[k][i][j] = a[k][i][j] * b;        \
}   }   }   })
#define ARRAYND_MUL_DIRECT(a, b, c) ({              \
    for(k = 0; k < ARRAYND_SAMPLES(a); k++){        \
        for(i = ARRAYND_ROWS(a); i--;){             \
            for(j = ARRAYND_COLS(b); j--;){         \
                c[k][i][j] = 0;                     \
                for(h = ARRAYND_ROWS(b); h--;){     \
                    c[k][i][j] +=                   \
                        a[k][i][h] * b[k][h][j];    \
}   }   }   }   })
#define ARRAYND_MUL_REVERSE(a, b, c)({              \
    for(k = 0; k < ARRAYND_SAMPLES(a); k++){        \
        for(i = ARRAYND_ROWS(a); i--;){             \
            for(j = ARRAYND_COLS(b); j--;){         \
                c[k][i][j] = 0;                     \
                for(h = ARRAYND_ROWS(b); h--;){     \
                    c[k][i][j] +=                   \
                        a[k][i][h] * b[k][h][j];    \
}   }   }   }   })

#endif