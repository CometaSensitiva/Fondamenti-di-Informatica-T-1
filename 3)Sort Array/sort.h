#pragma once
#ifndef SORT_H
#define SORT_H

#include "element.h"
#include <stdlib.h>
#include <time.h>

//Visual studio 2022 mi da problemi di compilazione se non la implemento(XCode no)
/*
long int srand48(unsigned int seedval);
*/

// ora se vuoi modificare il tipo di array devi modificare la confronta string "element" e typedef di "elementdef"
int findPosMax(elementArray a, int dim);

void naiveSort(elementArray a, int dim);

void bubbleSort(elementArray a, int dim);

void insertionSort(elementArray a, int dim);

void mergeSort(elementArray a, int length);

void mergeSortRecursion(elementArray a, int l, int r);

void mergeSortedArrays(elementArray a, int l, int m, int r);

void quickSort(elementArray a, int length);

void quickSortRecursion(elementArray a, int low, int high);

int partition(elementArray a, int low, int high);

#endif
