#include"tab2.h"



int init(int* tab, int size) {
	if (size < 0) { return-1; }//on n'effectue pas la fonction si la taille est négative

	for (int i = 0; i < size; i++) {
		tab[i] = 0;//toutes les valeurs du tableau devienent nulles
	}

}


TABLEAU newArray() {//on crée une fonction sans arguments, afin de pouvoir créer un TABLEAU depuis rien
	TABLEAU tab;//on crée donc un TABLEAU dans la fonction

	tab.elt = NULL;//on initialise le tableau en NULL

	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	if (tab.elt != NULL) { init(tab.elt, TAILLEINITIALE); }
	else { printf("mémoire insuffisante"); }//on lui alloue de la place si possible, comme dans l'exo 1

	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;//on termine par compléter le TABLEAU, avec les 2 champs manquants
	return tab;//on renvoie le tableau
}


int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int* stocktab;//on crée un tableau de stockage, pour garder tab.elt, au cas ou un accident se produit
	stocktab = tab->elt;
	int incr = tab->size + incrementValue;
	tab->elt = (int*)realloc(tab->elt, (incr) * sizeof(int));//on réalloue de l'espace

	if (tab->elt == NULL) {
		printf("erreur de reallocation");
		return-1;
	}//si l'allocation a échoué, on le fait savoir

	else {
		tab->size = tab->size + incrementValue;//on modifie la valeur de la taille
		return tab->size;
	}
}


int afficheTab(int* tab, int size, int nbElts) {
	if ((size < 0) || (size < nbElts)) { return -1; }//on ne montre pas le tableau si on n'a pas de bonnes conditions

	for (int i = 0; i < nbElts; i++) {//on affiche tous les nombres placés aux rangs i se succédants du tableau
		printf("%d ", tab[i]);
	}
}
    /// \\\
   /// | \\\
  ///  |  \\\
 ///   |   \\\
///    o    \\\
===============
//pour les fonctions setElement, displayElements and deleteElement, le premier élement considéré est l'élement 1 et non 0
//pour afficher, placer ou supprimer un élement, on ne peut pas commence à 0

int setElement(TABLEAU* tab, int pos, int element) {

	int* tab2 = NULL;


	if (tab->size <= pos) {//on réalloue de l'espace au tableau si la taille est insuffisante

		tab2 = tab->elt;//on stocke le tableau dans un autre, pour éviter d'avoir des erreurs et de le perdre

		tab->elt = (int*)realloc(tab->elt, (pos) * sizeof(int));//on le réaloue avec au moins la taille de la position

		if (tab->elt != NULL) {//si la réallocation est un succès
			for (int i = tab->size; i < pos; i++) {//on initialise la partie qui vient d'être créée
				tab->elt[i] = 0;
			}
		}
		tab->size = pos;//on change donc la valeur de la taille du tableau

		if (tab->elt == NULL)//si ça a échoué (le tableau devient nul), on arete et on le fait savoir à l'utilisateur
		{
			printf("memoire insuffisante"); return 0;
		}
	}


	if (tab->elt[pos - 1] == 0 && element != 0) {//on n'incremente le nombre d'élements,
		tab->eltsCount++; //que si on a ajouté un élement non nul
	}
	if (tab->elt[pos - 1] != 0 && element == 0) {//on décrémente le nombre d'élements,
		tab->eltsCount--; //si on ajoute un élement nul
	}
	tab->elt[pos - 1] = element;//on ajoute l'élément choisi à la position pos


	return pos;//on renvoie maintenant le tableau modifié

}


int fillTabuntilN(int* tab, int size, int nbElts) {//pour remplir un tableau avec les
	if ((size < 0) || (size < nbElts)) { return NULL; }//valeurs de 1 à n

	for (int i = 0; i < nbElts; i++) {
		tab[i] = i + 1;//ici i+1 car le tableau compte à partir du rang 0 et non 1
	}
}


int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (startPos<0 || endPos<0 || startPos>tab->size || endPos>tab->size) {
		//si les positions ne sont pas comprises dans la taille du tableau
		return -1;
	}
	else {
		if (startPos < endPos) {//si start<end, on affiche ce qu'il y a entre les deux inclus
			for (int i = startPos - 1; i < endPos; i++) {
				printf("%d ", tab->elt[i]);
			}
		}
		else if (startPos == endPos) {//si ils sont égaux on n'affiche que l'element souhaité
			printf("%d ", tab->elt[startPos]);
		}
		else {//si endPos<startPos
			//on affiche de endPos à la fin, puis du  début à startPos
			for (int i = endPos; i < tab->size; i++) {
				printf("%d ", tab->elt[i]);
			}
			for (int i = 0; i < startPos; i++) {
				printf("%d ", tab->elt[i]);
			}
		}
		return 0;
	}
}


int deleteElements(TABLEAU* tab, int startPos, int endPos) {

	if (startPos<0 || endPos<0 || startPos>tab->size || endPos>tab->size) {
		//si les positions ne sont pas comprises dans la taille du tableau
		return -1;
	}

	else {//si la section choisie est comprise dans le tableau

		if (startPos <= endPos) {
			int Delta = 1 + endPos - startPos;//on crée une variable qui vaut la taille de l'intervalle à enlever
			//le +1 est là car on veut aussi supprimer startPos et endPos 
			for (int i = startPos; i <= endPos; i++) {//on cherche dans cet intervalle
				if (tab->elt[i] != 0) {//les valeurs non nulles
					tab->eltsCount--;//pour décrémenter le nombre d'élements correctement
				}
			}

			for (int i = endPos; i < tab->size; i++) {//pour toutes les valeurs après endPos,
				tab->elt[i - Delta] = tab->elt[i];//on les recule de Delta (la taille de l'intervalle)
			}

			tab->size = tab->size - Delta;//la taille du tableau est maintenant diminuée
			int* stocktab = tab->elt;
			tab->elt = (int*)realloc(tab->elt, (tab->size) * sizeof(int));//on réalloue la place nécesssaire

		}

		else {//si endPos<startPos
			//on supprime tout le tableau sauf la partie comprise entre endPos et startPos
			//on commence ici aussi par chercher les valeurs non nulles entre endPos et la fin, et entre le début et startPos

			int Delta = startPos - endPos - 1;//on calcule la taille de l'intervalle
			//le -1 est là car on exclue les bornes de l'intervalle

			for (int i = startPos; i <= tab->size; i++) {//on cherche dans cet intervalle
				if (tab->elt[i] != 0) {//les valeurs non nulles
					tab->eltsCount--;//pour décrémenter le nombre d'élements correctement
				}
			}
			for (int i = 0; i < endPos; i++) {//on cherche dans cet intervalle
				if (tab->elt[i] != 0) {//les valeurs non nulles
					tab->eltsCount--;//pour décrémenter le nombre d'élements correctement
				}
			}

			for (int i = 0; i < Delta; i++) {//pour tous les i compris dans l'intervalle qui restera, bornes exclues
				tab->elt[i] = tab->elt[i + endPos];//leur valeur écrase les premières valeurs du tableau
			}


			tab->size = Delta;//la taille du tableau est maintenant diminuée
			int* stocktab = tab->elt;
			tab->elt = (int*)realloc(tab->elt, (tab->size) * sizeof(int));//on réalloue la place nécesssaire

		}

		return tab->size;
	}
}