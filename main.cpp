#include <iostream>
#include "Position.h"
#include "Pieces.h"
#include "Roi.h"
#include "Dame.h"
#include "Pion.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Plateau.h"
#include "Humain.h"
#include "Ordinateur.h"
#include "Jeu.h"
#include <string>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
  #ifdef _WIN32
    system("chcp 65001"); // Windows uniquement
  #endif

 cout << "\n\n=========================================\n\n";
    cout << "      ♟️  JEU D'ECHECS - C++ (POO) ♟️      \n\n";
    cout << "=========================================\n";
    cout << "\nProjet M1 - Modelisation Statistique\n\n";
    cout << "UE : Programmation Orientee Objet\n\n";
    cout << "=========================================\n";

    cout << "\nChoisissez le mode de jeu :\n\n";
    cout << " A - Humain contre Humain\n\n";
    cout << " B - Humain contre Ordinateur\n\n";
    cout << " C - Ordinateur contre Ordinateur\n\n";
    cout << "\nVotre choix : ";

    char choix;
    cin >> choix;

    Joueur* blanc = nullptr;
    Joueur* noir  = nullptr;

    switch (choix) {
    case 'A':
    case 'a':
        cout << "\nMode : Humain contre Humain\n";
        blanc = new Humain(Couleur::Blanc);
        noir  = new Humain(Couleur::Noir);
        break;

    case 'B':
    case 'b': {
        cout << "\n\nMode : Humain contre Ordinateur\n\n";
        cout << "Choisissez votre couleur :\n\n";
        cout << " 1 - Blanc (vous commencez)\n\n";
        cout << " 2 - Noir  (l'ordinateur commence)\n\n";
        cout << "Votre choix : ";

        int c;
        cin >> c;

        if (c == 1) {
            blanc = new Humain(Couleur::Blanc);
            noir  = new Ordinateur(Couleur::Noir);
        } else {
            blanc = new Ordinateur(Couleur::Blanc);
            noir  = new Humain(Couleur::Noir);
        }
        break;
    }

    case 'C':
    case 'c':
        cout << "\nMode : Ordinateur contre Ordinateur\n";
        cout << "Les coups seront joues automatiquement.\n";
        blanc = new Ordinateur(Couleur::Blanc);
        noir  = new Ordinateur(Couleur::Noir);
        break;

    default:
        cout << "\n❌ Choix invalide. Fin du programme.\n";
        return 0;
    }

    cout << "\nInitialisation du jeu...\n\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    Jeu jeu(blanc, noir);
    jeu.lancer();

    cout << "\nMerci d'avoir joue ! ♟️\n";
    return 0;
}

