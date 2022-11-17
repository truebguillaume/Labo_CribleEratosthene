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

#include <cstdlib>              // EXIT_SUCCESS
#include <limits>               // Numeric limits
#include <vector>               // Vecteur
#include <iostream>             // cout

#include "annexe.h"             // Librairie personnelle
#include "cribleEratosthene.h"  // Librairie pour le criblage

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {

    const int MIN_VALEUR = 2;
    const int MAX_VALEUR = 100;
    const int NBRE_COLONNE = 10;
    const int LARGEUR_COLONNE = 4;
    size_t nbreValeurs;

    nbreValeurs = (size_t)saisieEntier("Nombre de valeurs : ", MIN_VALEUR, MAX_VALEUR,
                                       "Valeur eronnée!");

    vector<bool> vecteurCriblage   = cribleEratosthene(nbreValeurs);
    afficheVecteur(vecteurCriblage, "Criblage du tableau", LARGEUR_COLONNE, NBRE_COLONNE);


    vector<int>  vecteurNbrPremier = nbrsPremier(vecteurCriblage);
    afficheVecteur(vecteurNbrPremier, "Nombres premiers", " / ");

    //Fin de programme
    cout << "Pressez ENTER pour quitter";
    VIDER_BUFFER;   // Vider le buffer
    return EXIT_SUCCESS;
}