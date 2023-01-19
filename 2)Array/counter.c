#include "counter.h"

//variabili globali
int compCount = 0;
int swapCount = 0;

void incComp(void) {
    compCount++;
}

void incSwap(void) {
    swapCount++;
}

void resetCount(void) {
    compCount = 0;
    swapCount = 0;
}
void printStatistics(void) {
    printf("Comparations : %d\n", compCount);
    printf("Swaps : %d\n", swapCount);
    resetCount();
}
