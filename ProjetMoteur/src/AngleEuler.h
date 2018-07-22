/**
* \file AngleEuler.h
* \author Killian Colin
*/

/**
* \class AngleEuler
* \brief AngleEuler is not currently use in the main.cpp
*/
#ifndef PROJETMOTEUR_ANGLEEULER_H
#define PROJETMOTEUR_ANGLEEULER_H


#include "MatrixC3.h"
class MatrixC3;
class Quaternion;

class AngleEuler {
private:
    float _h;
    float _p;
    float _b;
public:
    AngleEuler(float p,float h,float b);
    float getHeading();
    float getPitch();
    float getBank();
    void setHeading(float heading);
    void setPitch(float p);
    void setBank(float b);
    MatrixC3 toMatrix3();
    Quaternion toQuaternion();
    AngleEuler Lerp(AngleEuler efinal,float t);
    AngleEuler operator+(AngleEuler ae)const;
    AngleEuler operator-(AngleEuler ae)const;
    AngleEuler operator*(float d)const;
    AngleEuler operator/(float d)const;
    AngleEuler operator+(float d)const;
    AngleEuler operator-(float d)const;
    friend std::ostream& operator<<(std::ostream& out, AngleEuler ae);
};


#endif //PROJETMOTEUR_ANGLEEULER_H
