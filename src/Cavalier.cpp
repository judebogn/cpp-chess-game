#include "Cavalier.h"
#include <cmath>

Cavalier::Cavalier(Couleur c, const Position& p) : Pieces(c, p) {}

bool Cavalier::coupLegal(const Position& dest) const {
    int dr = std::abs(dest.getLigne() - position.getLigne());
    int dc = std::abs(dest.getColonne() - position.getColonne());
    return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
}

std::string Cavalier::getSymbole() const {
    return (couleur == Couleur::Blanc) ? "\u2658" : "\u265E";
}

Cavalier::~Cavalier()
{
    //dtor
}

//Cavalier::Cavalier(const Cavalier& other)
//{
    //copy ctor
//}

Cavalier& Cavalier::operator=(const Cavalier& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
