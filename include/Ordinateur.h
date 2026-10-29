#ifndef ORDINATEUR_H
#define ORDINATEUR_H

#include "Joueur.h"
#include "Plateau.h"
#include <vector>

class Ordinateur : public Joueur {
public:
    Ordinateur(Couleur c);
    virtual ~Ordinateur();

    // L'ordinateur joue un coup
    bool jouer(Plateau& plateau) override;
};

#endif // ORDINATEUR_H
