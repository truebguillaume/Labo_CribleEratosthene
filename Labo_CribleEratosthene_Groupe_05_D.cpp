//----------------------------------------------------------------------------------------------------------------------
// Demo           : Labo_CribleEratosthene_Groupe_05_D
// Fichier        : Labo_CribleEratosthene_Groupe_05_D.cpp
// Auteur(s)      : Urs Behrmann & Trüeb Guillaume
// But            : Créer un programme permettant de calculer les nombres premiers en se basant sur un
//                : crible eratosthene.
// Modifications  : -
// Remarque(s)    : -
// Compilateur    : MinGW w64 9.0.0 / Apple clang version 14.0.0
// C++ version    : C++20
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>             // Utilisation de cout, cin
#include <cstdlib>              // Utilisation de EXIT_SUCCESS
#include <limits>               // Utilisation de numeric limits
#include <vector>               // Utilisation des vecteurs

#include "annexe.h"             // Librairie personnelle
#include "cribleEratosthene.h"  // Libraire pour calculer crible

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {

    const int MIN_VALEUR        = 2;        // Valeur minimale autorisee pour l'utilisateur
    const int MAX_VALEUR        = 100;      // Valeur maximale autorisee pour l'utilisateur
    const int NBRE_COLONNE      = 10;       // Nombre de colonnes d'affichage
    const int LARGEUR_COLONNE   = 4;        // Largeur d'une colonne d'affichage

    // Saisie pour récupérer le nombre de valeur à parcourir pour calculer
    // les nombres premiers
    size_t nbreValeurs = (size_t)saisieEntier("Nombre de valeurs", MIN_VALEUR, MAX_VALEUR, "La valeur est hors-plage!");

    // En fonction de nbreValeurs calculer un vecteur crible avec toutes les
    // nombres premiers et l'affecter dans une vecteur de booleen
    vector<bool> vecteurCriblage   = cribleEratosthene(nbreValeurs);

    // Afficher le vecteur crible pour l'utilisateur
    afficheVecteur(vecteurCriblage, "Criblage du tableau", LARGEUR_COLONNE, NBRE_COLONNE);

    // En fonction du vecteur crible on le parcours et recupere tous les nombres premiers
    vector<int>  vecteurNbrPremier = nbrsPremier(vecteurCriblage);

    // Afficher le vecteur de nombre premier pour l'utilisateur
    afficheVecteur(vecteurNbrPremier, "Nombres premiers", LARGEUR_COLONNE, NBRE_COLONNE);

    // Demande à l'utilisateur d'appuyer sur enter pour quitter le programme
    cout << endl << "Appuyez sur ENTER pour quitter le programme.";
    VIDER_BUFFER;
    return EXIT_SUCCESS;

}