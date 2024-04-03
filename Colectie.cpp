#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>
#pragma
using namespace std;

/*
 * Best Case = Average Case = Worst Case
 * Complexitate timp: O(1)
 * Complexitate spatiu: O(1)
 */
Colectie::Colectie() {
	/*
	Creeaza o colectie
	*/
	lg = 0;
	cp = 200001;
	frecventa = new int[cp] {0};
}


/*
 * Best Case: O(1) - daca elementul exista in mijlocul vectorului(<maxi m>mini)
 * Average Case: O(lg^2) - daca exista sau trebuie adaugat intre inceput-mijloc sau intre mijloc-sfarsit
 * Worst Case: O(lg^2) - daca exista sau trebuie adaugat la inceput/sfarsit
 * Complexitate Timp: O(lg^2)
 */

void Colectie::adauga(TElem elem) {
	if (elem >= maxi) {
		maxi = elem;
		lg = maxi - mini + 1;
		int* copie_frecventa = new int[lg] {0};
		copie_frecventa = frecventa;
		frecventa = copie_frecventa;
		frecventa[lg - 1]++ ;
	}
	else if (elem <= mini) {
		int old_mini = mini;
		mini = elem;
		lg = maxi - mini + 1;
		int* copie_frecventa = new int[lg] {0};
		copie_frecventa = frecventa;
		for (int i = 0; i < abs(mini) - abs(old_mini); i++)
			for (int j = lg - 1; j > 0; j--)
				copie_frecventa[j] = copie_frecventa[j - 1];
		for (int i = 0; i < abs(mini) - abs(old_mini); i++) 
			copie_frecventa[i] = 0;
		frecventa = copie_frecventa;
		frecventa[0] ++;
	}
	else {
		if(mini < 0)
			frecventa[elem - mini]++;
		else 
			frecventa[elem + mini]++;
	}
	//printf("Mini: %d Maxi: %d", mini, maxi);
	//for (int i = 0; i < lg; i++)
	//	printf("%d ", frecventa[i]);
	//printf("\n");
}

/*
	Complexitate Timp: O(x)
*/
void Colectie::adauga_element_de_x_ori(TElem element,int x) {
	for (int i = 0; i < x; i++)
		adauga(element);
}

/*
	Complexitate Timp: O(1)
*/
bool Colectie::sterge(TElem elem) {
	if (elem <= maxi && elem >= mini) {
		if (mini < 0 && frecventa[elem - mini] != 0) {
			frecventa[elem - mini]--;
			return true;  
		}
		else if (mini >= 0 && frecventa[elem + mini] != 0) {
			frecventa[elem + mini]--;
			return true;
		}
	}
	return false;
}


bool Colectie::cauta(TElem elem) const {
	if (elem <= maxi && elem >= mini) {
		if (mini < 0 && frecventa[elem - mini] != 0)
			return true;
		else if (mini >= 0 && frecventa[elem + mini] != 0)
			return true;
	}
	return false;
}

/*
Complexitate Timp: O(1)
*/
int Colectie::nrAparitii(TElem elem) const {
	if(elem <= maxi && elem >= mini) {
		if (mini < 0)
			return frecventa[elem - mini];
		else
			return frecventa[elem + mini];
	}
	return 0;
}

/*
Complexitate Timp: O(lg)
*/
int Colectie::dim() const {
	int suma = 0;
	for (int elem = mini; elem <= maxi; elem++) {
		if (mini < 0)
			suma += frecventa[elem - mini];
		else if (mini >= 0)
			suma += frecventa[elem + mini];
	}

	return suma;
}

/*
Complexitate Timp: O(1)
*/
bool Colectie::vida() const {
	if (lg == 0)
		return true;
	return false;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

/*
Complexitate Timp: O(1)
*/
Colectie::~Colectie() {
	lg = -1;
	cp = -1;
	free(frecventa);
	mini = 0, maxi = 0;
}


