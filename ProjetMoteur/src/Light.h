
#ifndef PROJETMOTEUR_LIGHT_H
#define PROJETMOTEUR_LIGHT_H


#include "Vector4f.h"
/**
* \file Light.h
* \author Killian Colin
*/

/**
* \class Light
* \brief Light is use to light the object in the 3D environment
*/
class Light {
private:
    Vector4f lightPosition;
    Vector3f lightColor;
public:
	/*!
	\param[in] position: any Vector4f position (the position of the light)
	\param[in] color: any Vector4f color (the light color)
	\brief generate a monochromatic light point
	*/
    Light(Vector4f position,Vector3f color);
	/*!
	\return the light position
	*/
    Vector4f getPosition();
	/*!
	\return the light color
	*/
    Vector3f getColor();
};


#endif //PROJETMOTEUR_LIGHT_H
