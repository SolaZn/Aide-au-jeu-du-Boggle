#include <iostream>
#include <cassert>
using namespace std;

#include "conteneurs/Liste.h"

// Nous vous imposons de r�unir les 6 programmes du projet de sda dans 
// un unique projet Visual. Ceci doit vous permettre de partager du code 
// entre les programmes sans difficult�.

// Le programme qui suit montre l'architecture g�n�rale que nous proposons.

// A chaque programme correspond une fonction ne prenant aucun param�tre et 
// ne retournant rien (les fonctions exo1, exo2, etc ci-dessous). Rien ne 
// vous emp�che de r�partir ces fonctions dans plusieurs fichiers .cpp.

// Le main donn� ci-dessous aiguille l'ex�cution en fonction d'une valeur 
// enti�re lue au clavier 

// Il est possible de lancer le programme avec les fichiers d'entr�e fournis 
// sans pour autant en modifier le contenu.
//
// 1 - L'ex�cutable est suppos� s'appeler Boggle_SDA.exe (� adapter selon 
// le nom de votre projet).
// 2 - Dans l'invite de commande, vous devez vous placer dans le r�pertoire 
// contenant votre ex�cutable (commande cd).
// 3 - Les fichiers inXX.txt sont suppos�s �tre dans le m�me r�pertoire que 
// l'ex�cutable.
//
// La commande lance le programme ci-dessous pour l'exercice 1 :
// (echo 1 & type in1-2.txt) | Boggle_SDA.exe
//
// Pour l'exercice 2, cela donne : 
// (echo 2 & type in1-2.txt) | Boggle_SDA.exe


void echanger(Liste& l, unsigned int i, unsigned int j) {
	assert(i >= 0 && j < l.nb);
	char* aux = lire(l, i); // T type des �l�ments de liste
	ecrire(l, i, lire(l, j));
	ecrire(l, j, aux);
}

void tri(Liste& l) {
	Item tmp;
	for (unsigned int i = 0; i < longueur(l) - 1; i++) {
		for(unsigned int j = i; j < longueur(l) - 1; j++) {
			if (strcmp(lire(l, i), lire(l, j)) > 0) {
				tmp = lire(l, i);
				ecrire(l, i, lire(l, j));
				ecrire(l, j, tmp);
			}
		}
	}
}

