#include "listelement.h"

//Stampa element intero|*|
void printlistElement(listElement e) {
    printf("%d", e);
}

//Stampa un array ricavato da una lista
void printListElementArray(listElement *v, int maxDim){
    int i=0;
    for(i=0;i<maxDim;i++){
        printf("v%d=", i);
        printf("[ ");
        printlistElement(*(v+i));
        printf(" ] ");
    }
}
/*
//Stampa element stringa|*|
void printlistElement(listElement e) {
    printf("%s ", e);
}
*/


//Prende da input element intero |*|
listElement getlistElement(void) {
    listElement e;
    printf("Enter element : ");
    scanf("%d", &e);
    printf("\n");
    return e;
}

/*
//Prende da input element striga|*|
 listElement getlistElement(void) {
    listElement e;
    scanf("%s", e);
    return e;
}
*/

//Compara due element interi |*|
int comparelistElement(listElement e1, listElement e2) {
    if (e1 < e2)
        return -1;
    else if (e1 == e2)
        return 0;
    else return 1;
}

/*
//Compara due elementi stringa |*|
int comparelistElement(listElement e1, listElement e2) {
    if (strcmp(e1, e2) < 0)
        return -1;
    else if (strcmp(e1, e2) == 0)
        return 0;
    else return 1;
}
*/
