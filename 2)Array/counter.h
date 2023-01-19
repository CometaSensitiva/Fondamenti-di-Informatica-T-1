#pragma once
#ifndef COUNTER_H
#define COUNTER_H


#include "mylib.h"

//incrementa di +1 il contatore dei confronti
void incComp(void);

//incrementa di +1 il contatore degli scambi
void incSwap(void);

//resetta i contatori
void resetCount(void);

//stampa le i contatori di confronti e scambi poi li azzera
void printStatistics(void);
#endif

