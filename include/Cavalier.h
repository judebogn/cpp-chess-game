#ifndef CAVALIER_H
#define CAVALIER_H

#include <iostream>
#include "Position.h"
#include "Pieces.h"
#include <string>
using namespace std;
class Cavalier :  public Pieces
{
    public:
        Cavalier();
        virtual ~Cavalier();
        Cavalier(const Cavalier& other);
        Cavalier& operator=(const Cavalier& other);
        Cavalier(Couleur c, const Position& p);

    bool coupLegal(const Position& destination) const override;
    std::string getSymbole() const override;


    protected:

    private:
};

#endif // CAVALIER_H
