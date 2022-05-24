/*
 * jeuSousMarin.h
 *
 *  .h regroupent les fonction se raportant au sousmarin
 *
 */

#ifndef JEUSOUSMARIN_H_
#define JEUSOUSMARIN_H_
#include "joueur.h"
#include "sousmarin.h"
#include "bool.h"

void InitSousMarin (SousMarin *sousmarin,int taille);
void PlacementSousmarin (SousMarin *sousmarin,int taille);
void PlacementParJoueur (Joueur *joueur);
bool SousMarinPositionValid(SousMarin * sousmarin);

bool SousMarinCoule(SousMarin *sousmarin, char *mer[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y]);


#endif /* JEUSOUSMARIN_H_ */
