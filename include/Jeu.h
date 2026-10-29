#ifndef JEU_H
#define JEU_H


#include "Plateau.h"
#include "Joueur.h"



class Jeu {
public:
    Jeu(Joueur* b, Joueur* n);
    ~Jeu();

    void lancer();

private:
    int compteur{0};
    Plateau plateau;
    Joueur* blanc;
    Joueur* noir;
    Joueur* courant;
};

#endif
