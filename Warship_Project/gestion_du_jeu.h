/*
 * gestion_du_jeu.h
 *
 * .h regroupent les fonction de gestion_du_jeu.c
 *
 */

#ifndef GESTION_DU_JEU_H_
#define GESTION_DU_JEU_H_
#include "joueur.h"
#include <assert.h>
#include <stdio.h>
#include "sousmarin.h"
#include "jeuSousMarin.h"
#include "mer.h"
#include "tire.h"
#include "bool.h"

void InitGestionJeu();
bool gestionDuJeux_checkFinDuJeux(Joueur *joueur1, Joueur *joueur2,bool checkFinDuJeux);
void JeuEnCours();

#endif /* GESTION_DU_JEU_H_ */
