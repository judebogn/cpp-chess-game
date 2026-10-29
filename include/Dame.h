#ifndef DAME_H
#define DAME_H
#include <iostream>
#include "Position.h"
#include "Pieces.h"
#include <string>
using namespace std;

class Dame : public Pieces
{
    public:
        Dame(Couleur c, const Position& p);
        virtual ~Dame();
        Dame(const Dame& other);
        Dame& operator=(const Dame& other);


    bool coupLegal(const Position& destination) const override;
    std::string getSymbole() const override;

    protected:

    private:
};

#endif // DAME_H
