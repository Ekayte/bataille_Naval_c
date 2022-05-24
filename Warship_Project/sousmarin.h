/*
 * SousMarin.h
 *
 */

#ifndef SOUSMARIN_H_
#define SOUSMARIN_H_

#include "bool.h"
#define TailleMaxSousMarin	(3)

/* structure poisition qui permet de créer une varaible qui regroupe les position des sousmarin une fois placé*/
typedef struct
{
	int x;	// L'abscisse
	int y;	// L'ordonnée
	int z; 	// La profondeur
} Position;
/* structure qui regroupe ce que l'on a besoin pour le sousmarin*/
typedef struct
{
	bool pos_initialized;           	 // variable permettant de savoir si le sous-marin est bien placé
	Position pos[TailleMaxSousMarin];    //position du sousmarin dans la grille
	int taille;                        	 //taille du sousmarin
	bool touche[TailleMaxSousMarin]; 	 // Tableau permettant de connaitre les cases touchées
	bool coule;							 // Variable permettant de savoir si le sous-marin est coulé
} SousMarin;


#endif /* SOUSMARIN_H_ */
