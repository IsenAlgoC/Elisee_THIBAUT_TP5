#include"tab.h"


int initTab(int* tab, int size) {
	if (size < 0) { return-1; }//on n'effectue pas la fonction si la taille est négative

	for (int i = 0; i < size; i++) {
		tab[i] = 0;//toutes les valeurs du tableau devienent nulles
	}

}


int afficheTab(int* tab, int size, int nbElts) {
	if ((size < 0) || (size < nbElts)) { return NULL; }//on ne montre pas le tableau si on n'a pas de bonnes conditions

	for (int i = 0; i < nbElts; i++) {//on affiche tous les nombres placés aux rangs i se succédants du tableau
		printf("%d ", tab[i]);
	}
}



int fillTabuntilN(int* tab, int size, int nbElts) {//pour remplir un tableau avec les
	if ((size < 0) || (size < nbElts)) { return -1; }//valeurs de 1 à n

	for (int i = 0; i < nbElts; i++) {
		tab[i] = i + 1;//ici i+1 car le tableau compte à partir du rang 0 et non 1
	}
}

int* ajouteElementDansLeTableau(int* tab, int* size, int* nbElts, int element) {
	//ici, tab est le tableau a modifier
	// size : sa taille initiale
	//nbElts : le nombre d' éléments qu'il y a déja
	//element : ce qu'on veut ajouter

	int* tab2 = NULL;
	if ((tab != NULL) && (size > 0)) {//si on est dans des circonstances qui font sens, on execute le programme
		if (*size <= *nbElts) {//on réalloue de l'espace au tableau si la taille est insuffisante

			int* tab2 = tab;//on stocke le tableau dans un autre, pour éviter d'avoir des erreurs et de le perdre

			tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));//on le réaloue avec plus de place
			*size = *size + TAILLEAJOUT;//on change donc la valeur de la taille du tableau

			if (tab == NULL)//si ça a échoué (le tableau devient nul), on arete et on le fait savoir à l'utilisateur
			{
				printf("memoire insuffisante"); return NULL;
			}
		}

		if (tab != NULL) {//si le tableau n'est pas nul, après avoir ralongé le tableau ou non, on y ajoute la valeur souhaitée
			tab[*nbElts] = element;//on ajoute l'élément choisi après les autres
			*nbElts = *nbElts + 1;//on incremente le nombre d'élements, car on a ajouté un élement
		}

		return tab;//on renvoie maintenant le tableau modifié
	}
}