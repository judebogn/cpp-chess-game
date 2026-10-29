#ifndef JOUEUR_H
#define JOUEUR_H
#include "Position.h"
#include "Pieces.h"
#include "Plateau.h"
#include <string>


class Joueur {
public:
    Joueur(Couleur c);
    virtual ~Joueur();

    Couleur getCouleur() const;

    // Méthode abstraite : chaque type de joueur choisit son coup
   virtual bool jouer(Plateau& plateau) = 0;

protected:
    Couleur couleur;
};

#endif // JOUEUR_H
