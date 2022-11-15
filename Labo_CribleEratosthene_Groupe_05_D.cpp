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
#include <string>
#include <vector>
#include <math.h>

#include "annexe.h"     //Librairie personnelle

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

vector<bool> calculerCrible(const size_t tailleVector){
    vector<bool> vecteurCriblage((unsigned long)tailleVector, true);

    for (unsigned long i = 1 ; i < tailleVector ; ++i){
        if(vecteurCriblage[i]){
//            for (int j = i + 1 ; j < tailleVector ; ++j)
//                if((j+1)%(i+1) == 0)
//                    vecteurCriblage[j] = false;

            for (unsigned long j = 2; j < tailleVector / (i - 1); ++j)
                vecteurCriblage[(i + 1) * j - 1] = false;

        }
    }

    return vecteurCriblage;
}

vector<int> calculerNbrPremier(const vector<bool>& vecCrible){
    vector<int> vecNbrPremier;

    for (vector<bool>::const_iterator i = vecCrible.begin(); i != vecCrible.end(); ++i)
        cout << *i << " ";

}

int main() {

    const int MIN_VALEUR = 2;
    const int MAX_VALEUR = 100;
    int nbreValeurs;

    nbreValeurs = 55; //saisieEntier("nbre de valeurs ", MIN_VALEUR, MAX_VALEUR, "Valeur erronee!");

    vector<bool> vecteurCriblage = calculerCrible(nbreValeurs);
    //vector<int>  vecteurNbrPremier = calculerNbrPremier(vecteurCriblage);

    int compteur = 0;
    for(int i : vecteurCriblage){
        if(compteur == 10){
            compteur = 0;
            cout << endl;
        }
        cout << i << " ";
        compteur++;
    }

    return EXIT_SUCCESS;
}