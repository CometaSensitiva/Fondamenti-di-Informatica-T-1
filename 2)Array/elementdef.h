#pragma once
#ifndef ELEMENTDEF_H
#define ELEMENTDEF_H

#define DIM 10

#include "counter.h"
#include <string.h>


// Struttura di Element
typedef struct {
    int Element;
}element;

//Array di Element
typedef element elementArray[DIM];

int compareElement(element e1, element e2);//Se cambia il tipo di dato modifica solo questa specifica

#endif
