/*
 * joueur.h
 * .h qui regroupe les fonction du joueur.c
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_
#include"sousmarin.h"
#include"mer.h"
//#include"sousmarin.h"

/* definition de la macro NB_SOUSMARIN a 3 car 3 sousmarin dans le jeu*/
#define NB_SOUSMARINS	(3)

/* création de a structure Joueur
 *  permet de créer un nouveau type de variable qui est Joueur
 *  regroupe l'id du joueur
 *  sont nom
 *  ses sousmarin
 *  son tableau mer
 */
typedef struct
{
	int id ;
	char nom[10];
	SousMarin sousMarin[NB_SOUSMARINS]; // on creer un tableau qui regroupe tous les sousMarin
	Possibilite mer[PROFONDEUR_MAX_Z][MER_MAX_Y][MER_MAX_X];
} Joueur;



void InitJoueur(Joueur * joueur, int i);


#endif /* JOUEUR_H_ */
