/**
* \file Vector.h
* \author Killian Colin
*/
#ifndef PROJETMOTEUR_VECTOR_H
#define PROJETMOTEUR_VECTOR_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

/**
* \class Vector
* \brief Vector is the generic vector class
*/
class Vector{
protected:
    float *_value;
    int _size;
    Vector();
public:
    explicit Vector(int l);
    float operator[](int i)const;
    int size()const;
	/*!
	\return the float* corresponding to the float array in the vector
	*/
    float* getData();
	/*!
	\param[in] v: any Vector 
	\return the distance vector between this and v
	*/
	Vector distance(Vector& v);
	/*!
	\param[in] v: any Vector
	\return the distance squared vector between this and v
	\brief can be usefull to optimise some computation
	*/
	Vector distancePow(Vector& v);
	/*!
	\return the negative of this vector
	*/
	Vector neg()const;
	/*!
	\param[in] v: any Vector
	\return the angle between this and v
	*/
	float angle(Vector& v);
	/*!
	\return the norm of this
	*/
	float norm()const;
	/*!
	\return the norm squared of this
	\brief can be usefull to optimise some computation
	*/
	float normPow()const;
	/*!
	\brief normalize this vector
	*/
	void normalize();
	/*!
	\param[in] i: the index value need to be positive or null
	\param[in] res: the new value
	\brief this[i] = res;
	*/
	void set(int i, float res);
	bool operator==(Vector const& v);
	bool operator!=(Vector const& v2);
	void operator=(Vector const& v);
	void operator+=(Vector& v);
	void operator-=(Vector& v);
	void operator^=(Vector& v);
	void operator+=(float f);
	void operator-=(float f);
	void operator*=(float f);
	void operator/=(float f);
    Vector operator+(Vector const& v2)const;
    Vector operator-(Vector const& v2)const;
    Vector operator^(Vector const& v2)const;
    float operator*(Vector const& v2)const;
    Vector operator+(float d)const;
    Vector operator-(float d)const;
    Vector operator*(float d)const;
    Vector operator/(float f)const;
    Vector operator/(int j);

    friend std::ostream& operator<<(std::ostream& out, Vector v);
};
#endif //PROJETMOTEUR_VECTOR_H