#pragma once

/*
	@file fonc_liste.h
	@brief Fonctions utiles au traitement des listes du jeu de Boggle
*/

#include "Liste.h"

/** @brief Conteneur de listes alloué en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension.
 */
struct L_liste {
	/// Capacité du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur alloué en mémoire dynamique.
	Liste* tab;
	/// Nombre de listes stockés dans la liste de listes.
	unsigned int nb;
};

/**
 * @brief Initialiser une liste de listes vide, la liste est allouée en mémoire dynamique.
 * @see detruire_ll, la liste est à désallouer en fin d’utilisation.
 * @param[out] liste_liste La liste à initialiser.
 * @param[in] capa Capacité de la liste.
 * @param[in] pas Pas d’extension de la liste.
 * @pre capa > 0 et pas > 0.
 */
void initialiser_ll(L_liste& liste_liste, unsigned int capa, unsigned int pas);

/**
 * @brief Ecrire une liste dans la liste de listes.
 * @param[in,out] liste_liste La liste de listes dans laquelle écrire.
 * @param[in] i La position où écrire dans la liste de listes.
 * @param[in] l La liste à écrire dans la liste de listes.
 * @pre liste_liste.capacite > 0.
 */
void ecrire_ll(L_liste& liste_liste, unsigned int i, Liste& l);

/**
 * @brief Désallouer une liste de listes.
 * @see initialiser_ll
 * @param[out] liste_liste la liste.
 */
void detruire_ll(L_liste& liste_liste);

/**
 * @brief Trier en ordre alphabétique une liste.
 * @param[out] l La liste à trier.
 * @pre l.nb > 0.
 */
void tri(Liste& l);

/**
 * @brief Retirer les doublons dans une liste 
 * triée en ordre alphabétique une liste.
 * @param[out] l La liste à traiter.
 * @pre l.nb > 0.
 */
void doublon(Liste& l);

/**
 * @brief Saisir des données dans une liste.
 * @param[in,out] l La liste dans laquelle il faut saisir des données.
 * @pre l.nb = 0 et l.c.capacite > 0.
 */
void saisir_liste(Liste& l);

/**
 * @brief Afficher l'ensemble des données stockées dans une liste.
 * @param[in] l La liste à afficher.
 * @pre l.nb > 0.
 */
void afficher(Liste& l);

/**
 * @brief Saisir des données dans une liste de listes.
 * @param[in,out] l_l La liste de listes dans laquelle il faut
 * saisir les données.
 * @pre l_l.nb > 0 et l_l.capacite > 0.
 */
void saisirL_liste(L_liste& l_l);

/**
 * @brief Afficher l'ensemble des données stockées dans une liste,
 * données ayant répondu à un ou un autre critère.
 * @param[in] cas L'entier définissant le mode de fonctionnement 
 * de la fonction
 * @param[in] liste_prio La liste qui servira de liste à traiter pour
 * l'affichage
 * @param[in] liste_pas_prio La liste qui servira de dictionnaire
 * à la liste d'affichage
 * @pre liste_prio.nb > 0 et liste_pas_prio.nb > 0.
 */
void diffliste(int cas, Liste& liste_prio, Liste& liste_pas_prio);

/**
 * @brief Afficher la liste des données devant être exclues du comptage des
 * points car jouées par plus d'un joueur.
 * @param[out] l La liste à insérer 
 * @pre liste_prio.nb > 0 et liste_pas_prio.nb > 0.
 */
void mots_exclus(Liste& l);