/*
 * tire.h
 * .h regroupent les fonctions qui son dans le fichié tire.c
 *
 */

#ifndef TIRE_H_
#define TIRE_H_
#include "joueur.h"
#include "sousmarin.h"
#include "mer.h"
#include "jeuSousMarin.h"
#include "bool.h"

void initialiserTire(Position *posTire);
void tire(Position *posTire);
bool SousMarinPositionCible(Joueur *joueur, Position *posTire, char *mer[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y]);
void impactTire(Position *posTire, Joueur *joueur, char *mer[PROFONDEUR_MAX_Z][MER_MAX_X][MER_MAX_Y]);

#endif /* TIRE_H_ */
