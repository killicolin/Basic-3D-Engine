
#ifndef PROJETMOTEUR_COMPLEXSURFACE_H
#define PROJETMOTEUR_COMPLEXSURFACE_H
#include "ObjectRender.h"
using namespace std;

/**
* \file ComplexSurface.h
* \author Killian Colin
*/

/**
* \class ComplexSurface
* \brief ComplexSurface is a 3D complex surface object render in the 3D environment based on the .obj file give in parameter
*/
class ComplexSurface:public ObjectRender {
public:
	/*!
	\param[in] position: any Vector4f position, the ComplexSurface center position
	\param[in] color: any Vector4f color
	\param[in] filename: the .obj filename of the ComplexSurface desired
	\brief generate a monochromatic ComplexSurface
	*/
	ComplexSurface(Vector4f position,Vector4f color,char* filename);
};


#endif //PROJETMOTEUR_COMPLEXSURFACE_H
