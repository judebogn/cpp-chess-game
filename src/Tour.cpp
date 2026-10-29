#include "Tour.h"

Tour::Tour(Couleur c, const Position& p) : Pieces(c, p) {}

bool Tour::coupLegal(const Position& dest) const {
    return (dest.getLigne() == position.getLigne() ||
            dest.getColonne() == position.getColonne());
}

std::string Tour::getSymbole() const {
    return (couleur == Couleur::Blanc) ? "\u2656" : "\u265C";
}


Tour::~Tour()
{
    //dtor
}

//Tour::Tour(const Tour& other)
//{
    //copy ctor
//}

Tour& Tour::operator=(const Tour& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
