/**
* SDA Projet période B : Rapport de projet sur la conception d’un programme dédié au jeu du « Boggle »
* Auteurs : Anthony ZAKANI et Mehdi ZAOUI
*	dans le cadre d'un DUT Informatique au sein de l'Université de Paris
* Sur la base d'un code source issu de l'équipe pédagogique de l'IUT de Paris-Rives de Seine,
* membre de l'Université de Paris.
* Dernière mise à jour : vendredi 8 janvier 2021 à 22h46
*/

#include <iostream>
#include <cassert>
using namespace std;

#include "conteneurs/fonc_liste.h"

// Nous vous imposons de réunir les 6 programmes du projet de sda dans 
// un unique projet Visual. Ceci doit vous permettre de partager du code 
// entre les programmes sans difficulté.

// Le programme qui suit montre l'architecture générale que nous proposons.

// A chaque programme correspond une fonction ne prenant aucun paramètre et 
// ne retournant rien (les fonctions exo1, exo2, etc ci-dessous). Rien ne 
// vous empêche de répartir ces fonctions dans plusieurs fichiers .cpp.

// Le main donné ci-dessous aiguille l'exécution en fonction d'une valeur 
// entière lue au clavier 

// Il est possible de lancer le programme avec les fichiers d'entrée fournis 
// sans pour autant en modifier le contenu.
//
// 1 - L'exécutable est supposé s'appeler Boggle_SDA.exe (à adapter selon 
// le nom de votre projet).
// 2 - Dans l'invite de commande, vous devez vous placer dans le répertoire 
// contenant votre exécutable (commande cd).
// 3 - Les fichiers inXX.txt sont supposés être dans le même répertoire que 
// l'exécutable.
//
// La commande lance le programme ci-dessous pour l'exercice 1 :
// (echo 1 & type in1-2.txt) | Boggle_SDA.exe
//
// Pour l'exercice 2, cela donne : 
// (echo 2 & type in1-2.txt) | Boggle_SDA.exe


void exo1() {
	bool flux_ouvert = true;
	char buffer[35]; // chaine de caractere a remplir
	int nb_points = 0;

	do {
		cin >> buffer; // on remplis la chaine de caractere
		if (strcmp(buffer, "*") == 0) { // si le caractère de fin est tapé
			flux_ouvert = false; // on arrête l'écriture
		}
		else {
			switch (strlen(buffer)){ // on vérifie la longueur de la chaine // faire une fct
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
	} while (flux_ouvert == true); // tant que le "flux" est ouvert -> tant qu'on écrit
	
	cout << nb_points << endl;
}

void exo2() {
	Liste liste_mots;
	bool flux_ouvert = true;
	initialiser(liste_mots, 1, 2);

	saisir_liste(liste_mots);

	doublon(liste_mots);
	tri(liste_mots);

	afficher(liste_mots);

	detruire(liste_mots);
}

void exo3() {
	Liste liste_dico;
	initialiser(liste_dico, 1, 2);

	saisir_liste(liste_dico);
	
	doublon(liste_dico);
	tri(liste_dico);

	Liste liste_affichee;
	initialiser(liste_affichee, 1, 2);

	saisir_liste(liste_affichee);

	doublon(liste_affichee);
	tri(liste_affichee);

	diffliste(0, liste_affichee, liste_dico);

	detruire(liste_affichee);
	detruire(liste_dico);
}

void exo4() {
	Liste liste_dico;
	initialiser(liste_dico, 1, 2);

	saisir_liste(liste_dico);

	Liste liste_affichee;
	initialiser(liste_affichee, 1, 2);

	saisir_liste(liste_affichee);

	doublon(liste_affichee);
	tri(liste_affichee);

	diffliste(1, liste_affichee, liste_dico);

	detruire(liste_affichee);
	detruire(liste_dico);
}

void exo5() {
	// trouver un moyen d'initialiser un liste* en codant de nouvelles fonctions dans l'entête Liste (ne pas oublier le brief)
		// s'inspirer de celles fonctionnant déjà pour les listes char* (Liste* donne char**, donc un tableau de pointeurs vers des tableaux de char)
		// il faut quelque chose d'extensible tout comme les listes
		// peut être aussi recoder les fonctions d'insertion pour permettre de copier la valeur au lieu d'utiliser l'adresse pointée
	L_liste liste_de_listes ;
	initialiser_ll(liste_de_listes, 2, 2);
	
	saisirL_liste(liste_de_listes);

	Liste liste_agregee;
	initialiser(liste_agregee, 1, 2);

	for (unsigned int i = 0; i < liste_de_listes.nb; i++) {
		for (unsigned int j = 0; j < longueur(liste_de_listes.tab[i]); j++) {
			inserer(liste_agregee, j, liste_de_listes.tab[i].c.tab[j]);
		}
	}

	tri(liste_agregee);
	mots_exclus(liste_agregee);

	detruire_ll(liste_de_listes);
	detruire(liste_agregee);
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
