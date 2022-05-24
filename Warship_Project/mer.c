/*
 * mer.c
 *
 *  Created on: 2 mai 2019
 *      Author: antho_9ak3x1e
 */

#include"mer.h"
#include<Stdio.h>
/* affichage de la mer */
void MerInitialisation(char mer[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y])
{

		int i = 0; // variable permettent l'affichage des numero de ligne
		int z,x,y; // variables permettent l'affichage des differentes dimention du tableau

		//definition de l'interface de la grille mer

		for (z=0; z<PROFONDEUR_MAX_Z; z++) // dimention de la profondeur
		{
			if (z == 1) // affichage de la lgine de la premiere des profondeur
				printf("\n  --------------------------------------------------");
			if (z == 2) // affichage de la deuxieme ligne des profondeur
				printf("\n  --------------------------------------------------");
			if (z == 3) //affichage de la troisieme ligne des profondeur
				printf("\n  --------------------------------------------------");
			printf("\n\n");
			printf("\n    0    1    2    3    4    5    6    7    8    9");  // affichage des numeros de colonene

			for (x=0; x<MER_MAX_X; x++) // dimention des lignes
			{
				printf("\n  --------------------------------------------------");
				printf("\n");
				printf("%d ",i++);// affichage des numero de ligne
				if (i == 5) // remise a 0 de i pour les differentes profondeur
					i = 0;
				for (y=0; y<MER_MAX_Y; y++) // troisieme dimention celle des colonnes
				{
					mer[z][x][y] = 'M'; //onn rempli le tableau de 'm' pour symboliser la mer
					printf("| %c ",mer[z][x][y]); // affichage de la separation des colonnes
					if (MER_MAX_Y == 10)
						printf("|");
				}
			}
		}
		return ;
}

