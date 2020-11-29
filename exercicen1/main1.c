#include"tab.h"



int main() {

	int myTab1[10];
	initTab(myTab1, 10);
	printf("le premier tableau � construire est :\n");
	afficheTab(myTab1, 10, 10); //premi�re partie de l'exercice 1
	printf("\n\n\n\n\n");

	int* myTab2 = NULL;
	int tab2Size = TAB2SIZE;
	int nbElts2 = 20;

	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));//on r�serve de l'espace pour le tableau myTab2
	if (myTab2 != NULL) { initTab(myTab2, tab2Size); }//si la ligne precedente a �t� prise en compte, on initialise le tableau
	else { printf("memoire insuffisante"); return(-1); }//sinon on le fait savoir � l'user


	fillTabuntilN(myTab2, TAB2SIZE, nbElts2);//on remplit le tableau
	printf("le deuxiene tableau � construire est :\n");
	afficheTab(myTab2, TAB2SIZE, nbElts2);//on l'affiche
	free(myTab2);//on lib�re le tableau pour r�cup�rer de la place

	printf("\n\n\n\n\n");

	int* myTab3;
	int* tab3Size = TAB3SIZE;
	int* nbElts3 = TAB3SIZE;//on aurait ici pu mettre une valeur quelconque




	myTab3 = (int*)malloc(TAB2SIZE * sizeof(int));//on r�serve de l'espace pour le tableau myTab2
	if (myTab3 != NULL) { initTab(myTab3, tab3Size); }//si la ligne precedente a �t� prise en compte, on initialise le tableau
	else { printf("memoire insuffisante"); return(-1); }//sinon on le fait savoir � l'user


	fillTabuntilN(myTab3, tab3Size, nbElts3);//on remplit d�j� le tableau, comme fait auparavant avec le myTab2

	myTab3 = ajouteElementDansLeTableau(myTab3, &tab3Size, &nbElts3, 59);//myTab3 r�cup�re la valeur retourn�e par la fonction
	myTab3 = ajouteElementDansLeTableau(myTab3, &tab3Size, &nbElts3, 5);
	printf("le troisieme tableau � construire est :\n");
	afficheTab(myTab3, tab3Size, nbElts3);//on affiche ici le tableau modifi�

	return EXIT_SUCCESS;
}