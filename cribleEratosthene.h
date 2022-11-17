//---------------------------------------------------------
// Fichier        : cribleEratosthene.hpp
// Version        : 1.0
// Auteur(s)      : Trüeb Guillaume et Urs Behrmann
// Date           : 17.11.2022
// But            :
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

//-------------------------------------------------------------------------
#ifndef LABO_CRIBLEERATOSTHENE_CRIBLEERATOSTHENE_H
    #define LABO_CRIBLEERATOSTHENE_CRIBLEERATOSTHENE_H

    // Includes pour les éléments nécessaires au .h
    #include <vector>          // nécessaire pour les paramètres

    // Fonction permettant de demander à l'utilisateur une question en attendant une réponse oui ou non
    // ---------------------------------------------------------------------------------------------------------------------
    // @retour                  : une valeur de type bool avec true si la réponse était oui
    // @exceptions              : -
    std::vector<bool> calculerCrible(size_t tailleVector);

    std::vector<int> calculerNbrPremier(const std::vector<bool>& vecCrible);

#endif // LABO_CRIBLEERATOSTHENE_CRIBLEERATOSTHENE_H