/*
 * joueur.c
 *
 *  Created on: 29 avr. 2019
 *      Author: antho_9ak3x1e
 */
#include "jeuSousMarin.h"
#include "sousmarin.h"
#include"joueur.h"
#include<stdio.h>
//#include"buffer.h"
#include<stdlib.h>
#include<string.h>
/* On initialise le Joueur*/


void InitJoueur(Joueur * joueur, int numeroJoueur)
{

	/*
	 * initialiser le joueur
	 * saisi du nom du joueur
	 * dire le nombre de sousMarin qui reste a placer
	 * demander les coordonnees pour les placer
	 */

	joueur->id = numeroJoueur ;                     // on assigner un id au joueur pour pouvoir diferencier le joueur 1 du joueur 2
	printf ("\nJoueur %d\n",joueur->id);

	printf("Entrer le nom du joueur\n ");
	scanf("%s",joueur->nom);						// saisi du nom du joueur
	printf("Le joueur est : %s \n\n",joueur->nom);

	InitSousMarin(&joueur->sousMarin[0],1);			//  initialisation des sousmarin 1 2 3 a chaque joueur
	InitSousMarin(&joueur->sousMarin[1],2);
	InitSousMarin(&joueur->sousMarin[2],3);
}




