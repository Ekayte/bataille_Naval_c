/*
 * SousMarin.h
 *
 */

#ifndef SOUSMARIN_H_
#define SOUSMARIN_H_

#include "bool.h"
#define TailleMaxSousMarin	(3)

/* structure poisition qui permet de cr�er une varaible qui regroupe les position des sousmarin une fois plac�*/
typedef struct
{
	int x;	// L'abscisse
	int y;	// L'ordonn�e
	int z; 	// La profondeur
} Position;
/* structure qui regroupe ce que l'on a besoin pour le sousmarin*/
typedef struct
{
	bool pos_initialized;           	 // variable permettant de savoir si le sous-marin est bien plac�
	Position pos[TailleMaxSousMarin];    //position du sousmarin dans la grille
	int taille;                        	 //taille du sousmarin
	bool touche[TailleMaxSousMarin]; 	 // Tableau permettant de connaitre les cases touch�es
	bool coule;							 // Variable permettant de savoir si le sous-marin est coul�
} SousMarin;


#endif /* SOUSMARIN_H_ */
