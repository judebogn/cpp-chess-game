#include "Humain.h"
#include <iostream>

using namespace std;

Humain::Humain(Couleur c) : Joueur(c) {}

Humain::~Humain() {} // 🔴 SINON vtable cassée

bool Humain::jouer(Plateau& plateau) {


    std::string d, a;
    std::cout << "Entrez votre position de départ (ex e2) : ";
    std::cin >> d;
    std::cout << "Entrez position d'arrivée (ex e4) : ";
    std::cin >> a;

    Position dep(d), arr(a);
    std::string r, q;

    while(!dep.isValid() && !arr.isValid())
    {

    cout << "  Entrée de position non correcte ";

    std::cout << "Entrez votre position de départ (ex e2) : ";
    std::cin >> r;
    std::cout << "Entrez position d'arrivée (ex e4) : ";
    std::cin >> q;

    Position dep(r), arr(q);

    }

    Pieces* p = plateau.getPiece(dep);
    if (!p)
    {
       std::cout << "Il n'y a pas de pièces dans cette case\n";
        return false;
    }
    else if( p->getCouleur() != couleur) {
        std::cout << "\nCette pièce n'est pas la votre.\n";
        return false;
    }
    else
    {
    return plateau.deplacerPiece(dep, arr,1);
    }
}
