/**
 * @file Liste.cpp
 * @brief Composant de liste en mémoire dynamique et extensible
 */
 
#include <cassert> 
#include "Liste.h"

void initialiser(Liste& l, unsigned int capa, unsigned int pas) {
	assert ((capa>0) && (pas>0));
	initialiser(l.c, capa, pas);
	l.nb=0;
}

void ini_list_list(listedeConteneurTDE& liste_liste, unsigned int capa, unsigned int pas) {
	assert((capa > 0) && (pas > 0));
	liste_liste.capacite = capa;
	liste_liste.pasExtension = pas;
	liste_liste.tab = new Liste[capa];
	liste_liste.nb = 0;
	
	for (unsigned int i = 0; i < capa; i++) {
		assert((capa > 0) && (pas > 0));
		initialiser(liste_liste.tab[i].c, capa, pas);
		liste_liste.tab[i].nb = 0;
	}
}


 
void detruire(Liste& l) {
	detruire(l.c);
}

unsigned int longueur(const Liste& l) {
	return l.nb;
}

Item lire(const Liste& l, unsigned int pos) {
	assert(pos<l.nb);
	return lire(l.c, pos);
}

void ecrire(Liste& l, unsigned int pos, const Item& it) {
	assert(pos<l.nb);
	ecrire(l.c, pos, it);
}	

void ecrire_list_list(listedeConteneurTDE& liste_liste, unsigned int i, Liste& l) {
	if (i >= liste_liste.capacite) {
		unsigned int newTaille = (i + 1) * liste_liste.pasExtension;
		Liste* newT = new Liste[newTaille];
		for (unsigned int i = 0; i < liste_liste.capacite; ++i)
			newT[i] = liste_liste.tab[i];
		delete[] liste_liste.tab;
		liste_liste.tab = newT;
		
		for (unsigned int k = liste_liste.capacite; k < newTaille; k++) {
			assert((liste_liste.capacite > 0) && (liste_liste.pasExtension > 0));
			initialiser(liste_liste.tab[k].c, 2, 2);
			liste_liste.tab[k].nb = 0;
		}
		liste_liste.capacite = newTaille;
	}

	for (unsigned int j = 0; j < longueur(l); j++) {
		inserer(liste_liste.tab[i], j, lire(l, j));
	}

	liste_liste.nb++;
}

void inserer(Liste& l, unsigned int pos, const Item& it) {
	assert(pos<=l.nb);
	for (unsigned int i=l.nb; i>pos; i--) {
		ecrire(l.c, i, lire(l.c, i-1));
	}
	ecrire(l.c, pos, it);
	l.nb++;
}

void supprimer(Liste& l, unsigned int pos) {
	assert((l.nb!=0) && (pos<l.nb));
	l.nb--;
	for (unsigned int i=pos; i<l.nb; ++i)
	   ecrire(l.c, i, lire(l.c,i+1));
}
