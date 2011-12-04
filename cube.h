#ifndef CUBE_H
#define CUBE_H

#include "define.h"
#include "liste.h"
#include <iostream>
#include <QString>

class Cube
{
public:
    Cube();
    Cube(unsigned int* tab);
    int getColor(int i) {return cube[i];}
    unsigned int* getCube() {return cube;}
    bool rotation(QChar r);
    void rotation(QString str);
    unsigned int getRotationCount() {return rotationCount;}
    void restartRotationCount() {rotationCount = 0;}

    Cube genRotation(QChar c);
    bool resolveFirstCross(QString* solution);
    bool resolveFirst1Cross(QString* solution);
    bool resolveFirst2Cross(QString* solution);
    bool resolveFirst3Cross(QString* solution);
    bool resolveFirstFace(QString* solution);
    bool resolveSecondEdge(QString* solution);
    bool resolveThirdCross(QString* solution);
    bool resolveThirdEdge(QString* solution);




private:
    unsigned int cube[54];
    unsigned int rotationCount;

    bool isResolveFirstCross();
    bool isResolveFirstFace();
    bool isResolveFirst1Cross();
    bool isResolveFirst2Cross();
    bool isResolveFirst3Cross();
    bool is8Corner();
    bool is6Corner();
    bool is0Corner();
    bool is2Corner();
    bool isEdgeOrange();
    bool isEdgeBlue();
    bool isEdgeGreen();
    bool isEdgeRed();

    bool rotation(liste l);

    bool isResolveSecondEdgeOrange();
    bool isResolveSecondEdgeGreen();
    bool isResolveSecondEdgeRed();
    bool isResolveSecondEdgeBlue();
    bool isResolveSecondEdge();


    bool isResolveThirdCross();
    bool isResolveThirdEdge();


};

#endif // CUBE_H
