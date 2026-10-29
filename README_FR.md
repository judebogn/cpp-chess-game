# Jeu d’échecs en C++

Jeu d’échecs en ligne de commande développé en C++ dans le cadre de l’UE **Programmation orientée objet**, en Master 1 Mathématiques appliquées – parcours Modélisation statistique, à l’Université Marie et Louis Pasteur de Besançon (année universitaire 2025–2026).

Ce projet met en pratique la conception orientée objet, le polymorphisme, la représentation d’un plateau, la validation des déplacements et la création d’un adversaire informatique élémentaire.

> **Projet universitaire :** il s’agit d’un projet d’apprentissage, et non d’un moteur d’échecs complet. Certaines règles officielles et conditions de nullité ne sont pas implémentées ; voir la section [Limites connues](#limites-connues).

## Fonctionnalités

La version rendue comprend :

- **Trois modes de jeu**
  - Humain contre humain
  - Humain contre ordinateur
  - Ordinateur contre ordinateur
- **Choix de la couleur** en mode humain contre ordinateur.
- **Affichage textuel** du plateau dans le terminal, avec des symboles Unicode pour les pièces.
- **Classes dédiées** au roi, à la dame, à la tour, au fou, au cavalier et au pion.
- **Logique de validation des coups** portant notamment sur les déplacements des pièces, les cases occupées, les pièces qui bloquent le chemin et les coups qui laisseraient son propre roi en échec.
- **Vérifications de fin de partie**, notamment l’échec et mat, le pat et quelques cas de matériel insuffisant.
- **Promotion du pion** en dame, tour, fou ou cavalier.
- **Adversaire informatique :** recherche les coups légaux, donne la priorité aux captures, puis choisit aléatoirement parmi les coups candidats disponibles.
- Une limite de coups pour éviter que les parties ordinateur contre ordinateur ne se poursuivent indéfiniment.

## Technologies

- C++
- Programmation orientée objet (POO)
- Projet Code::Blocks (`.cbp`)
- Bibliothèque standard C++

## Structure du projet

```text
cpp-chess-game/
├── main.cpp
├── Projet-Echec.cbp
├── include/
│   ├── Pieces.h
│   ├── Position.h
│   ├── Plateau.h
│   ├── Joueur.h
│   ├── Humain.h
│   ├── Ordinateur.h
│   ├── Jeu.h
│   └── en-têtes propres aux pièces
└── src/
    └── fichiers d’implémentation C++
```

Les noms des classes et des méthodes sont conservés en français, conformément au projet universitaire d’origine.

## Compiler et lancer le jeu

### Option 1 — Code::Blocks

1. Ouvrir `Projet-Echec.cbp` dans Code::Blocks.
2. Sélectionner la cible `Debug` ou `Release`.
3. Compiler puis exécuter le projet.

### Option 2 — Depuis un terminal

Un compilateur C++ compatible avec C++11 est nécessaire. Depuis la racine du dépôt :

```bash
g++ -std=c++11 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o chess
./chess
```

Sous Windows, l’exécutable peut être nommé `chess.exe` :

```bash
g++ -std=c++11 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o chess.exe
.\chess.exe
```

Le terminal doit prendre en charge les caractères Unicode pour afficher correctement les symboles des pièces.

## Comment jouer

Au démarrage, choisir l’un des modes :

- `A` — Humain contre humain
- `B` — Humain contre ordinateur
- `C` — Ordinateur contre ordinateur

En mode humain contre ordinateur, choisir de jouer avec les Blancs ou les Noirs. Saisir ensuite la case de départ et la case d’arrivée, par exemple :

```text
Case de départ : e2
Case d’arrivée : e4
```

Le plateau est réaffiché après les coups acceptés.

## Conception orientée objet

Les principales classes sont :

- **`Pieces`** — classe abstraite qui stocke la couleur et la position d’une pièce et définit les interfaces virtuelles `coupLegal()` et `getSymbole()`.
- **`Roi`, `Dame`, `Tour`, `Fou`, `Cavalier`, `Pion`** — classes dérivées qui implémentent les déplacements propres aux pièces et leurs symboles.
- **`Position`** — représente une case et convertit une notation comme `e2` en indices de ligne et de colonne.
- **`Plateau`** — représente l’échiquier 8×8, initialise et affiche les pièces, et contient la logique de validation des coups et de fin de partie.
- **`Joueur`** — classe abstraite commune aux types de joueurs.
- **`Humain`** — récupère les coups saisis dans le terminal.
- **`Ordinateur`** — choisit un coup parmi les candidats légaux, en privilégiant les captures.
- **`Jeu`** — gère la boucle de jeu, l’alternance des joueurs et les vérifications de fin de partie.

Le plateau repose sur un tableau 8×8 de pointeurs vers `Pieces`. Cette représentation permet de stocker les différentes classes dérivées à travers une même classe de base.

## Limites connues

Le projet implémente une partie des règles des échecs et ne doit pas être considéré comme un moteur d’échecs pleinement conforme aux règles officielles.

- Le roque n’est pas implémenté.
- La prise en passant n’est pas implémentée.
- La détection des nullités est limitée aux cas explicitement traités dans le code ; la répétition de position et la règle des cinquante coups ne sont pas implémentées.
- L’ordinateur utilise une stratégie élémentaire de sélection des coups, sans algorithme de recherche ni évaluation stratégique.
- Aucun jeu de tests automatisés n’est fourni dans le projet rendu.

Ces limites constituent des pistes d’amélioration : couverture plus complète des règles, tests unitaires, historique des parties et stratégie informatique plus élaborée.

## Contexte universitaire

- **UE :** Programmation orientée objet
- **Formation :** M1 Mathématiques appliquées – Modélisation statistique
- **Année universitaire :** 2025–2026
- **Établissement :** Université Marie et Louis Pasteur, Besançon, France

## Langue

[English version](README.md)
