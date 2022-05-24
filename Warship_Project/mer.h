/*
 * mer.h
 *
 */

#ifndef MER_H_
#define MER_H_

//#include "utils.h"
#include "bool.h"


// Taille en X de la mer.

#define MER_MAX_Y 	(10)

// Taille en Y de la mer.

#define MER_MAX_X	(5)

// Nombre de paliers definissant la profondeur d'une mer.

#define PROFONDEUR_MAX_Z	(3)

// Statut de chaque case de la mer.

typedef enum
{
	STATUS_RIEN,
	STATUS_R,
	STATUS_V,
	STATUS_T,
	STATUS_C,
	NB_STATUS

} Possibilite;

void MerInitialisation(char mer[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y]);




#endif /* MER_H_ */
