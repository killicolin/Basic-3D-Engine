/**
* \file Vector4f.h
* \author Killian Colin
*/

#ifndef PROJETMOTEUR_VECTOR4F_H
#define PROJETMOTEUR_VECTOR4F_H

#include "Vector3f.h"

/**
* \class Vector4f
* \brief Vector4f is the generic vector4 class
*/
class Vector4f : public Vector3f{
    public:
		/*!
		\brief generate an empty Vector4f
		*/
        Vector4f();
		/*!
		\brief the Vector object need to have the size =4
		*/
        Vector4f(Vector);
		/*!
		\brief create [x y z w] vector
		*/
        Vector4f(float x , float y, float z, float w);
        void operator=(Vector const& v);
		/*!
		\return this[3]
		*/
        float getW();
		/*!
		\param[in] w: the new value
		\brief this[3]=w
		*/
        void setW(float w);
        Vector4f operator+(Vector4f const& v2)const;
        Vector4f operator-(Vector4f const& v2)const;
        Vector4f operator^(Vector4f const& v2)const;
        float operator*(Vector4f const& v2)const;
        Vector4f operator+(float d)const;
        Vector4f operator-(float d)const;
        Vector4f operator*(float d)const;
};


#endif //PROJETMOTEUR_VECTOR4F_H
