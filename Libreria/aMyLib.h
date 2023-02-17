#define _CRT_SECURE_NO_WARNINGS
#ifndef aMyLib_h
#define aMyLib_h


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EXIT_GENERAL_ERROR 1
#define EXIT_MEMORY_ALLOCATION_ERROR -2
#define EXIT_FILE_ERROR -3

#define FILE_STRING_DIM 21

typedef enum { false, true }boolean;

float square(float x);

void incComp(void);

void incSwap(void);

void resetCount(void);

void incDupl(void);

void printStatistics(void);

//Apre un file per VS2022
FILE* myfopen(FILE* fp, char* filename, char* mode);
/*
*
* fopen () apre un file per la lettura o la scrittura.
* fclose () chiude un file dopo averlo letto o scritto.
* fscanf () legge i dati da un file.
* fprintf () stampa i dati su un file.
* fgetc () legge un carattere da un file.
* fputc () scrive un carattere su un file.
* fseek () cambia la posizione attuale del file.
* ftell () restituisce la posizione attuale del file.
* rewind () riporta la posizione del file all'inizio
* fwrite () scrive un blocco di dati su un file.
* feof () controlla se si è raggiunta la fine di un file.
*
* La funzione scanf() con il parametro di formato "[^;]"
* memorizzerà la stringa inserita senza considerare il caricatore,
* quindi tutti i caratteri da inserire saranno memorizzati in stringa.
* char stringa[100];
*
*   printf("Inserisci una stringa fino a ;");
*   scanf("%[^;]", stringa);
*
*
* La funzione snprintf della libreria standard di C consente
* all'utente di creare una stringa formattata in un buffer predefinito.
* Prende in ingresso tre argomenti: il puntatore al buffer, la dimensione del buffer e
* la stringa che deve essere scritta
* nella memoria allocata.
*
* #include <stdio.h>
*
* int main(){
*    char buffer[256]; // Allocazione di un buffer con dimensione del 256 byte
*    snprintf(buffer, sizeof(buffer), "Il mio nome è %s e ho %d anni", "Mario", 32);
*    printf("%s\n", buffer); // Stampa: Il mio nome è Mario e ho 32 anni
*   return 0;
* }
*
* size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
* fprintf() scrive il numero come una stringa di caratteri, mentre fwrite()
* scrive il numero come una sequenza di byte.
*
* size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
* fscanf() legge il numero come una stringa di caratteri e lo
* converte nella sua rappresentazione interna,
* mentre fread() legge il numero come una sequenza di byte e lo assegna direttamente alla variabile.
*
 */
#endif 
