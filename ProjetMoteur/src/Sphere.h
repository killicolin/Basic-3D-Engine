
#ifndef PROJETMOTEUR_SPHERE_H
#define PROJETMOTEUR_SPHERE_H
#include "ObjectRender.h"
using namespace std;

/**
* \file Sphere.h
* \author Killian Colin
*/

/**
* \class Sphere
* \brief Sphere is a 3D Sphere object render in the 3D environment
*/
class Sphere :public ObjectRender{
public:
	/*!
	\param[in] position: any Vector4f position, the Sphere center position
	\param[in] color: any Vector4f color
	\param[in] radius: a positive float
	\param[in] precision: a positive integer, the number of point in the shape (determine the detail level of the shape)
	\brief generate a monochromatic Sphere
	*/
    Sphere(Vector4f position,Vector4f color,float radius,int precision);
};


#endif //PROJETMOTEUR_SPHERE_H
