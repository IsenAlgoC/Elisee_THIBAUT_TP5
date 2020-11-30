#include"tab2.h"



int init(int* tab, int size) {
	if (size < 0) { return-1; }//on n'effectue pas la fonction si la taille est n�gative

	for (int i = 0; i < size; i++) {
		tab[i] = 0;//toutes les valeurs du tableau devienent nulles
	}

}


TABLEAU newArray() {//on cr�e une fonction sans arguments, afin de pouvoir cr�er un TABLEAU depuis rien
	TABLEAU tab;//on cr�e donc un TABLEAU dans la fonction

	tab.elt = NULL;//on initialise le tableau en NULL

	tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	if (tab.elt != NULL) { init(tab.elt, TAILLEINITIALE); }
	else { printf("m�moire insuffisante"); }//on lui alloue de la place si possible, comme dans l'exo 1

	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;//on termine par compl�ter le TABLEAU, avec les 2 champs manquants
	return tab;//on renvoie le tableau
}


int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int* stocktab;//on cr�e un tableau de stockage, pour garder tab.elt, au cas ou un accident se produit
	stocktab = tab->elt;
	int incr = tab->size + incrementValue;
	tab->elt = (int*)realloc(tab->elt, (incr) * sizeof(int));//on r�alloue de l'espace

	if (tab->elt == NULL) {
		printf("erreur de reallocation");
		return-1;
	}//si l'allocation a �chou�, on le fait savoir

	else {
		tab->size = tab->size + incrementValue;//on modifie la valeur de la taille
		return tab->size;
	}
}


int afficheTab(int* tab, int size, int nbElts) {
	if ((size < 0) || (size < nbElts)) { return -1; }//on ne montre pas le tableau si on n'a pas de bonnes conditions

	for (int i = 0; i < nbElts; i++) {//on affiche tous les nombres plac�s aux rangs i se succ�dants du tableau
		printf("%d ", tab[i]);
	}
}
    /// \\\
   /// | \\\
  ///  |  \\\
 ///   |   \\\
///    o    \\\
===============
//pour les fonctions setElement, displayElements and deleteElement, le premier �lement consid�r� est l'�lement 1 et non 0
//pour afficher, placer ou supprimer un �lement, on ne peut pas commence � 0

int setElement(TABLEAU* tab, int pos, int element) {

	int* tab2 = NULL;


	if (tab->size <= pos) {//on r�alloue de l'espace au tableau si la taille est insuffisante

		tab2 = tab->elt;//on stocke le tableau dans un autre, pour �viter d'avoir des erreurs et de le perdre

		tab->elt = (int*)realloc(tab->elt, (pos) * sizeof(int));//on le r�aloue avec au moins la taille de la position

		if (tab->elt != NULL) {//si la r�allocation est un succ�s
			for (int i = tab->size; i < pos; i++) {//on initialise la partie qui vient d'�tre cr��e
				tab->elt[i] = 0;
			}
		}
		tab->size = pos;//on change donc la valeur de la taille du tableau

		if (tab->elt == NULL)//si �a a �chou� (le tableau devient nul), on arete et on le fait savoir � l'utilisateur
		{
			printf("memoire insuffisante"); return 0;
		}
	}


	if (tab->elt[pos - 1] == 0 && element != 0) {//on n'incremente le nombre d'�lements,
		tab->eltsCount++; //que si on a ajout� un �lement non nul
	}
	if (tab->elt[pos - 1] != 0 && element == 0) {//on d�cr�mente le nombre d'�lements,
		tab->eltsCount--; //si on ajoute un �lement nul
	}
	tab->elt[pos - 1] = element;//on ajoute l'�l�ment choisi � la position pos


	return pos;//on renvoie maintenant le tableau modifi�

}


int fillTabuntilN(int* tab, int size, int nbElts) {//pour remplir un tableau avec les
	if ((size < 0) || (size < nbElts)) { return NULL; }//valeurs de 1 � n

	for (int i = 0; i < nbElts; i++) {
		tab[i] = i + 1;//ici i+1 car le tableau compte � partir du rang 0 et non 1
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
		else if (startPos == endPos) {//si ils sont �gaux on n'affiche que l'element souhait�
			printf("%d ", tab->elt[startPos]);
		}
		else {//si endPos<startPos
			//on affiche de endPos � la fin, puis du  d�but � startPos
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
			int Delta = 1 + endPos - startPos;//on cr�e une variable qui vaut la taille de l'intervalle � enlever
			//le +1 est l� car on veut aussi supprimer startPos et endPos 
			for (int i = startPos; i <= endPos; i++) {//on cherche dans cet intervalle
				if (tab->elt[i] != 0) {//les valeurs non nulles
					tab->eltsCount--;//pour d�cr�menter le nombre d'�lements correctement
				}
			}

			for (int i = endPos; i < tab->size; i++) {//pour toutes les valeurs apr�s endPos,
				tab->elt[i - Delta] = tab->elt[i];//on les recule de Delta (la taille de l'intervalle)
			}

			tab->size = tab->size - Delta;//la taille du tableau est maintenant diminu�e
			int* stocktab = tab->elt;
			tab->elt = (int*)realloc(tab->elt, (tab->size) * sizeof(int));//on r�alloue la place n�cesssaire

		}

		else {//si endPos<startPos
			//on supprime tout le tableau sauf la partie comprise entre endPos et startPos
			//on commence ici aussi par chercher les valeurs non nulles entre endPos et la fin, et entre le d�but et startPos

			int Delta = startPos - endPos - 1;//on calcule la taille de l'intervalle
			//le -1 est l� car on exclue les bornes de l'intervalle

			for (int i = startPos; i <= tab->size; i++) {//on cherche dans cet intervalle
				if (tab->elt[i] != 0) {//les valeurs non nulles
					tab->eltsCount--;//pour d�cr�menter le nombre d'�lements correctement
				}
			}
			for (int i = 0; i < endPos; i++) {//on cherche dans cet intervalle
				if (tab->elt[i] != 0) {//les valeurs non nulles
					tab->eltsCount--;//pour d�cr�menter le nombre d'�lements correctement
				}
			}

			for (int i = 0; i < Delta; i++) {//pour tous les i compris dans l'intervalle qui restera, bornes exclues
				tab->elt[i] = tab->elt[i + endPos];//leur valeur �crase les premi�res valeurs du tableau
			}


			tab->size = Delta;//la taille du tableau est maintenant diminu�e
			int* stocktab = tab->elt;
			tab->elt = (int*)realloc(tab->elt, (tab->size) * sizeof(int));//on r�alloue la place n�cesssaire

		}

		return tab->size;
	}
}