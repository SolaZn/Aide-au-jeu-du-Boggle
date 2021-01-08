/*
	@file fonc_liste.cpp
	@brief Fonctions utiles au traitement des listes du jeu de Boggle
*/

#include <iostream>
#include <cassert>
using namespace std;

#include "fonc_liste.h"

void initialiser_ll(L_liste& liste_liste, unsigned int capa, unsigned int pas) {
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

void ecrire_ll(L_liste& liste_liste, unsigned int i, Liste& l) {
	assert(liste_liste.capacite > 0);
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

void detruire_ll(L_liste& liste_liste) {
	for (unsigned int k = 0; k < liste_liste.nb; k++) {
		for (unsigned int h = 0; h < liste_liste.tab[k].nb; h++) {
			delete[] liste_liste.tab[k].c.tab[h];
		}
		detruire(liste_liste.tab[k]);
	}

	delete[] liste_liste.tab;
	liste_liste.tab = NULL;
}

void tri(Liste& l) {
	assert(l.nb > 0);
	Item tmp;
	for (unsigned int i = 0; i < longueur(l) - 1; i++) {
		for (unsigned int j = i; j < longueur(l) - 1; j++) {
			if (strcmp(lire(l, i), lire(l, j)) > 0) {
				tmp = lire(l, i);
				ecrire(l, i, lire(l, j));
				ecrire(l, j, tmp);
			}
		}
	}
}

void doublon(Liste& l) {
	assert(l.nb > 0);
	Liste l2;
	initialiser(l2, l.c.capacite, l.c.pasExtension);
	for (unsigned int i = 0; i < longueur(l); i++) {
		inserer(l2, i, lire(l, i));
	}
	for (unsigned int i = 0; i < longueur(l); i++) {
		for (unsigned int j = 0; j < longueur(l2); j++) {
			if (i != j) {
				if (strcmp(lire(l, i), lire(l2, j)) == 0) {
					supprimer(l, j);
					supprimer(l2, j);
				}
			}
		}
	}

	detruire(l2);
}

void saisir_liste(Liste& l) {
	assert(l.nb == 0);
	assert(l.c.capacite > 0);
	bool flux_ouvert = true;

	do {
		char* buffer = new char[35]; //delete ?
		cin >> buffer; // on remplis la chaine de caractere

		if (strcmp(buffer, "*") == 0) { // si le caractère de fin est tapé
			inserer(l, longueur(l), buffer);
			flux_ouvert = false; // on arrête l'écriture
		}
		else {
			inserer(l, longueur(l), buffer);
		}
	} while (flux_ouvert == true);
}

void afficher(Liste& l) {
	assert(l.nb > 0);
	for (unsigned int i = 0; i < longueur(l); i++) {
		cout << lire(l, i) << endl;
	}
}

void saisirL_liste(L_liste& l_l) {
	assert(l_l.capacite > 0);
	assert(l_l.nb == 0);
	for (unsigned int i = 0;; i++) {
		Liste liste_rentree;
		initialiser(liste_rentree, 1, 2);

		saisir_liste(liste_rentree);

		doublon(liste_rentree);
		ecrire_ll(l_l, i, liste_rentree);

		if (longueur(liste_rentree) == 1) {
			break;
		}
	}
}

void diffliste(int cas, Liste& liste_prio, Liste& liste_pas_prio) {
	// coder la même fonction pour le 3 en parcourant la liste du début à la fin pour vérifier si un mot correspond,
	// auquel cas ils n'apparaissent pas dans la première
	assert(liste_prio.nb > 0);
	assert(liste_pas_prio.nb > 0);
	if (cas == 0) { // afficher les données de la première liste ne faisant pas partie de la seconde liste
		for (unsigned int h = 0; h < longueur(liste_prio); h++) {
			int mot_trouve = 0;
			for (unsigned int i = 0; i < longueur(liste_pas_prio); i++) {
				if (strcmp(lire(liste_prio, h), lire(liste_pas_prio, i)) == 0) {
					mot_trouve++;
					break;
				}
			}
			if (mot_trouve == 0) {
				cout << lire(liste_prio, h) << endl;
			}
		}
		cout << "*" << endl;
	}

	if (cas == 1) { // afficher les données faisant partie des deux listes 
		for (unsigned int i = 0; i < longueur(liste_prio); i++) {
			for (unsigned int j = 0; j < longueur(liste_pas_prio); j++) {
				if (strcmp(lire(liste_prio, i), lire(liste_pas_prio, j)) == 0) {
					cout << lire(liste_prio, i) << endl;
					break;
				}
			}
		}
	}
}

/*void lire_listedeliste(Liste& l) {
	// concevoir un algo qui lis une liste de liste
	on aura besoin de : connaître le nombre de liste ? (stocké dans nb ?) l.nb ?
						de connaître la longueur de chacune d'entre elles
						de les comparer toutes les unes entre elles en même temps pour savoir si il faut écrire
						faire en sorte que l'algo de recherche n'affiche le mot que si il a été trouvé deux fois ou plus dans toutes les listes

}*/

void mots_exclus(Liste& l) {
	assert(l.nb > 0);
	int mot_ecrit = 0;
	for (unsigned int k = 1; k < longueur(l); k++) {
		if (strcmp(lire(l, k - 1), lire(l, k)) == 0) {
			if (mot_ecrit == 0) {
				if (strcmp(lire(l, k), "*") != 0) {
					cout << lire(l, k) << endl;
					mot_ecrit = 1;
				}
			}
		}
		else
			mot_ecrit = 0;
		if (k == longueur(l) - 1) {
			cout << "*";
		}
	}
}