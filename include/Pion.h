#ifndef PION_H
#define PION_H
#include <iostream>
#include "Position.h"
#include "Pieces.h"
#include <string>
using namespace std;

class Pion :public Pieces
{
    public:
        Pion();
        virtual ~Pion();
        Pion(const Pion& other);
        Pion& operator=(const Pion& other);

        Pion(Couleur c, const Position& p);

    bool coupLegal(const Position& destination) const override;
    string getSymbole() const override;


    protected:

    private:
};

#endif // PION_H
