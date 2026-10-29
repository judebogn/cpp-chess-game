#ifndef TOUR_H
#define TOUR_H

#include <iostream>
#include "Position.h"
#include "Pieces.h"
#include <string>
using namespace std;
class Tour : public Pieces
{
    public:
        Tour();
        virtual ~Tour();
        Tour(const Tour& other);
        Tour& operator=(const Tour& other);
        Tour(Couleur c, const Position& p);

    bool coupLegal(const Position& destination) const override;
    std::string getSymbole() const override;


    protected:

    private:
};

#endif // TOUR_H
