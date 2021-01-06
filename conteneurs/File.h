#pragma once

/**
 * @file File.h
 * @brief Composant de file avec capacit� param�tr�e.
 */

#include "ConteneurTD.h"

struct File {
	/// Conteneur des �l�ments de file.
	ConteneurTD c;
	/// Indice de la t�te de file.
	unsigned int indPremier;
	/// Indice du prochain �l�ment entr� en file.
	unsigned int indProchain;
	/// Nombre d'�l�ments dans la file.
	unsigned int nb;
};

/**
 * @brief Initialiser une file vide.
 * @param[out] f File � initialiser.
 * @param[in] capa Capacit� de la file (nb maximum d�items stock�s).
 * @pre capa > 0.
 */
void initialiser(File& f, unsigned int capa);

/**
* @brief D�sallouer une file.
* @param[out] f La file. 
*/
void detruire(File& f);

/**
 * @brief Test de file pleine.
 * @param[in] f File test�e.
 * @return true si f est pleine, false sinon.
 */
bool estPleine(const File& f);

/**
 * @brief Test de file vide.
 * @param[in] f File test�e.
 * @return true si f est vide, false sinon.
 */
bool estVide(const File& f);

/**
 * @brief Lire l'item en t�te de file.
 * @param[in] f La file.
 * @return La valeur de l'item en t�te de file.
 * @pre La file n�est pas vide.
 */
Item tete(const File& f);

/**
 * @brief Entrer un item dans la file.
 * @param[in,out] f La file.
 * @param[in] it L'item � entrer.
 * @pre f n�est pas pleine.
 */
void entrer(File& f, const Item& it);

/**
 * @brief Sortir l�item t�te de file.
 * @param[in,out] f La file.
 * @pre f n�est pas vide.
 */
void sortir(File& f);
