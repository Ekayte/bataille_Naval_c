/*
 * gestion_du_jeu.c
 *
 *  Created on: 2 mai 2019
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

#define NB_JOUEURS	(2)


// Fonction privees



// Declaration des joueurs

static Joueur joueur1, joueur2;


	/*
     * initialisation du jeux
     * on initialise ce que l'on a pas besoin de redemmander a chaque tour du jeu
	 * on definit les deux joueur
	 * on initialise la grille de mer a chaqun des deux joueurs
	 * placement des sous-marin par joueurs
	 */
void InitGestionJeu()
{


	char mer1[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y]; 		// declaration de la mer
	MerInitialisation(mer1);								// affichage de la mer pour pouvoir placer les sousmarins et pour avoir un aperçu
	InitJoueur(&joueur1, 1);								// on definit le joueur 1
	InitJoueur(&joueur2, 2);								// on definit le joueur 2
	printf("Joueur1 placer vos sousmarins");
	PlacementParJoueur(&joueur1);							//placement des 3 sous marin pour le joueur 1
	printf("Joueur2 placer vos sousmarins");
	PlacementParJoueur(&joueur2);							//placement des 3 sousmarin pour le joueur 2



}

/*fonction permetent de verifier si un joueur a coulé tout les sousmarin adverse*/

bool gestionDuJeux_checkFinDuJeux(Joueur *joueur1, Joueur *joueur2,bool checkFinDuJeux)
{

	if (joueur1->sousMarin[0].coule==TRUE && joueur1->sousMarin[1].coule==TRUE && joueur1->sousMarin[2].coule==TRUE) // condition verifiant si tout les sousmarin du joueur 1 sont coulés
	{
		checkFinDuJeux = TRUE;		// mise a jour de la variable ce qui met fin au jeu
		printf("%s à gagner !\n",joueur2->nom); // le joueur 2 gagne
	}
	if (joueur2->sousMarin[0].coule==TRUE && joueur2->sousMarin[1].coule==TRUE && joueur2->sousMarin[2].coule==TRUE) // condition verifiant si tout les sousmarin du joueur 2 sont coulés
	{
		checkFinDuJeux = TRUE;		// mise a jour de la variable ce qui met fin au jeu
		printf("%s à gagner !\n",joueur1->nom); // le joueur 1 gagne
	}
	else // si persone ne finit le jeu cntinue
	{
		checkFinDuJeux=FALSE; // fin du jeu toujour a faux
	}
	return checkFinDuJeux; // on retourne la variable permettant de ssavoir si le jeu est finit
}
/**
 * Boucle principale du jeu.
 * on effectue dans cette fonction les tour du jeu, soit :
 * 		-les tirs sur les sousmarin par les deux joueur
 * 		-l'actualisation des tableau mer de chaque joueur suivant ce que touche le tirs adverse
 * 		-on verifi si les sousmarin sont coulé
 * 		-on verifi la fin du jeu
 */
void JeuEnCours()
{
    bool checkFinDuJeux=FALSE; // declaration de la variable verifiant la fin du jeu
    char mer1[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y],mer2[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y];//mer1 est l'affichage du jeu pour le joueur 1 et la mer 2 celui du joueur 2
    Position posTire;
	while(checkFinDuJeux==FALSE) // quand la variable checkFinDuJeu passe a true le jeu s'arrete
	{

		//d'abord le tour pour le joueur 1
		printf("C'est au tour de %s \n", joueur1.nom);
		MerInitialisation(mer1);                                            // initialisation de la mer pour le joueur 1
		initialiserTire(&posTire);											// initialisation du tirs qu'effectura le joueur 1
		//printf("\n1\n");
		tire(&posTire);														//tirs du joueur 1 sur la mer du joueur 2
		//printf("\n2\n");
		SousMarinPositionCible(&joueur2, &posTire, &mer1);					// verification de ce qu'a touché le joueur 1 si c'est "touché" ou "rien"
		//printf("\n3\n");

		impactTire(&posTire, &joueur2, &mer1);								// l'impacte qu'a effectué le tir présédent qui serra représenter de maniere differente suivant ce qu'il a touché
		MerInitialisation(mer1);											// actualisation de la mer du joueur 2
		SousMarinCoule(&joueur2.sousMarin[0], &mer1);						// verification si le sousmarin 1 a coulé du joueur 2
		SousMarinCoule(&joueur2.sousMarin[1], &mer1);						// verification si le sousmarin 2 a coulé du joueur 2
		SousMarinCoule(&joueur2.sousMarin[2], &mer1);						// verification si le sousmarin 3 a coulé du joueur 2
		gestionDuJeux_checkFinDuJeux(&joueur1, &joueur2, checkFinDuJeux);	// check si le jeu est finit

		//d'abord le tour pour le joueur 2
		printf("C'est au tour de %s \n", joueur2.nom);
		MerInitialisation(mer2);											// initialisation de la mer pour le joueur 2
		initialiserTire(&posTire);											// initialisation du tirs qu'effectura le joueur 2
		tire(&posTire);														//tirs du joueur 2 sur la mer du joueur 1
		SousMarinPositionCible(&joueur1, &posTire, &mer2);					// verification de ce qu'a touché le joueur 2 si c'est "touché" ou "rien"
		impactTire(&posTire, &joueur1, &mer2);								// l'impacte qu'a effectué le tir présédent qui serra représenter de maniere differente suivant ce qu'il a touché
		MerInitialisation(mer2);											// actualisation de la mer du joueur 1
		SousMarinCoule(&joueur1.sousMarin[0], &mer2);						// verification si le sousmarin 1 a coulé du joueur 1
		SousMarinCoule(&joueur1.sousMarin[1], &mer2);						// verification si le sousmarin 2 a coulé du joueur 1
		SousMarinCoule(&joueur1.sousMarin[2], &mer2);						// verification si le sousmarin 3 a coulé du joueur 1
		gestionDuJeux_checkFinDuJeux(&joueur1, &joueur2, checkFinDuJeux);	// check si le jeu est finit
	}



}

/*exemple pour la sauvegarde du jeu*/

/* sauvegarde de fichier
 *int x = 1,y = 2,z = 5;
 * FILE * f = fopen("backup.txt", "w");    //ouvrir creer le fichier
 *
 * fprintf(f,"%d %d %d\n,x,y,z);       // ecrit dans le fichier
 *
 * fscanf(f, %d %d %d );
 *
 * fclose(f);  //ferme le fichier
 */

