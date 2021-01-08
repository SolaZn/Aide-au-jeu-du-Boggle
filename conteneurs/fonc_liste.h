#pragma once

/*
	@file fonc_liste.h
	@brief Fonctions utiles au traitement des listes du jeu de Boggle
*/

#include "Liste.h"

/** @brief Conteneur de listes allou� en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension.
 */
struct L_liste {
	/// Capacit� du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur allou� en m�moire dynamique.
	Liste* tab;
	/// Nombre de listes stock�s dans la liste de listes.
	unsigned int nb;
};

/**
 * @brief Initialiser une liste de listes vide, la liste est allou�e en m�moire dynamique.
 * @see detruire_ll, la liste est � d�sallouer en fin d�utilisation.
 * @param[out] liste_liste La liste � initialiser.
 * @param[in] capa Capacit� de la liste.
 * @param[in] pas Pas d�extension de la liste.
 * @pre capa > 0 et pas > 0.
 */
void initialiser_ll(L_liste& liste_liste, unsigned int capa, unsigned int pas);

/**
 * @brief Ecrire une liste dans la liste de listes.
 * @param[in,out] liste_liste La liste de listes dans laquelle �crire.
 * @param[in] i La position o� �crire dans la liste de listes.
 * @param[in] l La liste � �crire dans la liste de listes.
 * @pre liste_liste.capacite > 0.
 */
void ecrire_ll(L_liste& liste_liste, unsigned int i, Liste& l);

/**
 * @brief D�sallouer une liste de listes.
 * @see initialiser_ll
 * @param[out] liste_liste la liste.
 */
void detruire_ll(L_liste& liste_liste);

/**
 * @brief Trier en ordre alphab�tique une liste.
 * @param[out] l La liste � trier.
 * @pre l.nb > 0.
 */
void tri(Liste& l);

/**
 * @brief Retirer les doublons dans une liste 
 * tri�e en ordre alphab�tique une liste.
 * @param[out] l La liste � traiter.
 * @pre l.nb > 0.
 */
void doublon(Liste& l);

/**
 * @brief Saisir des donn�es dans une liste.
 * @param[in,out] l La liste dans laquelle il faut saisir des donn�es.
 * @pre l.nb = 0 et l.c.capacite > 0.
 */
void saisir_liste(Liste& l);

/**
 * @brief Afficher l'ensemble des donn�es stock�es dans une liste.
 * @param[in] l La liste � afficher.
 * @pre l.nb > 0.
 */
void afficher(Liste& l);

/**
 * @brief Saisir des donn�es dans une liste de listes.
 * @param[in,out] l_l La liste de listes dans laquelle il faut
 * saisir les donn�es.
 * @pre l_l.nb > 0 et l_l.capacite > 0.
 */
void saisirL_liste(L_liste& l_l);

/**
 * @brief Afficher l'ensemble des donn�es stock�es dans une liste,
 * donn�es ayant r�pondu � un ou un autre crit�re.
 * @param[in] cas L'entier d�finissant le mode de fonctionnement 
 * de la fonction
 * @param[in] liste_prio La liste qui servira de liste � traiter pour
 * l'affichage
 * @param[in] liste_pas_prio La liste qui servira de dictionnaire
 * � la liste d'affichage
 * @pre liste_prio.nb > 0 et liste_pas_prio.nb > 0.
 */
void diffliste(int cas, Liste& liste_prio, Liste& liste_pas_prio);

/**
 * @brief Afficher la liste des donn�es devant �tre exclues du comptage des
 * points car jou�es par plus d'un joueur.
 * @param[out] l La liste � ins�rer 
 * @pre liste_prio.nb > 0 et liste_pas_prio.nb > 0.
 */
void mots_exclus(Liste& l);