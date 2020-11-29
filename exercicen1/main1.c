#include"tab.h"



int main() {

	int myTab1[10];
	initTab(myTab1, 10);
	printf("le premier tableau à construire est :\n");
	afficheTab(myTab1, 10, 10); //première partie de l'exercice 1
	printf("\n\n\n\n\n");

	int* myTab2 = NULL;
	int tab2Size = TAB2SIZE;
	int nbElts2 = 20;

	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));//on réserve de l'espace pour le tableau myTab2
	if (myTab2 != NULL) { initTab(myTab2, tab2Size); }//si la ligne precedente a été prise en compte, on initialise le tableau
	else { printf("memoire insuffisante"); return(-1); }//sinon on le fait savoir à l'user


	fillTabuntilN(myTab2, TAB2SIZE, nbElts2);//on remplit le tableau
	printf("le deuxiene tableau à construire est :\n");
	afficheTab(myTab2, TAB2SIZE, nbElts2);//on l'affiche
	free(myTab2);//on libère le tableau pour récupérer de la place

	printf("\n\n\n\n\n");

	int* myTab3;
	int* tab3Size = TAB3SIZE;
	int* nbElts3 = TAB3SIZE;//on aurait ici pu mettre une valeur quelconque




	myTab3 = (int*)malloc(TAB2SIZE * sizeof(int));//on réserve de l'espace pour le tableau myTab2
	if (myTab3 != NULL) { initTab(myTab3, tab3Size); }//si la ligne precedente a été prise en compte, on initialise le tableau
	else { printf("memoire insuffisante"); return(-1); }//sinon on le fait savoir à l'user


	fillTabuntilN(myTab3, tab3Size, nbElts3);//on remplit déjà le tableau, comme fait auparavant avec le myTab2

	myTab3 = ajouteElementDansLeTableau(myTab3, &tab3Size, &nbElts3, 59);//myTab3 récupère la valeur retournée par la fonction
	myTab3 = ajouteElementDansLeTableau(myTab3, &tab3Size, &nbElts3, 5);
	printf("le troisieme tableau à construire est :\n");
	afficheTab(myTab3, tab3Size, nbElts3);//on affiche ici le tableau modifié

	return EXIT_SUCCESS;
}