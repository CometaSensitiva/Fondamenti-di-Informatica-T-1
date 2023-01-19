#include "element.h"

//Assegna al valore di un puntatore ad element il valore di un element
void assign(element *lvalue, element rvalue){
    *lvalue=rvalue;
}

//Scambia la posizione di due elementi in un array di strutture
void swap(element *e1, element *e2){
    element temp;
    assign(&temp, *e1);
    assign(e1, *e2);
    assign(e2, temp);
    incSwap();
}
