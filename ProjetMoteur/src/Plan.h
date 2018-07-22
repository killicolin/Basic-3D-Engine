/**
* \file Plan.h
* \author Killian Colin
*/

/**
* \class Plan
* \brief Plan is a 2D Plan object render in the 3D environment
*/
#ifndef PROJETMOTEUR_PLAN_H
#define PROJETMOTEUR_PLAN_H
#include "ObjectRender.h"
using namespace std;

class Plan:public ObjectRender {
public:
	/*!
	\param[in] position: any Vector4f position (the middle of the plan)
	\param[in] color: any Vector4f color
	\param[in] normal: any Vector3f
	\param[in] wlen: any positive float (the width of the plan)
	\param[in] hlen: any positive float (the height of the plan)
	\brief generate a monochromatic plan
	*/
    Plan(Vector4f position,Vector4f color,Vector3f normal, float wlen,float hlen);
	/*!
	\param[in] color: any Vector4f color
	\brief change the color of the plan
	*/
    void setColorFace(Vector4f colorFace);
};


#endif //PROJETMOTEUR_PLAN_H
