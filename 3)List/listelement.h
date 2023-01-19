#pragma once
#ifndef LISTELEMENT_H
#define LISTELEMENT_H
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "myLib.h"


//In caso di altro tipo di dato, modificare quelle con |*|

//Un tipo listElement per rappresentare un generico tipo |*|
typedef int listElement;

//Stampa listElement |*|
void printlistElement(listElement e);

//Stampa un array ricavato da una lista
void printListElementArray(listElement *v, int maxDim);

//Prende da input listElement |*|
listElement getlistElement(void);

//Compara due listElement |*|
int comparelistElement(listElement e1, listElement e2);

#endif
