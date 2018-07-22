/**
* \file Quaternion.h
* \author Killian Colin
*/

/**
* \class Quaternion
* \brief Quaternion is not currently use in the main.cpp
*/
#ifndef PROJETMOTEUR_QUATERNION_H
#define PROJETMOTEUR_QUATERNION_H


#include "Vector3f.h"
#include "MatrixC3.h"

class Vector3f;
class MatrixC3;
class AngleEuler;

class Quaternion {
private:
    float _w;
    Vector3f _v;
public:
    Quaternion();
    Quaternion(float w,Vector3f v);
    Quaternion(Vector3f n,float teta);
    void setW(float w);
    void setV( Vector3f v);
    float getW()const;
    Vector3f getV()const;
    float magnitude()const;
    float magnitudePow()const;
    Quaternion conjug()const;
    Quaternion inverse()const;
    Quaternion log()const;
    Quaternion exp()const;
    float angleAlpha()const;
    MatrixC3 toMatrix()const;
    AngleEuler toEuler()const;
    void operator/=(float f);
    Quaternion difference(Quaternion const& q1)const;
    Quaternion slerp(Quaternion const& q1,float t);
    float scalaire(Quaternion const& q1);
    friend std::ostream& operator<<(std::ostream& out, Quaternion q);
    Quaternion operator+(Quaternion const& v2)const;
    friend Quaternion operator-(Quaternion const& q1);
    friend Quaternion operator*(Quaternion const& q1,float f);
    friend Quaternion operator/(Quaternion const& q1,float f);
    friend Quaternion operator*(Quaternion const& q1,Quaternion const& q2);
};


#endif //PROJETMOTEUR_QUATERNION_H
