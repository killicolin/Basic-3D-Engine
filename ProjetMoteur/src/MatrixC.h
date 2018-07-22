/**
* \file MatrixC.h
* \author Killian Colin
*/
#ifndef PROJETMOTEUR_MATRIXC_H
#define PROJETMOTEUR_MATRIXC_H

#include "Vector.h"
/**
* \class MatrixC
* \brief MatrixC is the generic square matrix class
*/
class MatrixC{
protected:
    float *_value;
    int _size;
    MatrixC();
	float det();
public:
	/**
	\param[in] l: the value need to be positive
	\brief create a square matrix with the l size, init as an identity matrix
	*/
    MatrixC(int l);

	/*!
	\return the float* corresponding to the float array in the MatrixC
	*/
    float * getData();

	/*!
	\param[in] i: the line index value need to be positive or null
	\param[in] j: the column index value need to be positive or null
	\return the value line i and column j
	*/
    float operator()(int i,int j)const;

	/*!
	\param[in] i: the line index value need to be positive or null
	\param[in] j: the column index value need to be positive or null
	\param[in] res: the column index value need to be positive or null
	\brief set the new value at the line i and column j
	*/
    void set(int i,int j, float res);

	/*!
	\param[in] i: the index value need to be positive or null
	\return the line i as a Vector
	*/
    Vector line(int i)const;

	/*!
	\param[in] i: the index value need to be positive or null
	\return the column i as a Vector
	*/
    Vector column(int i)const;

	/*!
	\return the size of this square matrix 
	*/
    int size()const;

	/*!
	\brief transpose this matrix
	*/
    void T();

	/*!
	\brief inverse this matrix
	*/
    void inv();

	/*!
	\return the matrix determinant value
	*/
    float determinant();

	/*!
	\param[in] x: the line index value need to be positive or null
	\param[in] y: the column index value need to be positive or null
	\return minor of this matrix, without line x and column y
	*/
    float sousComatrix(int x,int y);

	/*!
	\brief conjugate this matrix
	*/
    void coMatrix();

	/*!
	\brief set this matrix to identity
	*/
    void setIdentity();

	/*!
	\brief set this matrix to zero
	*/
    void empty();

	/*!
	\brief clear memory of this matrix
	*/
    void clear();

	/*!
	\return true if this matrix is orthogonal
	*/
    bool isOrthogonal();

	void operator=(MatrixC const& m);
	bool operator==(MatrixC const& m);
	MatrixC operator/(float f)const;
	void operator/=(float f);
	Vector operator*(Vector& v);
    void operator+=(MatrixC const& m1);
    void operator-=(MatrixC const& m1);
    void operator*=(MatrixC const& m1);
    friend std::ostream& operator<<(std::ostream& out, MatrixC m);
    friend MatrixC operator+(MatrixC const& m1,MatrixC const& m2);
    friend MatrixC operator-(MatrixC const& m1,MatrixC const& m2);
    friend MatrixC operator*(MatrixC const& m1,MatrixC const& m2);
};
#endif //PROJETMOTEUR_MATRIXC_H