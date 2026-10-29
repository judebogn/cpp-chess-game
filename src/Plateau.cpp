#include "Plateau.h"

// Affichage du plateau
void Plateau::afficher() const {
    string ligneSep = "--------------------------------";
    cout << endl << "\t"+ligneSep << endl;
    for (int r = 7; r >= 0; --r) {
        cout << r + 1 << "\t|";
        for (int c = 0; c < 8; ++c) {
            if (cases[r][c])
                cout << cases[r][c]->getSymbole() << " | ";
            else

                cout << "  | ";
        }
        cout << endl << "\t"+ligneSep << endl;
    }
    cout << "\t a   b   c   d   e   f   g   h " << endl<< endl;
}



// =======================
// Constructeur
// =======================
Plateau::Plateau() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cases[i][j] = nullptr;

    initialiser();
}

// =======================
// Destructeur
// =======================
Plateau::~Plateau() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            delete cases[i][j];
}

// =======================
// Accès à une pièce
// =======================
Pieces* Plateau::getPiece(const Position& p) const {
    if (!p.isValid()) return nullptr;
    return cases[p.getLigne()][p.getColonne()];
}

// =======================
// Placement d'une pièce
// =======================
void Plateau::placerPiece(Pieces* piece, const Position& p) {
    if (!p.isValid()) return;
    cases[p.getLigne()][p.getColonne()] = piece;
    piece->setPosition(p);
}


// =======================
// Vérification chemin libre
// =======================
bool Plateau::cheminLibre(const Position& dep, const Position& arr) const {
    int dr = arr.getLigne() - dep.getLigne();
    int dc = arr.getColonne() - dep.getColonne();

    int stepR = (dr == 0) ? 0 : (dr > 0 ? 1 : -1);
    int stepC = (dc == 0) ? 0 : (dc > 0 ? 1 : -1);

    int r = dep.getLigne() + stepR;
    int c = dep.getColonne() + stepC;

    while (r != arr.getLigne() || c != arr.getColonne()) {
        if (cases[r][c] != nullptr)
            return false;
        r += stepR;
        c += stepC;
    }
    return true;
}

// =======================
// Déplacement d'une pièce
// =======================
bool Plateau::deplacerPiece(
    const Position& depart,
    const Position& arrivee , int i
) {
    if (!coupValide(depart, arrivee))
        return false;

    Pieces* p = getPiece(depart);
    Pieces* cible = getPiece(arrivee);

    if (cible) delete cible;

    cases[arrivee.getLigne()][arrivee.getColonne()] = p;
    cases[depart.getLigne()][depart.getColonne()] = nullptr;
    p->setPosition(arrivee);

    // Promotion
    gererPromotion(p,i);

    return true;
}
bool Plateau::estEnEchec(Couleur couleur) {
    Position posRoi;
    bool roiTrouve = false;

    // 1️⃣ Trouver le roi de la couleur donnée
    for (int i = 0; i < 8 && !roiTrouve; ++i) {
        for (int j = 0; j < 8; ++j) {
            Pieces* p = cases[i][j];
            if (p && p->getCouleur() == couleur) {
                // On teste dynamiquement si c'est un Roi
                if (dynamic_cast<Roi*>(p)) {
                    posRoi = p->getPosition();
                    roiTrouve = true;
                    break;
                }
            }
        }
    }

    if (!roiTrouve) return false; // sécurité

    // 2️⃣ Vérifier si une pièce adverse attaque le roi
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Pieces* p = cases[i][j];
            if (p && p->getCouleur() != couleur) {
                if (coupValide(p->getPosition(),posRoi)) {
                    return true; // le roi est attaqué
                }
            }
        }
    }

    return false;
}

bool Plateau::estEchecEtMat(Couleur couleur) {
    // 1️⃣ Si le roi n'est pas en échec → pas mat
    if (!estEnEchec(couleur))
        return false;

    // 2️⃣ Tester TOUS les coups possibles du joueur
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Pieces* p = cases[i][j];
            if (p && p->getCouleur() == couleur) {

                Position depart = p->getPosition();

                // Essayer toutes les cases du plateau
                for (int r = 0; r < 8; ++r) {
                    for (int c = 0; c < 8; ++c) {
                        Position arrivee(r, c);

                      if (!p->coupLegal(arrivee))
                         continue;

                        if (!coupValide(depart,arrivee))
                            continue;

                        // Sauvegarde
                        Pieces* pieceCapturee = cases[r][c];

                        // Simulation du coup
                        cases[depart.getLigne()][depart.getColonne()] = nullptr;
                        cases[r][c] = p;
                        p->setPosition(arrivee);

                        bool toujoursEnEchec = estEnEchec(couleur);

                        // Annulation du coup
                        p->setPosition(depart);
                        cases[depart.getLigne()][depart.getColonne()] = p;
                        cases[r][c] = pieceCapturee;

                        if (!toujoursEnEchec)
                            return false; // il existe un coup pour sauver le roi
                    }
                }
            }
        }
    }

    // 3️⃣ Aucun coup possible → échec et mat
    return true;
}