void doublon(Liste& l) {
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

void agregliste(int cas, Liste& liste_prio, Liste& liste_pas_prio) {
	// coder la m�me fonction pour le 3 en parcourant la liste du d�but � la fin pour v�rifier si un mot correspond,
	// auquel cas ils n'apparaissent pas dans la premi�re
	if (cas == 0) {
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

	if (cas == 1) {
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

void lire_listedeliste(Liste& l) {
		// concevoir un algo qui lis une liste de liste
	/*
		on aura besoin de : conna�tre le nombre de liste ? (stock� dans nb ?) l.nb ?
							de conna�tre la longueur de chacune d'entre elles
							de les comparer toutes les unes entre elles en m�me temps pour savoir si il faut �crire
							faire en sorte que l'algo de recherche n'affiche le mot que si il a �t� trouv� deux fois ou plus dans toutes les listes
	*/
}

void saisir() {
	// id�e de fonction qui remplirait elle m�me les listes de liste ou alors permettrait de pouvoir faire des listes
}

void exo1() {
	bool flux_ouvert = true;
	char buffer[35]; // chaine de caractere a remplir
	int nb_points = 0;

	do {
		cin >> buffer; // on remplis la chaine de caractere
		if (strcmp(buffer, "*") == 0) { // si le caract�re de fin est tap�
			flux_ouvert = false; // on arr�te l'�criture
		}
		else {
			switch (strlen(buffer)){ // on v�rifie la longueur de la chaine // faire une fct
				case 0:
				case 1:
				case 2: 
					break;
				case 3:
				case 4:
					nb_points++;
					break;
				case 5:
					nb_points += 2;
					break;
				case 6: 
					nb_points += 3;
					break;
				case 7: 
					nb_points += 5;
					break;
				default: 
					nb_points += 11;	
			}
		}
	} while (flux_ouvert == true); // tant que le "flux" est ouvert -> tant qu'on �crit
	
	cout << nb_points << endl;
}

void exo2() {
	Liste liste_mots;
	bool flux_ouvert = true;
	initialiser(liste_mots, 1, 2);

	do {
		char* buffer = new char[35]; // essayer de s'en d�barasser
		
		cin >> buffer; // on remplis la chaine de caractere
		if (strcmp(buffer, "*") == 0) { // si le caract�re de fin est tap�
			inserer(liste_mots, longueur(liste_mots), buffer);
			flux_ouvert = false; // on arr�te l'�criture
		}
		else {
			inserer(liste_mots, longueur(liste_mots), buffer);
		}

		if (flux_ouvert == false) {

			doublon(liste_mots);
			tri(liste_mots);

			for (unsigned int i = 0; i < longueur(liste_mots); i++) {
				cout << lire(liste_mots, i) << endl;
			}

			delete[] buffer;
		}

	} while (flux_ouvert == true); // tant que le "flux" est ouvert -> tant qu'on �crit				   

	detruire(liste_mots);
}

void exo3() {
	Liste liste_dico;
	initialiser(liste_dico, 1, 2);
	bool flux_ouvert = true;

	do {
		char* buffer = new char[35];
		cin >> buffer; // on remplis la chaine de caractere

		if (strcmp(buffer, "*") == 0) { // si le caract�re de fin est tap�
			inserer(liste_dico, longueur(liste_dico), buffer);
			flux_ouvert = false; // on arr�te l'�criture
		}
		else {
			inserer(liste_dico, longueur(liste_dico), buffer);
		}
	} while (flux_ouvert == true);
	
	doublon(liste_dico);
	tri(liste_dico);

	Liste liste_affichee;
	initialiser(liste_affichee, 1, 2);
	flux_ouvert = true;

	do {
		char* buffer = new char[35];
		cin >> buffer; // on remplis la chaine de caractere

		if (strcmp(buffer, "*") == 0) { // si le caract�re de fin est tap�
			inserer(liste_affichee, longueur(liste_affichee), buffer);
			flux_ouvert = false; // on arr�te l'�criture
		}
		else {
			inserer(liste_affichee, longueur(liste_affichee), buffer);
		}
	} while (flux_ouvert == true);

	doublon(liste_affichee);
	tri(liste_affichee);

	agregliste(0, liste_affichee, liste_dico);
	detruire(liste_affichee);
	detruire(liste_dico);
}

void exo4() {
	Liste liste_dico;
	initialiser(liste_dico, 1, 2);
	bool flux_ouvert = true;

	do {
		char* buffer = new char[35];
		cin >> buffer; // on remplis la chaine de caractere

		if (strcmp(buffer, "*") == 0) { // si le caract�re de fin est tap�
			inserer(liste_dico, longueur(liste_dico), buffer);
			flux_ouvert = false; // on arr�te l'�criture
		}
		else {
			inserer(liste_dico, longueur(liste_dico), buffer);
		}
	} while (flux_ouvert == true);

	Liste liste_affichee;
	initialiser(liste_affichee, 1, 2);
	flux_ouvert = true;

	do {
		char* buffer = new char[35];
		cin >> buffer; // on remplis la chaine de caractere

		if (strcmp(buffer, "*") == 0) { // si le caract�re de fin est tap�
			inserer(liste_affichee, longueur(liste_affichee), buffer);
			flux_ouvert = false; // on arr�te l'�criture
		}
		else {
			inserer(liste_affichee, longueur(liste_affichee), buffer);
		}
	} while (flux_ouvert == true);

	doublon(liste_affichee);
	tri(liste_affichee);

	agregliste(1, liste_affichee, liste_dico);
	detruire(liste_affichee);
	detruire(liste_dico);
}

void exo5() {
	listedeConteneurTDE liste_de_listes ;
	// trouver un moyen d'initialiser un liste* en codant de nouvelles fonctions dans l'ent�te Liste (ne pas oublier le brief)
		// s'inspirer de celles fonctionnant d�j� pour les listes char* (Liste* donne char**, donc un tableau de pointeurs vers des tableaux de char)
		// il faut quelque chose d'extensible tout comme les listes
		// peut �tre aussi recoder les fonctions d'insertion pour permettre de copier la valeur au lieu d'utiliser l'adresse point�e
	ini_list_list(liste_de_listes, 2, 2);
	bool flux_principal = true;
	
	for (unsigned int i = 0;; i++) {
		Liste liste_rentree;
		initialiser(liste_rentree, 1, 2);
		bool flux_ouvert = true;

		do {
			char* buffer = new char[35];
			cin >> buffer; // on remplis la chaine de caractere

			if (strcmp(buffer, "*") == 0) { // si le caract�re de fin est tap�
				inserer(liste_rentree, longueur(liste_rentree), buffer);
				flux_ouvert = false; // on arr�te l'�criture
			}
			else {
				inserer(liste_rentree, longueur(liste_rentree), buffer);
			}
		} while (flux_ouvert == true);

		ecrire_list_list(liste_de_listes, i, liste_rentree);
		if (longueur(liste_rentree) == 1) {
			break;
		}
	}

	for (unsigned int i = 0; i < liste_de_listes.nb; i++) {
		for (unsigned int j = 0; j < longueur(liste_de_listes.tab[i]); j++) {
			// parcourir les listes en les utilisant comme dico une � une
			// si un mot appara�t dann plus de deux listes, on l'affiche
			// bien comparer les 5 listes pour chaque mot
			// peut �tre construire une liste qui r�cup�rerait tous les mots affich�s plus de deux fois
			cout << lire(liste_de_listes.tab[i], j) << endl;
		}
	}
}

void exo6() {
	cout << "sixieme pgm" << endl;
}

int main() {
	int num;
	cin >> num;
	switch (num) {
	case 1:
		exo1(); break; // correspond au main du premier programme
	case 2:
		exo2(); break; // correspond au main du second programme 
	case 3:
		exo3(); break;
	case 4:
		exo4(); break;
	case 5:
		exo5(); break;
	case 6:
		exo6(); break;
	}
}
