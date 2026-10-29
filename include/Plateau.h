#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include "Pieces.h"
#include "Position.h"
#include "Roi.h"
#include "Dame.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Pion.h"

class Plateau {
public:
    Plateau();              // initialise l’échiquier
    ~Plateau();             // libère la mémoire

    // ----- Affichage -----
    void afficher() const;

    // ----- Accès aux cases -----
    Pieces* getPiece(const Position& p) const;

    // ----- Placement / suppression -----
    void placerPiece(Pieces* piece, const Position& p);
    // ----- Déplacement principal -----
    bool coupValide(const Position& , const Position& );
    bool deplacerPiece(const Position& depart,
                       const Position& arrivee,int i);
    void gererPromotion(Pieces* p , int i);
    bool estEnEchec(Couleur couleur) ;
    bool estEchecEtMat(Couleur couleur);
    bool matchnul1(Couleur couleur) ;
    bool matchnul2() const ;
    bool matchnul3() const ;
    bool matchnul4() const ;

    bool cheminLibre(const Position& depart,
                     const Position& arrivee) const;



private:
    Pieces* cases[8][8];

    // ----- Initialisation -----
    void initialiser();


};

#endif
