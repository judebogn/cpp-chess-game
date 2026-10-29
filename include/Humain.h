#ifndef HUMAIN_H
#define HUMAIN_H
#include "Joueur.h"

using namespace std ;


class Humain : public Joueur
 {

public:
    Humain(Couleur c);

    virtual ~Humain();
     bool jouer(Plateau& plateau) override;


    protected:

    private:
};

#endif // HUMAIN_H
