
/*!
* \file MatrixC3.h
* \author Killian Colin
*/
#ifndef PROJETMOTEUR_MATRIXC3_H
#define PROJETMOTEUR_MATRIXC3_H

#include "MatrixC.h"
#include "Quaternion.h"
#include "AngleEuler.h"
class Quaternion;
class AngleEuler;

/*!
* \class MatrixC3
* \brief MatrixC3 is the generic square matrix (size:3) class
*/
class MatrixC3 : public MatrixC{
    protected:
        MatrixC3(int l);
    public:
        MatrixC3();
		/*!
		\brief create [m00 m01 m02] matrix
			          [m10 m11 m12] 
			          [m20 m21 m22] 
		*/
        MatrixC3(float m00,float m01,float m02,
                 float m10,float m11,float m12,
                 float m20,float m21,float m22);

        void operator=(MatrixC const& m);

		/*!
		\param[in] angleDegree: any float (the angle in degree)
		\brief set a rotation on the X axis of angleDegree degrees
		*/
        void rotationCardinalX(float angleDegree);

		/*!
		\param[in] angleDegree: any float (the angle in degree)
		\brief set a rotation on the Y axis of angleDegree degrees
		*/
        void rotationCardinalY(float angleDegree);

		/*!
		\param[in] angleDegree: any float (the angle in degree)
		\brief set a rotation on the Z axis of angleDegree degrees
		*/
        void rotationCardinalZ(float angleDegree);

		/*!
		\param[in] angleDegree: any float (the angle in degree)
		\brief set a rotation on the Y axis of angleDegree degrees
		*/
        void rotationArbitraire(Vector3f const& n, float angleDegree);

		/*!
		\param[in] kx: any float (the factor on the X axis)
		\param[in] ky: any float (the factor on the Y axis)
		\param[in] kz: any float (the factor on the Z axis)
		\brief scale this matrix with the kx, ky, kz factors
		*/
        void scaleCardinal(float kx,float ky,float kz);

		/*!
		\param[in] n: any Vector3f (the scale axis)
		\param[in] k: any float (the scale factor)
		\brief scale this matrix on the n axis with the k factor
		*/
        void scaleArbitraire(Vector3f const& n,float k);

		/*!
		\brief set this to a 2D projection matrix to the axes X and Y
		*/
        void orthoXY();

		/*!
		\brief set this to a 2D projection matrix to the axes X and Z
		*/
        void orthoXZ();

		/*!
		\brief set this to a 2D projection matrix to the axes Y and Z
		*/
        void orthoYZ();

		/*!
		\brief normalize this matrix
		*/
        void normalize();

		/*!
		\param[in] n: any Vector3f
		\brief set this to a 3D orthographic projection matrix with value n 
		*/
        void orthoArbitraire(Vector3f const& n);

		/*!
		\param[in] n: any Vector3f
		\brief set this to a mirror matrix from the n axis
		*/
        void mirror(Vector3f const& n);

		/*!
		\param[in] s: any float
		\param[in] t: any float
		\brief set this to shearing matrix with s the x factor and t the y factor in the z direction
		*/
        void cisaillementXY(float s,float t);

		/*!
		\param[in] s: any float
		\param[in] t: any float
		\brief set this to shearing matrix with s the x factor and t the y factor in the y direction
		*/
        void cisaillementXZ(float s,float t);

		/*!
		\param[in] s: any float
		\param[in] t: any float
		\brief set this to shearing matrix with s the y factor and t the y factor in the x direction
		*/
        void cisaillementYZ(float s,float t);

		/*!
		*/
        Quaternion toQuaternion();

		/*!
		*/
        AngleEuler toEuler();
};


#endif //PROJETMOTEUR_MATRIXC3_H
