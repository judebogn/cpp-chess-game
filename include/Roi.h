#ifndef ROI_H
#define ROI_H
#include <iostream>
#include "Position.h"
#include "Pieces.h"
#include <string>

using namespace std;

class Roi : public Pieces
{
    public:

        Roi(Couleur c, const Position& p);
        virtual ~Roi();
        Roi(const Roi& other);
        Roi& operator=(const Roi& other);


    bool coupLegal(const Position& destination) const override;
    string getSymbole() const override;

    protected:

    private:
};

#endif // ROI_H
