#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include "Position.h"

enum class Couleur {Blanc,Noir};

class Pieces {

public:
    // Constructeur
    Pieces(Couleur c, const Position& p);

    // Destructeur virtuel obligatoire pour une classe abstraite
    virtual ~Pieces();

    // Accesseurs
    Couleur getCouleur() const;
    Position getPosition() const;

    // Modificateur
    void setPosition(const Position& p);

    // Méthodes abstraites
    virtual bool coupLegal(const Position& destination) const = 0;
    virtual std::string getSymbole() const = 0;


    protected:
    Couleur couleur;
    Position position;
};

#endif // PIECE_H
