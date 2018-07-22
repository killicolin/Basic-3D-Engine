/**
* \file Vector3f.h
* \author Killian Colin
*/

#ifndef PROJETMOTEUR_VECTOR3F_H
#define PROJETMOTEUR_VECTOR3F_H

#include "Vector.h"
#include "CoordSpherique.h"

class CoordSpherique;

/**
* \class Vector3f
* \brief Vector3f is the generic vector3 class
*/
class Vector3f: public Vector {
    protected:
        Vector3f(int l);
    public:
		/*!
		\brief generate an empty Vector3f
		*/
        Vector3f();
		/*!
		\brief the Vector object need to have the size =3
		*/
        Vector3f(Vector);
		/*!
		\brief create [x y z] vector
		*/
        Vector3f(float x , float y, float z);
        void operator=(Vector const& v);
		/*!
		\return this[0]
		*/
        float getX();
		/*!
		\return this[1]
		*/
        float getY();
		/*!
		\return this[2]
		*/
        float getZ();
		/*!
		\param[in] x: the new value
		\brief this[0]=x
		*/
        void setX(float x);
		/*!
		\param[in] y: the new value
		\brief this[1]=y
		*/
        void setY(float y);
		/*!
		\param[in] z: the new value
		\brief this[2]=z
		*/
        void setZ(float z);
        Vector3f operator+(Vector3f const& v2)const;
        Vector3f operator-(Vector3f const& v2)const;
        Vector3f operator^(Vector3f const& v2)const;
        float operator*(Vector3f const& v2)const;
        Vector3f operator+(float d)const;
        Vector3f operator-(float d)const;
        Vector3f operator*(float d)const;
        Vector3f operator/(float d)const;

        CoordSpherique convertCoordSpherique();
};


#endif //PROJETMOTEUR_VECTOR3F_H
