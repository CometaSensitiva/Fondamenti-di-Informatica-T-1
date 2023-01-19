#include "elementdef.h"


//Compara due elementi di tipo struct element.Element
 
int compareElement(element e1, element e2){
    incComp();
    return (e1.Element<e2.Element) ? -1 : (e1.Element==e2.Element) ? 0 : 1;
}

//Compara due elementi di tipo struct element.Element [DIM]

/*
 int compareElement(element e1, element e2){
    int result=2;
    result = strcmp(e1.Element, e2.Element);
    incComp();
    return (result<0) ? -1 : (result==0) ? 0 : 1;
 }
 */
