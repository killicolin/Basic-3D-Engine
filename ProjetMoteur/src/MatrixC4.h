
/*!
* \file MatrixC4.h
* \author Killian Colin
*/
#ifndef PROJETMOTEUR_MATRIXC4_H
#define PROJETMOTEUR_MATRIXC4_H

#include "MatrixC3.h"

/*!
* \class MatrixC4
* \brief MatrixC4 is the generic square matrix (size:4) class
*/
class MatrixC4: public MatrixC3 {
public:
    MatrixC4();
	/*!
	\brief create [m00 m01 m02 m03] matrix
				  [m10 m11 m12 m13]
				  [m20 m21 m22 m23]
				  [m30 m31 m32 m33]
	*/
    MatrixC4(float m00,float m01,float m02,float m03,
             float m10,float m11,float m12,float m13,
             float m20,float m21,float m22,float m23,
             float m30,float m31,float m32,float m33);
	
    void operator=(MatrixC const& m);

	/*!
	\param[in] x: any float (the translate value on x axis)
	\param[in] y: any float (the translate value on y axis)
	\param[in] z: any float (the translate value on z axis)
	\brief set a translation on this matrix
	*/
    void setTranslation(float x,float y, float z);

	/*!
	\param[in] n: any Vector3f (the translate vector)
	\brief set a translation on this matrix
	*/
    void setTranslation(Vector3f n);

	/*!
	\param[in] angle: the angle of the fild of view (fov, angle in radian) 
	\param[in] near: the distance before the first view plan (positive float)
	\param[in] far: the distance before the last view plan (positive float)
	\brief set this to a perpective projection matrix
	*/
    void perspective(float angle,float near,float far);

	/*!
	\param[in] left: the position of the leftest view plan (on X axis)
	\param[in] right: the position of the rightest view plan (on X axis)
	\param[in] bottom: the position of the bottomest view plan (on Y axis)
	\param[in] top: the position of the topest view plan (on Y axis)
	\param[in] near: the position of the first view plan (on Z axis)
	\param[in] far: the position of the last view plan (on Z axis)
	\brief set this to a orthographic projection matrix
	*/
    void orthographic(float left,float right,float bottom,float top,float near,float far);
    MatrixC3 toMatrix3();
};


#endif //PROJETMOTEUR_MATRIXC4_H
