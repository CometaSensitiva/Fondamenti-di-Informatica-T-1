#include "dMyList.h"
static int allocCounter = 0;

//Tiene traccia della memoria allocata;
void printAllocCounter(void)
{
    printf("Memoria allocata : %d\n", allocCounter);
    allocCounter = 0;
}

//->PRIMITIVE

//Crea una lista vuota
list emptyList(void)
{
    return NULL;
}

//Verifica se lista vuota
boolean empty(list l)
{
    if (l == NULL)
        return true;
    else return false;
}

//Selettore testa lista
myType head(list l)
{
    if (empty(l) == true) {
        puts("listElement head() -> Errore selettore testa\n");
        exit(EXIT_MEMORY_ALLOCATION_ERROR);
    }
    else return l->value;
}

//Selettore coda lista
list tail(list l)
{
    if (empty(l) == true) {
        puts("listElement tail() -> Errore selettore coda\n");
        exit(EXIT_MEMORY_ALLOCATION_ERROR);
    }
    else return l->next;
}

//Costruttore che aggiunge in testa alla lista
list cons(myType e, list l)
{
    list t = NULL;
    t = (list)malloc(sizeof(item));
    allocCounter++;
    if (t == NULL) {
        puts("list cons() -> Errore allocamento memoria\n");
        exit(EXIT_MEMORY_ALLOCATION_ERROR);
    }
    else if (t != NULL) {
        t->value = e;
        t->next = l;
    }
    return t;
}

//->NON PRIMITIVE SENZA COMPARE

//Fa la free della lista
void freelist(list l)
{
    if (empty(l) == true)
        return;
    else {
        freelist(tail(l));
        free(l);
    }
    return;
}
/*
//Stampa la lista
void showlist(list l)
{
    printf("List:\n");
    printf("[ ");
    while (empty(l) == false) {
        //condizione da modificare in caso la lista cambi tipo
        printmyType(head(l));
        l = tail(l);
        if (empty(l) == false)
            printf(", ");
    }
    printf(" ]\n");
}
*/
//Calcola il numero di elementi della lista data ITERATIVA
int length(list l)
{
    int counter = 0;
    while (!empty(l)) {
        counter++;
        l = tail(l);
    }
    return counter;
}
//Calcola il numero di elementi della lista data  RICORSIVA
int recursiveLength(list l)
{
    //caso base
    if (empty(l) == true) {
        return 0;
    }
    else return 1 + recursiveLength(l);
}

//Restituisce una lista che sia il concatenamento di due liste l1 e l2
list append(list l1, list l2)
{
    if (empty(l1) == true)
        return l2;
    //chiamata ricorsiva
    else  return cons(head(l1), append(tail(l1), l2));
}

//Restituisce una lista che sia in ordine inverso rispetto a quella data
list reverse(list l)
{
    if (empty(l)) {
        return emptyList();
    }
    else return append(reverse(tail(l)), cons(head(l), emptyList()));
}

//Copia la lista passata per argomento
list copy(list l)
{
    if (empty(l) == true)
        return l;
    else return cons(head(l), copy(tail(l)));
}

//Crea un array da una lista
myType* fromListToArray(list l1, int* size)
{
    myType* v = NULL;
    int i = 0;
    *size = length(l1);
    v = (myType*)malloc(sizeof(myType) * (*size));
    while (!empty(l1)) {
        *(v + i) = head(l1);
        l1 = tail(l1);
        i++;
    }
    return v;
}

//Crea una lista da un array
list fromArrayToList(myType* v, int size)
{
    if (size == 0)
        return emptyList();
    else
        return cons(*v, fromArrayToList(v + 1, size - 1));
}