bool Plateau::matchnul1(Couleur couleur) {
    // 1️⃣ Si le roi est en échec échec → pas de nul
    if (estEnEchec(couleur))
        return false;

    // 2️⃣ Tester TOUS les coups possibles du joueur
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Pieces* p = cases[i][j];
            if (p && p->getCouleur() == couleur) {

                Position depart = p->getPosition();

                // Essayer toutes les cases du plateau
                for (int r = 0; r < 8; ++r) {
                    for (int c = 0; c < 8; ++c) {
                        Position arrivee(r, c);

                      if (!p->coupLegal(arrivee))
                         continue;

                        if (!coupValide(depart,arrivee))
                            continue;

                        // Sauvegarde
                        Pieces* pieceCapturee = cases[r][c];

                        // Simulation du coup
                        cases[depart.getLigne()][depart.getColonne()] = nullptr;
                        cases[r][c] = p;
                        p->setPosition(arrivee);

                        bool toujoursEnEchec = estEnEchec(couleur);

                        // Annulation du coup
                        p->setPosition(depart);
                        cases[depart.getLigne()][depart.getColonne()] = p;
                        cases[r][c] = pieceCapturee;

                        if (!toujoursEnEchec)
                            return false; // il existe un coup pour sauver le roi
                    }
                }
            }
        }
    }

    // 3️⃣ Aucun coup possible → échec et mat
    return true;
}

bool Plateau::matchnul2() const {
    int nbPieces = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (cases[i][j]) {
                // Si ce n'est pas un roi → matériel suffisant
                if (!dynamic_cast<Roi*>(cases[i][j]))
                    return false;
                nbPieces++;
            }
        }
    }

    return nbPieces == 2; // Roi blanc + Roi noir
}

bool Plateau::matchnul3() const {
    int nbRois = 0;
    int nbFous = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (cases[i][j]) {

                if (dynamic_cast<Roi*>(cases[i][j])) {
                    nbRois++;
                }
                else if (dynamic_cast<Fou*>(cases[i][j])) {
                    nbFous++;
                }
                else {
                    // Toute autre pièce rend le mat possible
                    return false;
                }
            }
        }
    }

    return (nbRois == 2 && nbFous == 1);
}


bool Plateau::matchnul4() const {
    int nbRois = 0;
    int nbCavaliers = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (cases[i][j]) {

                if (dynamic_cast<Roi*>(cases[i][j])) {
                    nbRois++;
                }
                else if (dynamic_cast<Cavalier*>(cases[i][j])) {
                    nbCavaliers++;
                }
                else {
                    return false;
                }
            }
        }
    }

    return (nbRois == 2 && nbCavaliers == 1);
}



void Plateau::gererPromotion(Pieces* p, int i) {
   Pion* pion = dynamic_cast<Pion*>(p);
    if (!pion) return;

    int ligne = p->getPosition().getLigne();

    if ((p->getCouleur() == Couleur::Blanc && ligne == 7) ||
        (p->getCouleur() == Couleur::Noir && ligne == 0)) {

        Position pos = p->getPosition();
        Couleur c = p->getCouleur();

        delete p;

        //  CAS HUMAIN
        if (i==1) {
            int  choix;
            cout << "\n\n Votre pion a atteint la dernière ligne du plateau \n\n.";
           cout << " Vous allez donc le remplacer par une de ses pièces de votre choix \n \n";

          cout << " Tapez : \n \n  1 pour  Tour \u2656  \n 2 pour FOU \u2657 \n 3 pour Cavalier \u2658 \n 4 pour Dame \u2655 : \n";
            cin >> choix;

            switch (choix) {
                case 1: cases[pos.getLigne()][pos.getColonne()] = new Tour(c, pos); break;
                case 2: cases[pos.getLigne()][pos.getColonne()] = new Fou(c, pos); break;
                case 3: cases[pos.getLigne()][pos.getColonne()] = new Cavalier(c, pos); break;
                case 4:
                default:  cases[pos.getLigne()][pos.getColonne()] = new Dame(c, pos);
            }
        }
        // 👇 CAS ORDINATEUR
        else {
            int r = rand() % 100;

            if (r < 70)
                cases[pos.getLigne()][pos.getColonne()] = new Dame(c, pos);   // 70%
            else if (r < 80)
                cases[pos.getLigne()][pos.getColonne()] = new Tour(c, pos);   // 10%
            else if (r < 90)
                cases[pos.getLigne()][pos.getColonne()] = new Fou(c, pos);    // 10%
            else
                cases[pos.getLigne()][pos.getColonne()] = new Cavalier(c, pos); // 10%
        }
    }
}





