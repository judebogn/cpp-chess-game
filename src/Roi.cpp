#include "Roi.h"
#include <cmath>

using namespace std ;

Roi::Roi(Couleur c, const Position& p) : Pieces(c, p) {}

bool Roi::coupLegal(const Position& dest) const {
    int dr = abs(dest.getLigne() - position.getLigne());
    int dc = abs(dest.getColonne() - position.getColonne());
    return (dr <= 1 && dc <= 1 && (dr + dc != 0));
}

std::string Roi::getSymbole() const {
    return (couleur == Couleur::Blanc) ? "\u2654" : "\u265A";
}

Roi::~Roi()
{
    //dtor
}

//Roi::Roi(const Roi& other)
//{
    //copy ctor
//}

Roi& Roi::operator=(const Roi& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
