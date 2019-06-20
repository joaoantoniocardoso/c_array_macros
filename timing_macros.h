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

#ifndef _TIMING_MACROS_H_
#define _TIMING_MACROS_H_

#include <time.h>
clock_t timer_start, timer_end;
double cpu_time_used;
#define TIC() timer_start = clock()
#define TAC() timer_end = clock(); cpu_time_used = ((double) (timer_end - timer_start)) / CLOCKS_PER_SEC
#define TOC() printf("Result::Elapsed Time: %Es\n", cpu_time_used)

#endif