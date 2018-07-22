
#ifndef PROJETMOTEUR_COORDINATESYSTEM_H
#define PROJETMOTEUR_COORDINATESYSTEM_H
#include "ObjectRender.h"
using namespace std;

/**
* \file CoordinateSystem.h
* \author Killian Colin
*/

/**
* \class CoordinateSystem
* \brief CoordinateSystem is a 3D coordinate system render in the 3D environment
*/
class CoordinateSystem: public ObjectRender{
public:
	/*!
	\param[in] position: any Vector4f position, the Sphere center position
	\brief generate a monochromatic Sphere
	*/
    CoordinateSystem(Vector4f position);
	/*
	\param[in] P: The projection matrix
	\param[in] V: The view matrix
	\brief Draw the CoordinateSystem
	*/
    void draw(MatrixC4 P,MatrixC4 V);
};


#endif //PROJETMOTEUR_COORDINATESYSTEM_H