// =======================
// Initialisation du jeu
// =======================
void Plateau::initialiser() {
    // Blancs
    placerPiece(new Tour(Couleur::Blanc, Position("a1")), Position("a1"));
    placerPiece(new Cavalier(Couleur::Blanc, Position("b1")), Position("b1"));
    placerPiece(new Fou(Couleur::Blanc, Position("c1")), Position("c1"));
    placerPiece(new Dame(Couleur::Blanc, Position("d1")), Position("d1"));
    placerPiece(new Roi(Couleur::Blanc, Position("e1")), Position("e1"));
    placerPiece(new Fou(Couleur::Blanc, Position("f1")), Position("f1"));
    placerPiece(new Cavalier(Couleur::Blanc, Position("g1")), Position("g1"));
    placerPiece(new Tour(Couleur::Blanc, Position("h1")), Position("h1"));

    for (char c = 'a'; c <= 'h'; ++c)
        placerPiece(new Pion(Couleur::Blanc, Position(string(1, c) + "2")),
                    Position(string(1, c) + "2"));

    // Noirs
    placerPiece(new Tour(Couleur::Noir, Position("a8")), Position("a8"));
    placerPiece(new Cavalier(Couleur::Noir, Position("b8")), Position("b8"));
    placerPiece(new Fou(Couleur::Noir, Position("c8")), Position("c8"));
    placerPiece(new Dame(Couleur::Noir, Position("d8")), Position("d8"));
    placerPiece(new Roi(Couleur::Noir, Position("e8")), Position("e8"));
    placerPiece(new Fou(Couleur::Noir, Position("f8")), Position("f8"));
    placerPiece(new Cavalier(Couleur::Noir, Position("g8")), Position("g8"));
    placerPiece(new Tour(Couleur::Noir, Position("h8")), Position("h8"));

    for (char c = 'a'; c <= 'h'; ++c)
        placerPiece(new Pion(Couleur::Noir, Position(string(1, c) + "7")),
                    Position(string(1, c) + "7"));
}


bool Plateau::coupValide(
    const Position& depart,
    const Position& arrivee
) {
    Pieces* p = getPiece(depart);
    if (!p) return false;


    // 2️⃣ Mouvement légal pour la pièce
    if (!p->coupLegal(arrivee)) return false;

    // 3️⃣ Pas de capture alliée
    Pieces* cible = getPiece(arrivee);
    if (cible && cible->getCouleur() == p->getCouleur())
        return false;


    // Cas du pion
    if (dynamic_cast<Pion*>(p)) {
        int dc = abs(arrivee.getColonne() - depart.getColonne());

        // Avance droite → case doit être vide
        if (dc == 0 && cible != nullptr)
            return false;

        // Capture diagonale → pièce adverse obligatoire
        if (dc == 1 && (cible == nullptr || cible->getCouleur() == p->getCouleur()))
            return false;
    }

    // Autres pièces : pas de saut (sauf cavalier)
    if (!dynamic_cast<Cavalier*>(p)) {
        if (!cheminLibre(depart, arrivee))
            return false;
    }


    // 4️⃣ Simulation du coup (IMPORTANT)
    Pieces* sauvegarde = cible;
    Position posOrigine = p->getPosition();

    cases[arrivee.getLigne()][arrivee.getColonne()] = p;
    cases[depart.getLigne()][depart.getColonne()] = nullptr;
    p->setPosition(arrivee);

    bool roiEnDanger = estEnEchec(p->getCouleur());

    // 🔙 Annulation du coup
    cases[depart.getLigne()][depart.getColonne()] = p;
    cases[arrivee.getLigne()][arrivee.getColonne()] = sauvegarde;
    p->setPosition(posOrigine);
    return !roiEnDanger;
}


