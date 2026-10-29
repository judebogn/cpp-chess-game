#include "Ordinateur.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <chrono>


Ordinateur::Ordinateur(Couleur c) : Joueur(c) {
    //srand(time(nu));
}


Ordinateur::~Ordinateur() {} // 🔴 SINON vtable cassée

bool Ordinateur::jouer(Plateau& plateau) {

    cout << "L'ordinateur réfléchit..." << endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    vector<pair<Position, Position>> coupsCapture;
    vector<pair<Position, Position>> coupsSimples;


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Position depart(i, j);
            Pieces* p = plateau.getPiece(depart);

            if (p && p->getCouleur() == couleur) {
                for (int r = 0; r < 8; ++r) {
                    for (int c = 0; c < 8; ++c) {
                        Position arrivee(r, c);
                          Pieces* cible = plateau.getPiece(arrivee);
                        if (plateau.coupValide(depart, arrivee)) {

                        if (cible&& cible->getCouleur() != couleur)
                        coupsCapture.push_back({depart, arrivee});
                      else
                        coupsSimples.push_back({depart, arrivee});
                        }
                    }
                }
            }
        }
    }

     // Aucun coup possible → échec et mat ou pat
    if (coupsCapture.empty() && coupsSimples.empty()) {
        return false;
    }

    // Priorité aux captures
    pair<Position, Position> coup;
    if (!coupsCapture.empty()) {
        coup = coupsCapture[rand() % coupsCapture.size()];
    } else {
        coup = coupsSimples[rand() % coupsSimples.size()];
    }

    plateau.deplacerPiece(coup.first, coup.second,2);
    return true;
}
