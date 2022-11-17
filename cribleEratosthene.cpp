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

#include "cribleEratosthene.h"

vector<bool> calculerCrible(const size_t tailleVector){
    vector<bool> vecteurCriblage(tailleVector, true);

    for (unsigned long i = 1 ; i < tailleVector ; ++i)
        if(vecteurCriblage[i])
//            for (int j = i + 1 ; j < tailleVector ; ++j)
//                if((j+1)%(i+1) == 0)
//                    vecteurCriblage[j] = false;
            for (unsigned long j = 2; j <= tailleVector / (i + 1); ++j)
                vecteurCriblage[(i + 1) * j - 1] = false;

    return vecteurCriblage;
}

vector<char> calculerCribleChar(const size_t tailleVector){
    vector<char> vecteurCriblage(tailleVector, 'O');

    vecteurCriblage[0] = ' ';

    for (unsigned long i = 1 ; i < tailleVector ; ++i)
        if(vecteurCriblage[i])
//            for (int j = i + 1 ; j < tailleVector ; ++j)
//                if((j+1)%(i+1) == 0)
//                    vecteurCriblage[j] = 'X';
            for (unsigned long j = 2; j <= tailleVector / (i + 1); ++j)
                vecteurCriblage[(i + 1) * j - 1] = 'X';

    return vecteurCriblage;
}
