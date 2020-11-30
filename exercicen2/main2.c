#include"tab2.h"


int main() {

	TABLEAU firstTab;

	firstTab = newArray();


	incrementArraySize(&firstTab, 20);

	init(firstTab.elt, firstTab.size);

	for (int i = 0; i < firstTab.size; i++) {
		firstTab.elt[i] = i + 1;
		firstTab.eltsCount++;
	}

	setElement(&firstTab, 20, 6);
	setElement(&firstTab, 12, 0);
	setElement(&firstTab, 16, 8);

	deleteElements(&firstTab, 24, 17);

	displayElements(&firstTab, 1, firstTab.size);
	

	printf("\n\nla taille du tableau est: %d\n\nil y a %d elements\n\n", firstTab.size, firstTab.eltsCount);





	return EXIT_SUCCESS;
}