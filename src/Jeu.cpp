#include "Jeu.h"
#include <iostream>

using namespace std;


Jeu::Jeu(Joueur* b, Joueur* n)
    : blanc(b), noir(n), courant(b) {}

Jeu::~Jeu() {
    delete blanc;
    delete noir;
}

void Jeu::lancer() {
    plateau.afficher();
    while (true) {

            if (compteur>=1000) {
            cout << "\nMatch nul (limite de coups atteinte).\n";
            break;
             }

            else{

        std::cout << "\nTour "
                  << ((courant->getCouleur() == Couleur::Blanc) ? "Blanc" : "Noir")
                  << std::endl;

        bool joue = courant->jouer(plateau);



        if (joue) {

            plateau.afficher();

            Couleur couleurAdverse =
            (courant->getCouleur() == Couleur::Blanc)
                ? Couleur::Noir
                : Couleur::Blanc;

        //  TEST ÉCHEC ET MAT
        if (plateau.estEchecEtMat(couleurAdverse)) {
            cout << "\n♚ ÉCHEC ET MAT ♚\n";
            cout << "Victoire des "
                 << ((courant->getCouleur() == Couleur::Blanc) ? "Blancs" : "Noirs")
                 << " !\n";

                 plateau.afficher();
            break; // FIN DU JEU
        }
        else if (plateau.matchnul1(couleurAdverse)) {
            cout << " Ouf !!! Match nul \n";
            cout << " Ceci est un Pat. Pas de victoire. Le roi adverse n'est pas en échec mais n'a plus d'autre coup légal \n\n";

            plateau.afficher();
            break; // FIN DU JEU
        }
        else if (plateau.matchnul2()) {
            cout << " Ouf !!! Match nul \n";
            cout << " Il n'y a plus de possibilité de victoire dans ce jeu \n\n";
            cout << " Il s'agit d'un roi contre un roi \n\n";
            plateau.afficher();
            break; // FIN DU JEU
        }
          else if (plateau.matchnul3()) {
            cout << " Ouf !!! Match nul \n";
            cout << " Il n'y a plus de possibilité de victoire dans ce jeu \n\n";
             cout << " Il s'agit d'un roi contre un roi et un fou \n\n";
            plateau.afficher();
            break; // FIN DU JEU
        }
          else if (plateau.matchnul4()) {
            cout << " Ouf !!! Match nul \n";
            cout << " Il n'y a plus de possibilité de victoire dans ce jeu \n\n";
            cout << " Il s'agit d'un roi contre un roi et un chevalier \n\n";
            plateau.afficher();
            break; // FIN DU JEU
        }


            // 🔁 ALTERNANCE CORRECTE
            courant = (courant == blanc) ? noir : blanc;



        }


         else {
            cout << "Coup non valide, rejouez.\n";
        }
    }
    compteur=compteur+1;
    }

}

