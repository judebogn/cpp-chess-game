#include "Position.h"
#include <iostream>
#include <string>
using namespace std ;

// Constructeur par défaut : position invalide
Position::Position() : ligne(-1), colonne(-1) {}

// Constructeur par coordonnées
Position::Position(int r, int c) : ligne(r), colonne(c) {}

// Constructeur depuis "e2"
Position::Position(const string& pos)  {
    if (pos.size() != 2)
    {

    cout<< "Entré de position incorrecte"<< endl;
        return;
    }
    else
    {


    char lettre = pos[0]; // colonne (a-h)
    char numero = pos[1]; // ligne (1-8)

     if (lettre >= 'A' && lettre<= 'Z') {
        lettre = lettre + ('a' - 'A');
    }

    if (lettre >= 'a' && lettre <= 'h' &&
        numero >= '1' && numero <= '8') {

        colonne = lettre - 'a';
        ligne = numero - '1';
    }
    }
}


bool Position::isValid() const {
    return ligne >= 0 && ligne < 8 && colonne >= 0 && colonne < 8;
}

void Position::setLigne(int r)
{
    ligne=r;
}


void Position::setColonne(int r)
{
    colonne=r;
}


string Position::toString() const {
    if (!isValid())
        return "--";

    string s;
    s += char('a' + colonne);
    s += char('1' + ligne);
    return s;
}

bool Position::operator==(const Position& other) const {
    return ligne == other.ligne && colonne == other.colonne;
}

bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}
