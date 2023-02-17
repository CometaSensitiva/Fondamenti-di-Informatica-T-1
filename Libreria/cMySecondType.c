#include "cMySecondType.h"

//Compara due numeri |*|
int compare2(mySecondType a, mySecondType b)
{
    incComp();
    return (a.field1<b.field1) ? -1 : (a.field1==b.field1) ? 0 : 1;
}


/*
//Compara due stringhe |*|
 int compareElement(mySecondType a, mySecondType b)
 {
    int result=2;
    result = strcmp(a.field1, a.field1);
    incComp();
    return (result<0) ? -1 : (result==0) ? 0 : 1;
 }
 */

//Stampa mySecondType intero |*|
void printmySecondType(mySecondType a)
{
    printf("%d",a.field1);
}

//Prende da input mySecondType |*|
mySecondType scanmySecondType(void)
{
    mySecondType a;
    scanf("%d", &a.field1);
    return a;
}

//Assegna al valore di un puntatore a myType il valore di un myType
void assign2(mySecondType *lvalue, mySecondType rvalue)
{
    *lvalue=rvalue;
}

//Scambia la posizione di due myType in un array di myType
void swap2(mySecondType *e1, mySecondType *e2)
{
    if(compare2(*e1, *e2)==0){
        incDupl();
    }else{
        mySecondType temp;
        assign2(&temp, *e1);
        assign2(e1, *e2);
        assign2(e2, temp);
        incSwap();
    }
}

int findPosMax2(mySecondType *a, int dim) {
    int i = 0;
    //Imposta la posizione del massimo di default all'indice 0
    int posMax = 0;
    for (i = 0; i < dim; i++) {
        //Se l'elemento i-esimo è maggiore secondo la funzione compare, i diventa la posMax
        if (compare2(*(a+posMax), *(a+i)) < 0)
            posMax = i;
    }
    //Ritorna la posMax
    return posMax;
}

//Naive Sort O(n^2)

void naiveSort2(mySecondType *a, int dim){
    int p;
    // Continua a iterare finché ci sono più di un elemento nell'array
    while(dim>1){
        // Trova la posizione del massimo nella parte non ancora ordinata dell'array
        p=findPosMax2(a, dim);
        // Se il massimo non è già l'ultimo elemento, lo scambia con l'ultimo elemento non ancora ordinato
        if (p<dim-1)
            swap2((a+p), (a+dim-1));
        dim--;
    }
}



//Bubble Sort O(n^2)

void bubbleSort2(mySecondType *a, int dim){
    int i;
    int ordinato = 0;
    while (dim>1 && !ordinato){
     ordinato = 1;
     for (i=0; i<dim-1; i++)
       if (compare2(*(a+i),*(a+i+1))>0) {
            swap2((a+1),(a+i+1));
            ordinato = 0;
       } dim--;
  }
}

//Insertion Sort O(n^2)

void insertionSort2(mySecondType *a, int dim){
    int i, j;
    mySecondType key;
    //Il ciclo esterno esamina ogni elemento nella parte destra dell'array
    //dal secondo elemento fino alla fine dell'array
    for (i=1; i<dim;i++){
        //Il ciclo interno shifta ogni elemento dalla parte ordinata sinistra dell'array
        //fin quando non viene trovata la collocazione giusta per "key", nella quale viene viene messo
        assign2(&key,*(a+i));
        j= i-1;
        while(j>= 0 && compare2(*(a+j),key)>0){
            assign2((a+j+1),*(a+j));
            j=j-1;
        }
        //inserisce l'elemento
        assign2((a+j+1),key);
    }
}


//Merge Sort O(nLog(n))
//NB il mergeSort restituisce un array senza duplicati
void mergeSort2(mySecondType *a, int length) {
    //Che chiama la funzione che divide ricorsivamente in subArray
    mergeSortRecursion2(a, 0, length - 1);
}

void mergeSortRecursion2(mySecondType *a, int l, int r)
//l = limite sinistro dell'array, r = limite destro dell'array
{
    //fin quando l'estremo sinistro è minore di quello destro, dividiamo l'array disordinato in parti sempre più piccole
    if (l < r)
    {
        //definisco l'indice del del punto medio dell'array da dove dividere in due sub-Array
        int m = l + (r - l) / 2;
        mergeSortRecursion2(a, l, m);
        mergeSortRecursion2(a, m + 1, r);
        mergeSortedArrays2(a, l, m, r);
    }
}

