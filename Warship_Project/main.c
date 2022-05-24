/*
 * main.c
 *
 *  Created on: 5 mai 2019
 *      Author: antho_9ak3x1e
 */

#include "gestion_du_jeu.h"
#include "joueur.h"
#include <assert.h>
#include <stdio.h>
#include "sousmarin.h"
#include "jeuSousMarin.h"
#include "mer.h"
#include "tire.h"
#include "bool.h"
/*
 * le main du programme
 * excute seulement 2 fonction
 */

int main()
{

	InitGestionJeu(); // fonction permettant d'initialiser le joueu
	JeuEnCours();	  // fonction qui permet de jouer au jeu avec les tour du jeu
	return 0;
}