/*
//Prende una lista e un elemento come argomento e determina se � presente nella lista data  ITERATIVA
boolean member(myType e, list l)
{
    while (!empty(l)) {
        if (compare(head(l), e)==0) //condizione da modificare in caso la lista cambi tipo
            return true;
        else
            l = tail(l);
    }
    return false;
}

//Prende una lista e un elemento come argomento e determina se � presente nella lista data  RICORSIVA
boolean recursiveMember(myType e, list l)
{
    //caso base
    if (empty(l))
        return false;
    else if (compare(head(l), e) == 0)//condizione da modificare in caso la lista cambi tipo
        return true;
    else
        return(recursiveMember(e, tail(l)));
}



//Elimina l'elemento dalla lista
list deleteList(myType e, list l)
{
    if (empty(l))
        return emptyList();
    else if (compare(e, head(l)) == 0)
        return copy(tail(l));
    else return cons(head(l), deleteList(e, tail(l)));
}

//Inserisce l'elemento in ordine,( la lista deve essere ordinata)
list insord(myType e, list l)
{
    if (empty(l) == true)
        return cons(e, l);
    else if (compare(e, head(l)) <= 0)//Questa relazione d'ordine va modificata nel caso di utilizzo di un altro tipo
        return cons(e, l);
    else return cons(head(l), insord(e, tail(l)));
}

//Inserisce l'elemento in ordine,( la lista deve essere ordinata), versione senza libreria
list insordPtr(myType e, list l)
{
    list pprec=NULL, patt = l, paux;
    boolean trovato = false;
    while (patt != NULL && !trovato) {
        if (compare(e, patt->value)<0)
            trovato = true;
        else {
        pprec = patt;
        patt = patt->next;
        }
    }
    paux = (list)malloc(sizeof(item));
    paux->value = e;
    if (patt == l)
        return paux;
    else {
        pprec->next = paux;
        return l;
    }
}

//Elimina gli elementi duplicati adiacenti
list unique(list l)
{
    //Caso base quello del prof � sbagliato
    if (empty(tail(l))==true)
        return l;
    else if(compare(head(l), head(tail(l)))!=0)
        return cons(head(l),unique(tail(l)));
    else return unique(tail(l));
}

//Elimina i duplicati da una lista
list unique2(list l)
{
    list result;
    if(l==NULL)
       return l;
    else if(l->next==NULL)
        return l;
    else{
        if(compare(l->value,l->next->value)==0)
            return unique(l->next);
        else{
            result=(list)malloc(sizeof(item));
            result->value=l->value;
            result->next=unique2(l->next);
            return result;
        }
    }
}

//Date l1 e l2 ordinate, restituisce una lista eliminando l2 da l1
list escludil2(list l1, list l2)
{                                              //l1=[ -7, -2, 0, 3, 5, 8, 15]
    list result=emptyList();                   //l2=[ -1, 3, 4, 5 ]
    while(empty(l1)==false){
        if(member(head(l1), l2)==false)
        result=(cons(head(l1),result));
        l1=tail(l1);
    }
    return result;                             //result=[ -7, -2, 0, 8, 15 ].
}

//Date l1 e l2 ordinate, restituisce la loro intersezione
list intersect(list l1, list l2)
{
    list result=emptyList();                //l1=[ -7, -2, 0, 3, 5, 8, 15]
    while(!empty(l1)){                      //l2=[ -1, 3, 4, 5 ]
        if(member(head(l1), l2)){
            result=cons(head(l1), result);
            l1=tail(l1);
        }
        else
            l1=tail(l1);
    }
    return result;                          //result=[ 3, 5 ].
}

//Date l1 e l2 anche NON ordinate e anche CON elementi ripetuti, restituisce la loro intersezione, senza ripetizioni
list intersect2(list l1, list l2)
{
    if(empty(l1))
        return l1;
    else{
        if(member(head(l1), l1) && !member(head(l1), tail(l1)))
            return cons(head(l1), intersect2(tail(l1), l2));
        else return intersect2(tail(l1), l2);
    }
}

//Fonde l1 e l2 ordinate in l3 senza ripetizioniRICORSIVA
list mergeList(list l1, list l2)
{
    if (empty(l1))
        return l2;
    else if(empty(l2))
        return l1;
    else {
    if (compare(head(l1), head(l2))<0)
        return cons(head(l1),mergeList(tail(l1),l2));
    else if (compare(head(l1), head(l2))==0)
        return cons(head(l1),mergeList(tail(l1),tail(l2)));
    else return cons(head(l2),mergeList(l1,tail(l2)));
    }
}
*/