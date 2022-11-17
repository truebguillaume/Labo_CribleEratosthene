//---------------------------------------------------------
// Demo           : cribleEratosthene
// Fichier        : cribleEratosthene.cpp
// Auteur(s)      : Urs Behrmann & Trüeb Guillaume
// But            :
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------


#include <cmath>
#include "cribleEratosthene.h"


using namespace std;

vector<bool> calculerCrible(const size_t tailleVector){
    vector<bool> vecteurCriblage(tailleVector, true);

    // Mets la valeur 0 et 1 à false
    vecteurCriblage[0] = false;

    for (unsigned long i = 1 ; i < tailleVector ; ++i)
        if(vecteurCriblage[i])
            for (unsigned long j = 2; j <= tailleVector / (i + 1); ++j)
                vecteurCriblage[(i + 1) * j - 1] = false;

    vecteurCriblage.insert(vecteurCriblage.cbegin(), false);

    return vecteurCriblage;
}

vector<int> calculerNbrPremier(const vector<bool>& vecCrible){
    vector<int> vecNbrPremier;
    vecNbrPremier.reserve(vecCrible.size() );

    for(size_t i = 0; i < vecCrible.size(); ++i)
        if(vecCrible.at(i))
            vecNbrPremier.push_back((int)i);

    vecNbrPremier.shrink_to_fit();

    return vecNbrPremier;
}

vector<int> calculerNbrPremier2(const vector<bool>& vecCrible){
    vector<int> vecNbrPremier;
    vecNbrPremier.reserve(vecCrible.size());

    // x/log(x) x = nbre chiffre total

//    auto adressePremierVecteur = &vecCrible[0];
//
//    for (vector<bool>::iterator it = vecCrible.begin() ; it != vecCrible.end(); ++it)
//        vecNbrPremier.push_back(&it - adressePremierVecteur);


    vecNbrPremier.shrink_to_fit();

    return vecNbrPremier;
}
