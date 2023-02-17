#include "lib.h"

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

void clearBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}