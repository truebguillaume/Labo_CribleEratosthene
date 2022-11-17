//---------------------------------------------------------
// Demo           : Labo_CribleEratosthene_Groupe_05_D
// Fichier        : Labo_CribleEratosthene_Groupe_05_D.cpp
// Auteur(s)      : Urs Behrmann & Trüeb Guillaume
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include <iostream>     //cout, cin
#include <cstdlib>      //EXIT_SUCCESS
#include <limits>       //Numeric limits
#include <vector>

#include "annexe.h"     //Librairie personnelle
#include "cribleEratosthene.h"

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {

    const int MIN_VALEUR = 2;
    const int MAX_VALEUR = 100;
    const int NBRE_COLONNE = 10;
    const int LARGEUR_COLONNE = 4;
    size_t nbreValeurs;

    nbreValeurs = saisieEntier("Nombre de valeurs : ", MIN_VALEUR, MAX_VALEUR, "Valeur eronnée!");

    vector<bool> vecteurCriblage   = calculerCrible(nbreValeurs);
    afficheVecteurCriblage(vecteurCriblage, NBRE_COLONNE, LARGEUR_COLONNE, "Criblage du tableau");

    vector<int>  vecteurNbrPremier = calculerNbrPremier(vecteurCriblage);
    afficheVecteur(vecteurNbrPremier, NBRE_COLONNE, LARGEUR_COLONNE, "Nombres premiers");

    return EXIT_SUCCESS;
}