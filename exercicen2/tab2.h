#include<stdio.h>
#include<stdlib.h>

#define TAILLEINITIALE 30

typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;

int init(int* tab, int size);

TABLEAU newArray();

int incrementArraySize(TABLEAU* tab, int incrementValue);

int afficheTab(int* tab, int size, int nbElts);

int setElement(TABLEAU* tab, int pos, int element);

int fillTabuntilN(int* tab, int size, int nbElts);

int displayElements(TABLEAU* tab, int startPos, int endPos);

int deleteElements(TABLEAU* tab, int startPos, int endPos);


