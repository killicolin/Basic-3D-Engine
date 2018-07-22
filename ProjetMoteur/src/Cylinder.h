
#ifndef PROJETMOTEUR_CYLINDER_H
#define PROJETMOTEUR_CYLINDER_H
#include "ObjectRender.h"
using namespace std;
/**
* \file Cylinder.h
* \author Killian Colin
*/

/**
* \class Cylinder
* \brief Cylinder is a 3D Cylinder object render in the 3D environment
*/
class Cylinder:public ObjectRender{
public:
	/*!
	\param[in] position: any Vector4f position, the Cylinder center position
	\param[in] color1: any Vector4f color (bottom face color)
	\param[in] color2: any Vector4f color (top face color)
	\param[in] color3: any Vector4f color (circular face color)
	\param[in] radius: any positive float (the radius of the cylinder)
	\param[in] ylen: any positive float (the height of the cylinder)
	\param[in] precision: a positive integer, the number of point in the shape (determine the detail level of the shape)
	\brief generate a Cylinder
	*/
    Cylinder(Vector4f position,Vector4f color1,Vector4f color2,Vector4f color3, float radius,float ylen,int precision);
	/*!
	\param[in] colorBase: any Vector4f color (bottom face color)
	\param[in] colorTop: any Vector4f color (top face color)
	\param[in] colorAround: any Vector4f color (circular face color)
	\brief change the color of the Cylinder
	*/
    void setColorFace(Vector4f colorBase,Vector4f colorTop,Vector4f colorAround);
};


#endif //PROJETMOTEUR_CYLINDER_H
