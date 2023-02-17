#define _CRT_SECURE_NO_WARNINGS
#ifndef bMyType_h
#define bMyType_h

#include "aMyLib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

//È il tipo intero |*|

typedef struct{
     int field1;
}myType;

//Stampa myType |*|
void printmyType(myType a);

//Stampa Array di myType
void showArray(myType *a, int dim);

//Prende da input myType e lo ritorna|*|
myType scanmyType(void);


/* ORDINAMENTO */

//Compara due myType |*|
int compare(myType a, myType b);

//Assegna al valore di un puntatore a myType il valore di un myType
void assign(myType* lvalue, myType rvalue);

//Scambia due elementi myType in un Array
void swap(myType *e1, myType *e2);


//Visual studio 2022 mi da problemi di compilazione se non la implemento(XCode no)

long int srand48(time_t seedval);


int findPosMax(myType *a, int dim);

void naiveSort(myType *a, int dim);

void bubbleSort(myType *a, int dim);

void insertionSort(myType *a, int dim);

void mergeSort(myType *a, int length);

void mergeSortRecursion(myType *a, int l, int r);

void mergeSortedArrays(myType *a, int l, int m, int r);

void quickSort(myType *a, int length);

void quickSortRecursion(myType *a, int low, int high);

int partition(myType *a, int low, int high);

#endif
