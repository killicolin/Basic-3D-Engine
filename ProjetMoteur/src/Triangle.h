/**
* \file Triangle.h
* \author Killian Colin
*/

/**
* \class Triangle
* \brief Triangle is a 2D triangle object render in the 3D environment
*/
#ifndef PROJETMOTEUR_TRIANGLE_H
#define PROJETMOTEUR_TRIANGLE_H
#include "ObjectRender.h"
using namespace std;
class Triangle :public ObjectRender {
public:
	/*!
	\param[in] position1: any Vector4f position
	\param[in] position2: any Vector4f position
	\param[in] position3: any Vector4f position
	\param[in] color: any Vector4f color
	\brief generate a monochromatic triangle
	*/
    Triangle(Vector4f position1,Vector4f position2,Vector4f position3,Vector4f color);
	/*!
	\param[in] color1: any Vector4f color
	\param[in] color2: any Vector4f color
	\param[in] color3: any Vector4f color
	\brief change the color of the Triangle (the first color vector, color the first position of the Triangle etc ...)
	*/
    void setColorFace(Vector4f color1,Vector4f color2,Vector4f color3);
};


#endif //PROJETMOTEUR_TRIANGLE_H
