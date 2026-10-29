#include "Pion.h"

Pion::Pion(Couleur c, const Position& p) : Pieces(c, p) {}

bool Pion::coupLegal(const Position& dest) const {
    int dr = dest.getLigne() - position.getLigne();
    int dc = abs(dest.getColonne() - position.getColonne());

    int direction = (couleur == Couleur::Blanc) ? 1 : -1;

    // Avance simple
    if (dc == 0 && dr == direction)
        return true;

    // Avance de 2 cases (premier coup)
    if (dc == 0 && dr == 2 * direction &&
        ((couleur == Couleur::Blanc && position.getLigne() == 1) ||
         (couleur == Couleur::Noir && position.getLigne() == 6)))
        return true;

    // Capture diagonale (forme seulement)
    if (dc == 1 && dr == direction)
        return true;

    return false;
}


std::string Pion::getSymbole() const {
   return (couleur == Couleur::Blanc) ? "\u2659"  : "\u265F";
}

Pion::~Pion()
{

}


Pion& Pion::operator=(const Pion& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
