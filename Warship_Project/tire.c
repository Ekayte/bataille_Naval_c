/*
 * tire.c
 *
 *  Created on: 2 mai 2019
 *      Author: antho_9ak3x1e
 */

#include "joueur.h"
#include <assert.h>
#include <stdio.h>
#include "sousmarin.h"
#include "jeuSousMarin.h"
#include "mer.h"
#include "bool.h"
/* on definit juste qu'est ce qu'ai un tir*/
void initialiserTire(Position *posTire)
{
	posTire->x=0; // axe x
	posTire->y=0; // axe y
	posTire->z=0; // axe z
}

/* fonction pour affectuer les tirs sur les sousmarin*/

void tire(Position *posTire)
{
	printf("\nSaisissez x\n");
	scanf("%d", &posTire->x); // saisi du tir sur l'axe x
	getchar();
	printf("Saisissez y\n");
	scanf("%d", &posTire->y); // saisi du tir sur l'axe y
	getchar();
	printf("Saisissez z\n");
	scanf("%d", &posTire->z); // saisi du tir sur l'axe z
	getchar();

}
/*
 * fonction qui permet de diferencier si l'on a touché ou pas les sousmarin lors du tir
 */

bool SousMarinPositionCible(Joueur *joueur, Position *posTire, char *mer[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y]){
	int i=0,j=0;

	for (i=0; i<3 ;i++)  //pour passer d'un sousmarin à l'autre dans la structure joueur
	{
		printf("\npremiere boucle for\n ");
		for (j=0; j<joueur->sousMarin[i].taille ; j++) // pour passer d'une case à l'autre du sousmarin
		{
			printf("\ndeuxieme boucle for \n");
			if (posTire->x == joueur->sousMarin[i].pos[j].x && posTire->y == joueur->sousMarin[i].pos[j].y && posTire->z == joueur->sousMarin[i].pos[j].z )
			{//pour verifier si la case du sousmarin est touché
				printf("\n touche\n");
				joueur->sousMarin[i].touche[j] = TRUE; //enregistrer que la case est touché
				*mer[posTire->z][posTire->x][posTire->y]='T';  // afficher sur la grille que le sousmarin est touché
			}
			else
			{
				printf("\n Rien\n");
				joueur->sousMarin[i].touche[j] = FALSE;
				*mer[posTire->z][posTire->x][posTire->y]='R';  //afficher qu'il n'y a rien sur la case
			}
			printf("test 1");
		}
		printf("test 2");

	}
	printf("test 3");

	return joueur->sousMarin[i].touche[j];
}

