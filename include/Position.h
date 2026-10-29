#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <string>
using namespace std ;

class Position {

public:
    // Constructeurs
    Position();                         // position invalide par défaut
    Position(int r, int c);             // à partir d’indices
    Position(const string& str);   // à partir de "e2"

    // Accesseurs
    int getLigne() const {return ligne;}
    int getColonne() const {return colonne ;}

    // Modificateurs
    void setLigne(int r);
    void setColonne(int c);

    // Validité
    bool isValid() const;

    // Conversions
    string toString() const;

    // Comparaisons
    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;

    private:
    int ligne; // 0 à 7 (ligne)
    int colonne; // 0 à 7 (colonne)

};

#endif // POSITION_H
