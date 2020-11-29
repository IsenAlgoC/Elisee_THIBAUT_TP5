#pragma once
#include<stdio.h>
#include<stdlib.h>


#define TAB2SIZE 100
#define TAILLEAJOUT 10
#define TAB3SIZE 100

int initTab(int* tab, int size);

int afficheTab(int* tab, int size, int nbElts);



int fillTabuntilN(int* tab, int size, int nbElts);


int* ajouteElementDansLeTableau(int* tab, int* size, int* nbElts, int element);