void impactTire(Position *posTire, Joueur *joueur, char *mer[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y]){  // fonction pour l'affichage des Vu, Rien autour de la cible de tir
	int i=0,j=0,k=0;
	Position posVerify;  // variable des coordonnées à verifier autour du tir
	for (i=posTire->x-1; i<posTire->x+1; i=i+2){ //pour changer de colonne et verifier les cases devant et derriere la cible
		j=posTire->y; //j est la posotion y du tir
		k=posTire->z; //k est la posotion z du tir
		posVerify.x=i;//posverify prend les coordonnées du tire à verifier
		posVerify.y=j;
		posVerify.z=k;
		if ((joueur->sousMarin[1].pos[1].x == posVerify.x && joueur->sousMarin[1].pos[1].y == posVerify.y && joueur->sousMarin[1].pos[1].z == posVerify.z)||(joueur->sousMarin[1].pos[2].x == posVerify.x && joueur->sousMarin[1].pos[2].x == posVerify.x && joueur->sousMarin[1].pos[2].x == posVerify.x)||(joueur->sousMarin[1].pos[3].x==posVerify.x && joueur->sousMarin[1].pos[3].y==posVerify.y && joueur->sousMarin[1].pos[3].z==posVerify.z)||(joueur->sousMarin[2].pos[1].x==posVerify.x && joueur->sousMarin[2].pos[1].y==posVerify.y && joueur->sousMarin[2].pos[1].z==posVerify.z)||(joueur->sousMarin[2].pos[2].x==posVerify.x && joueur->sousMarin[2].pos[2].y==posVerify.y && joueur->sousMarin[2].pos[2].z==posVerify.z)||(joueur->sousMarin[2].pos[3].x==posVerify.x && joueur->sousMarin[2].pos[3].y==posVerify.y && joueur->sousMarin[2].pos[3].z==posVerify.z)||(joueur->sousMarin[3].pos[1].x==posVerify.x && joueur->sousMarin[3].pos[1].y==posVerify.y && joueur->sousMarin[3].pos[1].z==posVerify.z)||(joueur->sousMarin[3].pos[2].x==posVerify.x && joueur->sousMarin[3].pos[2].y==posVerify.y && joueur->sousMarin[3].pos[2].z==posVerify.z)||(joueur->sousMarin[3].pos[3].x==posVerify.x && joueur->sousMarin[3].pos[3].y==posVerify.y && joueur->sousMarin[3].pos[3].z==posVerify.z)){
			//condition pour verifier si un bout de sousmarin se situe au-dessus ou en-dessous du tire
			if (*mer[posVerify.z][posVerify.x-1][posVerify.y]!='C'||*mer[posVerify.z][posVerify.x-1][posVerify.y]!='T'){//pour pas remplacer un coulé ou un touche
				*mer[posVerify.z][posVerify.x-1][posVerify.y]='V';   /*afficher  V tout autour*/
			}

			if (*mer[posVerify.z][posVerify.x+1][posVerify.y]!='C'||*mer[posVerify.z][posVerify.x+1][posVerify.y]!='V'){
				*mer[posVerify.z][posVerify.x+1][posVerify.y]='V';
			}
			return;
		}
		else {
			*mer[posVerify.z][posVerify.x+1][posVerify.y]='R';/*afficher  R que là où verifier*/
			*mer[posVerify.z][posVerify.x-1][posVerify.y]='R';
		}
	}
	for (j=posTire->y-1; j<posTire->y+1; j=j+2){ //pour changer de ligne et verifier les cases devant et derriere la cible
		i=posTire->x;//j est la posotion x du tir
		k=posTire->z;//k est la posotion z du tir
		posVerify.x=i;
		posVerify.y=j;//posverify prend les coordonnées du tire à verifier
		posVerify.z=k;
		if ((joueur->sousMarin[1].pos[1].x == posVerify.x && joueur->sousMarin[1].pos[1].y == posVerify.y && joueur->sousMarin[1].pos[1].z == posVerify.z)||(joueur->sousMarin[1].pos[2].x == posVerify.x && joueur->sousMarin[1].pos[2].x == posVerify.x && joueur->sousMarin[1].pos[2].x == posVerify.x)||(joueur->sousMarin[1].pos[3].x==posVerify.x && joueur->sousMarin[1].pos[3].y==posVerify.y && joueur->sousMarin[1].pos[3].z==posVerify.z)||(joueur->sousMarin[2].pos[1].x==posVerify.x && joueur->sousMarin[2].pos[1].y==posVerify.y && joueur->sousMarin[2].pos[1].z==posVerify.z)||(joueur->sousMarin[2].pos[2].x==posVerify.x && joueur->sousMarin[2].pos[2].y==posVerify.y && joueur->sousMarin[2].pos[2].z==posVerify.z)||(joueur->sousMarin[2].pos[3].x==posVerify.x && joueur->sousMarin[2].pos[3].y==posVerify.y && joueur->sousMarin[2].pos[3].z==posVerify.z)||(joueur->sousMarin[3].pos[1].x==posVerify.x && joueur->sousMarin[3].pos[1].y==posVerify.y && joueur->sousMarin[3].pos[1].z==posVerify.z)||(joueur->sousMarin[3].pos[2].x==posVerify.x && joueur->sousMarin[3].pos[2].y==posVerify.y && joueur->sousMarin[3].pos[2].z==posVerify.z)||(joueur->sousMarin[3].pos[3].x==posVerify.x && joueur->sousMarin[3].pos[3].y==posVerify.y && joueur->sousMarin[3].pos[3].z==posVerify.z)){
			//condition pour verifier si un bout de sousmarin se situe au-dessus ou en-dessous du tire
			if (*mer[posVerify.z][posVerify.x][posVerify.y-1]!='C'||*mer[posVerify.z][posVerify.x][posVerify.y-1]!='T'){//pour pas remplacer un coulé ou un touche
				*mer[posVerify.z][posVerify.x][posVerify.y-1]='V';   /*afficher  V tout autour*/
			}

			if (*mer[posVerify.z][posVerify.x][posVerify.y+1]!='C'||*mer[posVerify.z][posVerify.x][posVerify.y+1]!='V'){
				*mer[posVerify.z][posVerify.x][posVerify.y+1]='V';
			}
			return;
		}
		else {
			*mer[posVerify.z][posVerify.x][posVerify.y-1]='R';/*afficher  R que là où verifier*/
			*mer[posVerify.z][posVerify.x][posVerify.y+1]='R';
		}

	}
}
