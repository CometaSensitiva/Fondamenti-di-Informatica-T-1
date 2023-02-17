#include "aMyLib.h"

int compCount = 0;
int swapCount = 0;
int duplCount = 0;

float square(float x)
{
    return x * x;
}

void incComp(void)
{
    compCount++;
}

void incSwap(void)
{
    swapCount++;
}

void incDupl(void)
{
    duplCount++;
}

void resetCount(void)
{
    compCount = 0;
    swapCount = 0;
    duplCount = 0;
}

void printStatistics(void)
{
    printf("Comparations : %d\n", compCount);
    printf("Swaps : %d\n", swapCount);
    printf("Duplicates : %d\n", duplCount);
    resetCount();
}

//Apre un file per VS2022
FILE* myfopen(FILE* fp, char* filename, char* mode)
{
    if ((fp = fopen(filename, mode)) == NULL) {
        printf("Errore nell'apertura %s", filename);
        exit(EXIT_FILE_ERROR);
    }
    return fp;
}
