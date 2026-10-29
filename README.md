# C++ Chess Game

A command-line chess game written in C++ for the Object-Oriented Programming course in the first year of the Master's degree in Statistical Modelling (2025–2026) at Université Marie et Louis Pasteur, Besançon, France.

The project explores object-oriented design, polymorphism, board representation, move validation, and a basic computer opponent.

> **Academic project:** this is a learning project, not a complete chess engine. Some official chess rules and draw conditions are not implemented; see [Limitations](#limitations).

## Features

The submitted version includes the following features:

- **Three game modes**
  - Human vs. human
  - Human vs. computer
  - Computer vs. computer
- **Colour selection** in human-vs-computer mode.
- **Text-based board** displayed in the terminal, using Unicode chess symbols.
- **Piece classes** for the king, queen, rook, bishop, knight, and pawn.
- **Move validation logic** for piece movement, occupied squares, blocking pieces, and moves that would leave the moving side's king in check.
- **Basic end-of-game checks**, including checkmate, stalemate, and a few insufficient-material cases.
- **Pawn promotion** to a queen, rook, bishop, or knight.
- **Computer opponent:** searches for legal moves, gives priority to captures, then selects a move randomly from the available candidates.
- A maximum-move limit to prevent computer-vs-computer games from running indefinitely.

## Technologies

- C++
- Object-oriented programming (OOP)
- Code::Blocks project (`.cbp`)
- Standard C++ library

## Project structure

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
│   └── piece-specific headers
└── src/
    └── C++ implementation files
```

The source code uses French class and method names, reflecting the language of the original academic project.

## Build and run

### Option 1 — Code::Blocks

1. Open `Projet-Echec.cbp` in Code::Blocks.
2. Select the `Debug` or `Release` target.
3. Build and run the project.

### Option 2 — Compile from a terminal

A C++ compiler with C++11 support is required. From the repository root, run:

```bash
g++ -std=c++11 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o chess
./chess
```

On Windows, the generated executable can be named `chess.exe`:

```bash
g++ -std=c++11 -Wall -Wextra -Iinclude main.cpp src/*.cpp -o chess.exe
.\chess.exe
```

The terminal should support Unicode characters for the chess-piece symbols to display correctly.

## How to play

When the program starts, select one of the available modes:

- `A` — Human vs. human
- `B` — Human vs. computer
- `C` — Computer vs. computer

In human-vs-computer mode, choose whether to play as White or Black. Enter a move using algebraic square coordinates, for example:

```text
Starting square: e2
Destination square: e4
```

The board is displayed again after accepted moves.

## Object-oriented design

The main classes are:

- **`Pieces`** — abstract base class storing a piece's colour and position. It defines the virtual interfaces `coupLegal()` and `getSymbole()`.
- **`Roi`, `Dame`, `Tour`, `Fou`, `Cavalier`, `Pion`** — piece-specific subclasses implementing movement patterns and display symbols.
- **`Position`** — represents a board coordinate and converts algebraic notation such as `e2` into internal row and column indices.
- **`Plateau`** — represents the 8×8 board, initializes the pieces, displays the board, and contains move-validation and endgame logic.
- **`Joueur`** — abstract base class for players.
- **`Humain`** — reads moves from the terminal.
- **`Ordinateur`** — selects a move from the available legal candidates, prioritizing captures.
- **`Jeu`** — manages the game loop, player turns, and end-of-game checks.

The board is represented by an 8×8 array of pointers to `Pieces`, which allows the board to store different derived piece types through a common base class.

## Limitations

This project implements a subset of chess rules and should not be considered a fully compliant chess engine.

- Castling is not implemented.
- En passant is not implemented.
- Draw detection is limited to the cases explicitly handled in the code; repetition and the fifty-move rule are not implemented.
- The computer opponent uses a basic move-selection heuristic rather than a search algorithm or strategic evaluation.
- No automated test suite is included in the submitted project.

These limitations provide possible directions for future improvements, including more comprehensive rule coverage, unit tests, game-history support, and stronger computer strategies.

## Academic context

- **Course:** Object-Oriented Programming
- **Programme:** M1 Mathematical Modelling and Statistics
- **Academic year:** 2025–2026
- **Institution:** Université Marie et Louis Pasteur, Besançon, France

## Language

[Version française](README_FR.md)
