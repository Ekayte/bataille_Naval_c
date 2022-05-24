/*
  * sousmarin.c
 *
 *  Created on: 1 avr. 2019
 *      Author: antho_9ak3x1e
 */
#include "joueur.h"
#include <assert.h>
#include <stdio.h>
#include "sousmarin.h"
#include "jeuSousMarin.h"
#include "bool.h"
/*
 * initialisation des sousmarin
 * donc ici dans cette fonction on definit chaque sousmarin avec leur taile respective
 */
void InitSousMarin (SousMarin *sousmarin,int taille)
{
	sousmarin->pos_initialized = FALSE;  	// verification si le sousmarin n'est pas encore placé
	sousmarin->touche[1] = FALSE;			// en mettent FALSE on dit que le sousmarin 1 n'est pas touché
	sousmarin->touche[2] = FALSE;			// en mettent FALSE on dit que le sousmarin 2 n'est pas touché
	sousmarin->touche[3] = FALSE;			// en mettent FALSE on dit que le sousmarin 3 n'est pas touché
	sousmarin->coule = FALSE;				// en mettent FALSE on dit que les sousmarins  n'est pas coulé
	sousmarin->taille = taille; 			//definition de la variable taille qui servira a definir la taille des different soumarin
}
/*
 * placement des sous marin
 */

void PlacementSousmarin (SousMarin *sousmarin,int taille)
{


	int i = 0;
	//bool valid = FALSE;
	//while(valid== FALSE){
		for (i=0 ; i<taille ;i++) 	// ici on utilise en parametre de la boucle la taille pour pouvoir effectuer cett boucle for pour chaque type de sousmarin
									// cette boucle for vas s'executer au temps de fois que le sousmarin aura de case a placer
									// car on place case par case les sous marin
		{
		printf("\nSaisissez les coordonnees du sous-marin\n");
		printf("Saisissez x\n");
		scanf("%d", &sousmarin->pos[i].x); // saisi de la position en x de la case du sousmarin
		getchar();
		printf("Saisissez y\n");
		scanf("%d", &sousmarin->pos[i].y); // saisi de la position en y  de la case du sousmarin
		getchar();
		printf("Saisissez z\n");
		scanf("%d", &sousmarin->pos[i].z);  // saisi de la position en z  de la case du sousmarin
		getchar();

		}
		/* ce qui suit est pour la verification de la position des sousmarins, si les case sont bien collé*/

		/*if (taille == 1)
		{
			printf("\nsousmarin 1 placé\n");
			break;
		}
		if ((taille == 2)&&( (&sousmarin->pos[1].x == &sousmarin->pos[0].x + 1)||(&sousmarin->pos[1].x == &sousmarin->pos[0].x - 1 ) )||( (&sousmarin->pos[1].y == &sousmarin->pos[0].y + 1)||(&sousmarin->pos[1].y == &sousmarin->pos[0].y - 1 ) )&&( (&sousmarin->pos[1].z == &sousmarin->pos[0].z )))
		{
			printf("\nsousmarin 2 placé\n");
			break;
		}
		if ((taille == 3)&&( ((&sousmarin->pos[1].x == &sousmarin->pos[0].x + 1) || (&sousmarin->pos[2].x == &sousmarin->pos[2].x + 1))||((&sousmarin->pos[1].x == &sousmarin->pos[1].x - 1 )||(&sousmarin->pos[2].x == &sousmarin->pos[1].x - 1 )) )||( ((&sousmarin->pos[1].y == &sousmarin->pos[0].y + 1) || (&sousmarin->pos[2].y == &sousmarin->pos[2].y + 1))||((&sousmarin->pos[1].y == &sousmarin->pos[1].y - 1 )||(&sousmarin->pos[2].y == &sousmarin->pos[1].y - 1 )) )&&( ((&sousmarin->pos[1].z == &sousmarin->pos[0].z ))))
		{
			printf("\nsousmarin 3 placé\n");
			break;

		}
		printf("ERREUR COORDONNEES NON-VALIDE: \nSaisissez des coordonnees cote a cote\n");
	}*/

}

/*
 * placement des trois sousmarin pour un joueur
 */
void PlacementParJoueur (Joueur *joueur)
{

	PlacementSousmarin (&joueur->sousMarin[0], 1); // premier sousmarin
	printf("\n sousmarin 1 est place\n");
	PlacementSousmarin (&joueur->sousMarin[1], 2); // deuxieme sousmarin
	printf("\n sousmarin 2 est place\n");
	PlacementSousmarin (&joueur->sousMarin[2], 3); // troisieme sousmarin
	printf("\n sousmarin 3 est place\n");
}


bool SousMarinPositionValid(SousMarin * sousmarin){
	sousmarin->pos_initialized = TRUE;
	return sousmarin->pos_initialized;
}
/*
 * verification si les sous marin sont coulé
 */

bool SousMarinCoule(SousMarin *sousmarin, char *mer[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y]){
	if (sousmarin->taille==1)     // pour un sousmarin de taille 1
	{
		if (sousmarin->touche[0] == TRUE)   // si le sousmarin est touché soit egale a TRUE
		{
			sousmarin->coule = TRUE;        // le parametre coule dans la structure devient vrai
			*mer[sousmarin->pos[0].z][sousmarin->pos[0].x][sousmarin->pos[0].y]='C'; // l'emplacement du sousmarin est marquer d'un 'c'
		}
	}
	else if (sousmarin->taille==2)    // pour un sousmarin de taille 2
	{
		if (sousmarin->touche[0] == TRUE && sousmarin->touche[1] == TRUE) // les deux case du sousmarin sont touché
		{
			sousmarin->coule = TRUE; // le parametre coule dans la structure devient vrai
			*mer[sousmarin->pos[0].z][sousmarin->pos[0].x][sousmarin->pos[0].y]='C';  // l'emplacement du sousmarin est marquer d'un 'c'
			*mer[sousmarin->pos[1].z][sousmarin->pos[1].x][sousmarin->pos[1].y]='C'; // l'emplacement du sousmarin est marquer d'un 'c'
		}
	}
	else if (sousmarin->taille==3)	// pour un sousmarin de taille 3
	{
		if (sousmarin->touche[0] == TRUE && sousmarin->touche[1] == TRUE && sousmarin->touche[2] == TRUE)	// les trois case du sousmarin sont touché
		{
			sousmarin->coule = TRUE;  // le parametre coule dans la structure devient vrai
			*mer[sousmarin->pos[0].z][sousmarin->pos[0].x][sousmarin->pos[0].y]='C'; // l'emplacement du sousmarin est marquer d'un 'c'
			*mer[sousmarin->pos[1].z][sousmarin->pos[1].x][sousmarin->pos[1].y]='C'; // l'emplacement du sousmarin est marquer d'un 'c'
			*mer[sousmarin->pos[2].z][sousmarin->pos[2].x][sousmarin->pos[2].y]='C'; // l'emplacement du sousmarin est marquer d'un 'c'
		}
	}
	return sousmarin->coule;
}
