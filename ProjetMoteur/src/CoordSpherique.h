
#ifndef PROJETMOTEUR_COORDSPHERIQUE_H
#define PROJETMOTEUR_COORDSPHERIQUE_H


#include "Vector3f.h"


class Vector3f;

class CoordSpherique {
private:
    float _r;
    float _p;
    float _h;
public:
    CoordSpherique(float r,float p,float h);
    void setR(float r);
    void setP(float p);
    void setH(float h);
    float getR();
    float getP();
    float getH();
    Vector3f convertToVector();
    
};


#endif //PROJETMOTEUR_COORDSPHERIQUE_H
