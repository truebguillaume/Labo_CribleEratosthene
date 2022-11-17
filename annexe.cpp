//---------------------------------------------------------
// Demo           : annexe.cpp
// Fichier        : annexe.cpp
// Auteur(s)      : Trüeb Guillaume
// But            : Fournir différentes fonctions permettant de rendre plus efficace
//                : certaines actions répétitives, tel que la saisie utilisateur.
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include "annexe.h"

#include <iostream>
#include <limits>       //Numeric limits
#include <iomanip>

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int saisieEntier(const string& MSG, int min, int max, const string& MSG_ERREUR) {

    int  saisie;                 // Variable de stockage de la saisie
    bool erreur;                 // Variable de stockage de l'état de la saisie

    do {
        // Affichage message de demande de saisie
        cout << MSG;

        // Vérifie si le flux est cassé ou si la valeur est en dehors des valeurs minimum et maximum
        erreur = not(cin >> saisie) or saisie < min or saisie > max;

        // Si la saisie est incorrecte affiche message erreur et répare le flux
        if (erreur) {
            cout << MSG_ERREUR << endl;
            cin.clear();
        }

        VIDER_BUFFER;

    }while(erreur);

    return saisie;
}

// Cette fonction permet à l'utilisateur de recommencer le programme
bool repondOui() {
    char saisie;                // Variable de stockage de la saisie

    do {
        // Affichage message de demande de saisie
        cout << endl << "Voulez-vous recommencer le programme ? (o/n) : ";
        cin >> saisie;

        toupper(saisie);

        VIDER_BUFFER;

    }while(saisie != 'O' and saisie != 'N');

    // Si l'utilisateur a saisi 'o' on retourne true
    return saisie == 'O';
}

void afficheVecteur(const vector<bool> &vecteur, const string &titre, const int largeurColonne,
                    const int nbreColonne){

    cout << endl << titre << endl;

    for (unsigned long i = 0 ; i < vecteur.size() ; ++i) {

        if(vecteur[i])
            cout << setw(largeurColonne) << "O";
        else
            cout << setw(largeurColonne) << "X";

        if(nbreColonne > 0 && i % (unsigned long)nbreColonne == (unsigned long)nbreColonne - 1)
            cout << endl;
    }
}

void afficheVecteur(const vector<int>& vecteur, const string& titre, const string& separateur,
                    const int largeurColonne, const int nbreColonne){

    cout << endl << titre << endl;

    for (unsigned long i = 0 ; i < vecteur.size() ; ++i) {

        if(i != 0) cout << separateur;

        cout << setw(largeurColonne) << vecteur[i];

        if( nbreColonne > 0 && i % (unsigned long)nbreColonne == (unsigned long)nbreColonne - 1
            && i != 0 )
            cout << endl;
    }
}

