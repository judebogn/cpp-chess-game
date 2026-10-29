#ifndef FOU_H
#define FOU_H
#include <iostream>
#include "Position.h"
#include "Pieces.h"
#include <string>
using namespace std;

class Fou :public Pieces
{
    public:
        Fou();
        virtual ~Fou();
        Fou(const Fou& other);
        Fou& operator=(const Fou& other);

        Fou(Couleur c, const Position& p);

    bool coupLegal(const Position& destination) const override;
    std::string getSymbole() const override;

    protected:

    private:
};

#endif // FOU_H
