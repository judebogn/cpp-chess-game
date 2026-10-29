#include "Joueur.h"
#include <iostream>

using namespace std;


Joueur::Joueur(Couleur c) : couleur(c) {}

Joueur::~Joueur() {}

Couleur Joueur::getCouleur() const {
    return couleur;
}
