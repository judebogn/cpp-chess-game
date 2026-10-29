#include "Dame.h"
#include <cmath>

Dame::Dame(Couleur c, const Position& p) : Pieces(c, p) {}

bool Dame::coupLegal(const Position& dest) const {
    int dr = std::abs(dest.getLigne() - position.getLigne());
    int dc = std::abs(dest.getColonne() - position.getColonne());

    return (dr == dc || dr == 0 || dc == 0);
}

std::string Dame::getSymbole() const {
    return (couleur == Couleur::Blanc) ? "\u2655" : "\u265B";
}
Dame::~Dame()
{
    //dtor
}

//Dame::Dame(const Dame& other)
//{
    //copy ctor
//}

Dame& Dame::operator=(const Dame& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
