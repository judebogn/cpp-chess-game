#include <iostream>
#include "Position.h"
#include "Pieces.h"
#include <string>
using namespace std;

// Constructeur
Pieces::Pieces(Couleur c, const Position& p)
    : couleur(c), position(p)
{
}

// Destructeur
Pieces::~Pieces()
{
}

// Accesseurs
Couleur Pieces::getCouleur() const {
    return couleur;
}

Position Pieces::getPosition() const {
    return position;
}

// Modificateur
void Pieces::setPosition(const Position& p) {
    position = p;
}


