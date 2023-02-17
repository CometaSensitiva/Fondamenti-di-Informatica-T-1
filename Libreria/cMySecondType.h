#define _CRT_SECURE_NO_WARNINGS
#ifndef cMySecondType_h
#define cMySecondType_h

#include "aMyLib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>


//È il tipo intero |*|

typedef struct{
     int field1;
}mySecondType;

//Stampa mySecondType |*|
void printmySecondType(mySecondType a);

//Prende da input mySecondType e lo ritorna|*|
mySecondType scanmySecondType(void);

//Compara due mySecondType |*|
int compare2(mySecondType a, mySecondType b);

//Assegna al valore di un puntatore a myType il valore di un myType
void assign2(mySecondType* lvalue, mySecondType rvalue);

//Scambia la posizione di due myType in un array di myType
void swap2(mySecondType* e1, mySecondType* e2);


//Visual studio 2022 mi da problemi di compilazione se non la implemento(XCode no)

long int srand48_2(time_t seedval);

int findPosMax2(mySecondType *a, int dim);

void naiveSort2(mySecondType *a, int dim);

void bubbleSort2(mySecondType *a, int dim);

void insertionSort2(mySecondType *a, int dim);

void mergeSort2(mySecondType *a, int length);

void mergeSortRecursion2(mySecondType *a, int l, int r);

void mergeSortedArrays2(mySecondType *a, int l, int m, int r);

void quickSort2(mySecondType *a, int length);

void quickSortRecursion2(mySecondType *a, int low, int high);

int partition2(mySecondType *a, int low, int high);

#endif

