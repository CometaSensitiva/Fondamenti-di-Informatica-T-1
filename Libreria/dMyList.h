#define _CRT_SECURE_NO_WARNINGS

#ifndef dMyList_h
#define dMyList_h

#include "aMyLib.h"

//In caso di altro tipo di dato, modificare quelle con |*|

typedef struct element_list {
    myType value;
    struct element_list* next;
}item;

//Un puntatore a un nodo
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
myType head(list l);

//Prende una lista come argomento e restituisce l'elemento successivo della lista
list tail(list l);

//Prende una lista e un elemento come argomento e restituisce una nuova lista con l'elemento posto in testa
list cons(myType e, list l);


//->NON PRIMITIVE SENZA COMPARE


//fa la free della lista
void freelist(list l);

/*
//Stampa la lista
void showlist(list l);
*/

//Calcola il numero di elementi della lista data
int length(list l);//ITERATIVA
int recursiveLength(list l); // RICORSIVA

//Restituisce una lista che sia il concatenamento di due liste l1 e l2
list append(list l1, list l2);

//Restituisce una lista che sia in ordine inverso rispetto a quella data
list reverse(list l);

//Copia la lista passata per argomento
list copy(list l);

//Crea un array da una lista
myType* fromListToArray(list l1, int* size);

//Crea una lista da un array
list fromArrayToList(myType* v, int size);

/*
//->NON PRIMITIVE CON COMPARE

//Prende una lista e un elemento come argomento e determina se è presente nella lista data
boolean member(myType e, list l); //ITERATIVA
boolean recursiveMember(myType e, list l); //RICORSIVA

//Elimina l'elemento e dalla lista l
list deleteList(myType e, list l);

//Inserisce l'elemento in ordine,( la lista deve essere ordinata)
list insord(myType e, list l);

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

//Fonde l1 e l2 ordinate in l3 senza ripetizioni RICORSIVA
list mergeList(list l1, list l2);
*/
#endif