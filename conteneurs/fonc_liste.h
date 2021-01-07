#pragma once

/*
	@file fonc_liste.h
	@brief Fonctions utiles au traitement des listes du jeu de Boggle
*/

void tri(Liste& l);

void doublon(Liste& l);

void saisir_liste(Liste& l);

void saisirL_liste(L_liste& l_l);

void diffliste(int cas, Liste& liste_prio, Liste& liste_pas_prio);

void mots_exclus(Liste& l);