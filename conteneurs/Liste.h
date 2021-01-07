#pragma once

/**
 * @file Liste.h
 * @brief Composant de liste en m�moire dynamique et extensible.
 */

#include "ConteneurTDE.h"

struct Liste {
	/// Conteneur m�morisant les �l�ments de la liste.
	ConteneurTDE c;
	/// Nombre d'�l�ments stock�s dans la liste.
    unsigned int nb;	
};

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
 * @brief Initialiser une liste vide, la liste est allou�e en m�moire dynamique.
 * @see detruire, la liste est � d�sallouer en fin d�utilisation.
 * @param[out] l La liste � initialiser.
 * @param[in] capa Capacit� de la liste.
 * @param[in] pas Pas d�extension de la liste.
 * @pre capa > 0 et pas > 0.
 */
void initialiser(Liste& l, unsigned int capa, unsigned int pas);


/**
 * @brief Initialiser une liste vide, la liste est allou�e en m�moire dynamique.
 * @see detruire, la liste est � d�sallouer en fin d�utilisation.
 * @param[out] l La liste � initialiser.
 * @param[in] capa Capacit� de la liste.
 * @param[in] pas Pas d�extension de la liste.
 * @pre capa > 0 et pas > 0.
 */
void initialiser_ll(L_liste& liste_liste, unsigned int capa, unsigned int pas);

void ecrire_ll(L_liste& liste_liste, unsigned int i, Liste& l);

void detruire_ll(L_liste& liste_liste);

/**
 * @brief D�sallouer une liste.
 * @see initialiser
 * @param[out] l La liste.
 */
void detruire(Liste& l);

/**
 * @brief Longueur de liste.
 * @param[in] l La liste.
 * @return La longueur de la liste.
 */
unsigned int longueur(const Liste& l);

/**
 * @brief Lire un �l�ment de liste.
 * @param[in] l La liste.
 * @param[in] pos Position de l'�l�ment � lire.
 * @return L'item lu en position pos.
 * @pre 0 <= pos < longueur(l).
 */
Item lire(const Liste& l, unsigned int pos);

/**
 * @brief Ecrire un item dans la liste.
 * @param[in,out] l La liste.
 * @param[in] pos Position de l'�l�ment � �crire.
 * @param[in] it L'item.
 * @pre 0 <= pos < longueur(l).
*/
void ecrire(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Ins�rer un �l�ment dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position � laquelle l'�l�ment est ins�r�.
 * @param[in] it L'�l�ment ins�r�.
 * @pre 0 <= pos <= longueur(l).
 */
void inserer(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Supprimer un �l�ment dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position de l'�l�ment � supprimer.
 * @pre longueur(l) > 0 et 0 <= pos < longueur(l).
 */
void supprimer(Liste& l, unsigned int pos);
