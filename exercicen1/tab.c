#include"tab.h"


int initTab(int* tab, int size) {
	if (size < 0) { return-1; }//on n'effectue pas la fonction si la taille est n�gative

	for (int i = 0; i < size; i++) {
		tab[i] = 0;//toutes les valeurs du tableau devienent nulles
	}

}


int afficheTab(int* tab, int size, int nbElts) {
	if ((size < 0) || (size < nbElts)) { return NULL; }//on ne montre pas le tableau si on n'a pas de bonnes conditions

	for (int i = 0; i < nbElts; i++) {//on affiche tous les nombres plac�s aux rangs i se succ�dants du tableau
		printf("%d ", tab[i]);
	}
}



int fillTabuntilN(int* tab, int size, int nbElts) {//pour remplir un tableau avec les
	if ((size < 0) || (size < nbElts)) { return -1; }//valeurs de 1 � n

	for (int i = 0; i < nbElts; i++) {
		tab[i] = i + 1;//ici i+1 car le tableau compte � partir du rang 0 et non 1
	}
}

int* ajouteElementDansLeTableau(int* tab, int* size, int* nbElts, int element) {
	//ici, tab est le tableau a modifier
	// size : sa taille initiale
	//nbElts : le nombre d' �l�ments qu'il y a d�ja
	//element : ce qu'on veut ajouter

	int* tab2 = NULL;
	if ((tab != NULL) && (size > 0)) {//si on est dans des circonstances qui font sens, on execute le programme
		if (*size <= *nbElts) {//on r�alloue de l'espace au tableau si la taille est insuffisante

			int* tab2 = tab;//on stocke le tableau dans un autre, pour �viter d'avoir des erreurs et de le perdre

			tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));//on le r�aloue avec plus de place
			*size = *size + TAILLEAJOUT;//on change donc la valeur de la taille du tableau

			if (tab == NULL)//si �a a �chou� (le tableau devient nul), on arete et on le fait savoir � l'utilisateur
			{
				printf("memoire insuffisante"); return NULL;
			}
		}

		if (tab != NULL) {//si le tableau n'est pas nul, apr�s avoir ralong� le tableau ou non, on y ajoute la valeur souhait�e
			tab[*nbElts] = element;//on ajoute l'�l�ment choisi apr�s les autres
			*nbElts = *nbElts + 1;//on incremente le nombre d'�lements, car on a ajout� un �lement
		}

		return tab;//on renvoie maintenant le tableau modifi�
	}
}