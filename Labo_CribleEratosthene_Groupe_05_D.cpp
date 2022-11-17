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
#include <iomanip>

#include "annexe.h"     //Librairie personnelle

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

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

vector<int> calculerNbrPremier(const vector<bool>& vecCrible){
    vector<int> vecNbrPremier;

    for (vector<bool>::const_iterator i = vecCrible.begin(); i != vecCrible.end(); ++i)
    {
        if(*i)
            cout << *i;

    }
}

void afficheVecteurCriblage(const vector<bool>& vecteur, const int nbreColonne,
                    const int largeurColonne, const string& titre = ""){

    cout << endl << titre << endl;

    for (unsigned long i = 0 ; i < vecteur.size() ; ++i) {

        if(i == 0){
            cout << setw(largeurColonne) << " ";
            continue;
        }

        if(vecteur[i])
            cout << setw(largeurColonne) << "O";
        else
            cout << setw(largeurColonne) << "X";

        if(nbreColonne > 0 && i % (unsigned long)nbreColonne == (unsigned long)nbreColonne - 1)
            cout << endl;
    }
}

void afficheVecteur(const vector<char>& vecteur, const int nbreColonne,
                            const int largeurColonne, const string& titre = ""){

    cout << endl << titre << endl;

    for (unsigned long i = 0 ; i < vecteur.size() ; ++i) {
        cout << setw(largeurColonne) << vecteur[i];

        if( nbreColonne > 0 && i % (unsigned long)nbreColonne == (unsigned long)nbreColonne - 1
        && i != 0 )
            cout << endl;
    }
}

int main() {

    const int MIN_VALEUR = 2;
    const int MAX_VALEUR = 100;
    const int NBRE_COLONNE = 10;
    const int LARGEUR_COLONNE = 4;
    size_t nbreValeurs;

    nbreValeurs = 100; //saisieEntier("nbre de valeurs ", MIN_VALEUR, MAX_VALEUR, "Valeur
    // erronee!");

    vector<bool> vecteurCriblage = calculerCrible(nbreValeurs);
    vector<char> vecteurCriblageChar = calculerCribleChar(nbreValeurs);
    //vector<int>  vecteurNbrPremier = calculerNbrPremier(vecteurCriblage);

    //afficheVecteurCriblage(vecteurCriblage, NBRE_COLONNE, LARGEUR_COLONNE, "criblage du tableau");
    //afficheVecteur(vecteurCriblageChar, NBRE_COLONNE, LARGEUR_COLONNE, "criblage du tableau");

    calculerNbrPremier(vecteurCriblage);

    return EXIT_SUCCESS;
}