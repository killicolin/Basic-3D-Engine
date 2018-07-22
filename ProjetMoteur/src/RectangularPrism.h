/**
* \file RectangularPrism.h
* \author Killian Colin
*/

/**
* \class RectangularPrism
* \brief RectangularPrism is a 3D RectangularPrism object render in the 3D environment
*/
#ifndef PROJETMOTEUR_RECTANGULARPRISM_H
#define PROJETMOTEUR_RECTANGULARPRISM_H
#include "ObjectRender.h"
using namespace std;

class RectangularPrism:public ObjectRender{
    private:
        void colorCarre(Vector4f * vertex,Vector4f color,Vector3f normal,int i1,int i2,int i3,int i4);
        void colorCube(Vector4f * vertex,Vector4f * color,Vector3f * normal);
    public:
		/*!
		\param[in] position: any Vector4f position, the RectangularPrism center position
		\param[in] color: any Vector4f color
		\param[in] xlen: any positive float (the X axis length)
		\param[in] ylen: any positive float (the Y axis length)
		\param[in] zlen: any positive float (the Z axis length)
		\brief generate a monochromatic RectangularPrism
		*/
        RectangularPrism(Vector4f position,Vector4f color, float xlen,float ylen, float zlen);
		/*!
		\param[in] colorFace: any Vector4f color
		\brief change the color of the RectangularPrism
		*/
        void setColorFace(Vector4f *colorFace);
};


#endif //PROJETMOTEUR_RECTANGULARPRISM_H