void mergeSortedArrays2(mySecondType *a, int l, int m, int r) {

    int leftLength = 0;
    int rightLength = 0;
    //lunghezza della parte sinistra dell'array
    leftLength = m - l + 1;
    //lunghezza della parte destra dell'array
    rightLength = r - m;

    // creo array temporanei per storare le due parti
    mySecondType *tempLeft = NULL;
    mySecondType *tempRight = NULL;
    
    tempLeft = (mySecondType *)malloc(leftLength*sizeof(mySecondType));
    tempRight = (mySecondType *)malloc(rightLength*sizeof(mySecondType));

    if (tempLeft == NULL || tempRight == NULL) {
        printf("Errore allocazione di memoria mergeSortedArrays \n");
        exit(EXIT_MEMORY_ALLOCATION_ERROR);
    }

    //indici utilizzati per gli array a, tempLeft, tempRight
    int i, j, k;

    //copiamo il contenuto dell'array iniziale in due suoi sottoarray

    //array sinistro, inizia all'indice l, poi devo incrementare
    for (int i = 0; i < leftLength; i++)
        assign2((tempLeft+i), *(a+l+i));

    //array destro inizia all'indice m+1, poi devo incrementare
    for (int i = 0; i < rightLength; i++)
        assign2((tempRight+i), *(a+m + 1 + i));

    //PARTE DIFFICILE UNIONE DEI DUE SUB-ARRAY
    //k è l'indice che tiene traccia dell'array iniziale a[]

    //i è l'indice che tiene traccia dell'indice di tempLeft[]
    //j è l'indice che tiene traccia dell'indice di tempRight[]
    // i e j saranno rispettivamente incrementati solo nel caso in cui vengano utilizzato elementi di tempLeft o tempRight

    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        //Questa condizione determina il caso in cui noi vogliamo effettivamente copiare gli elementi da tempLeft[] ad a[]
        //le prime due condizioni controllano che non si esca fuori dai due subArray sx e dx, la terza determina se utilizzare un elemento da tempLeft[] o tempRight[]  <=
        if ((i < leftLength) && (j >= rightLength || compare2(*(tempLeft+i), *(tempRight+j)) <= 0)) {
            assign2((a+k), *(tempLeft+i));
            i++;
        }
        //
        else {
            assign2((a+k), *(tempRight+j));
            j++;
        }
    }
}

 //Mi serve per VS2022
long int srand48_2(time_t seedval){
    srand(seedval);
    return rand();
}

// rende la funzione più bella poiché alla chiamata devo inserire solo l'array e la lunghezza e lei ricorsivamente fa le sue chiamate
// (sarebbe evitabile, ma migliora l'interfaccia)
void quickSort2(mySecondType *a, int length){
    // immetto un seed al generatore di numeri casuali che sia ogni volta diverso.
    //srand(seed)
    //uso srand 48 perché accetta come argomento un unsigned long int e non un semplice unsigned int
    //time(NULL) -> ritorna il current time (un valore che cambia sempre)
    
    srand48_2(time(NULL));
    
    quickSortRecursion2(a, 0, length-1);
}


void quickSortRecursion2(mySecondType *a, int low, int high){
    
    if(low<high){
        //mi ritorna l'indice del pivot
        int pivotIndex= partition2(a, low, high);
        //la parte a sinistra del pivot
        quickSortRecursion2(a, low, pivotIndex-1);
        //la parte a destra del pivot
        quickSortRecursion2(a, pivotIndex+1, high);
    }
}

//Divide l'array tra gli indici low e high in base a un pivot e ritorna l'inidce del pivot
int partition2(mySecondType *a, int low, int high){
    //si può dimostrare che prendere il pivot sempre come ultimo elemento può essere svantaggioso
    //prendo un valore casuale tra high e low
    int pivotIndex=low+(rand()%(high-low));
    if (pivotIndex!=high){
        swap2((a+pivotIndex), (a+high));
    }
    //assumiamo che il pivot sia sempre l'ultimo elemento della porzione di array che stiamo considerando
    mySecondType pivotValue;
    assign2(&pivotValue,*(a+high));
    int i=low;
    //il ciclo esterno mette gli elementi minori del valore del pivot a sinistra del pivot
    //il ciclo interno mette gli elementi maggiori del valore del pivot a destra del pivot
    //in realtà scambiando
    for(int j=low;j<high;j++){
        if(compare2(*(a+j),pivotValue)<=0){
            swap2((a+i), (a+j));
            i++;
        }
    }
    // il valore all'indice i è => al valore del pivot quindi scambiamo il valore dell'inidice i per completare la divisone dell'array
    swap2((a+i), (a+high));
    
    //ritorna l'indice del pivot così che quickSortRecursion(...) sappia dove dividere l'array quando viene applicato l'algoritmo ai sub-array
    return i;
}
