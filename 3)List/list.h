#pragma once
#ifndef LIST_H
#define LIST_H

#include "listelement.h"
#include <stdlib.h>

typedef struct element_list {
    int value;
    struct element_list * next;
}item;

typedef item* list;

//Tiene traccia della memoria allocata
void printAllocCounter(void);

//->PRIMITIVE

/* costruttore lista vuota */
list emptyList(void);

//Controlla se una lista è vuota
//true se è vuota
//false se non lo è
boolean empty(list l);

//Prende una lista come argomento e restituisce l'elemento contenuto
listElement head(list l);

//Prende una lista come argomento e restituisce l'elemento successivo della lista
list tail(list l);

//Prende una lista e un elemento come argomento e restituisce una nuova lista con l'elemento posto in testa
list cons(listElement e, list l);

//->NON PRIMITIVE


//fa la free della lista
void freelist(list l);

//Stampa la lista
void showlist(list l);

//Prende una lista e un elemento come argomento e determina se è presente nella lista data
boolean member(listElement e, list l); //ITERATIVA
boolean recursiveMember(listElement e, list l); //RICORSIVA

//Calcola il numero di elementi della lista data
int length(list l);//ITERATIVA
int recursiveLength(list l); // RICORSIVA

//Restituisce una lista che sia il concatenamento di due liste l1 e l2
list append(list l1, list l2);

//Restituisce una lista che sia in ordine inverso rispetto a quella data
list reverse(list l);

//Copia la lista passata per argomento
list copy(list l);

//Elimina l'elemento e dalla lista l
list deleteList(listElement e, list l);

//Inserisce l'elemento in ordine,( la lista deve essere ordinata)
list insord(listElement e, list l);

//Elimina gli elementi duplicati adiacenti
list unique(list l);

//Elimina i duplicati da una lista
list unique2(list l);

//Date l1 e l2 ordinate, restituisce una lista eliminando l2 da l1
list escludil2(list l1, list l2);

//Date l1 e l2 ordinate, restituisce la loro intersezione
list intersect(list l1, list l2);

//Date l1 e l2 anche NON ordinate e anche CON elementi ripetuti, restituisce la loro intersezione, senza ripetizioni
list intersect2(list l1, list l2);

//Crea un array da una lista
listElement * fromListToArray(list l1, int * size);

//Crea una lista da un array
list fromArrayToList(int * v, int size);
#endif
