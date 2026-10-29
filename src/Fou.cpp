#include "Fou.h"
#include <cmath>

Fou::Fou(Couleur c, const Position& p) : Pieces(c, p) {}

bool Fou::coupLegal(const Position& dest) const {
    int dr = std::abs(dest.getLigne() - position.getLigne());
    int dc = std::abs(dest.getColonne() - position.getColonne());
    return dr == dc;
}

std::string Fou::getSymbole() const {
    return (couleur == Couleur::Blanc) ? "\u2657" : "\u265D";
}

Fou::~Fou()
{
    //dtor
}

//Fou::Fou(const Fou& other)
//{
    //copy ctor
//}

Fou& Fou::operator=(const Fou& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
