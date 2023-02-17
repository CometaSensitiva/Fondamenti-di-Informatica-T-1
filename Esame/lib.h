#define _CRT_SECURE_NO_WARNINGS
#ifndef lib_h
#define lib_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EXIT_GENERAL_ERROR 1
#define EXIT_MEMORY_ALLOCATION_ERROR -2
#define EXIT_FILE_ERROR -3

#define FILE_STRING_DIM 21

typedef enum { false, true }boolean;

float square(float x);

void incComp(void);

void incSwap(void);

void resetCount(void);

void incDupl(void);

void printStatistics(void);

void clearBuffer();

#endif 