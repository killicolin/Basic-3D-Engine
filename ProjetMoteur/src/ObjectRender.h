#ifndef PROJETMOTEUR_OBJECTRENDER_H
#define PROJETMOTEUR_OBJECTRENDER_H
#define _USE_MATH_DEFINES
#include <cmath>
#include "openglFunction.h"
#include "Vector4f.h"
#include "MatrixC4.h"
#include "Light.h"
#include <vector>

using namespace std;
/**
* \file ObjectRender.h
* \author Killian Colin
*/

/**
* \class ObjectRender
* \brief ObjectRender is the parent class to any rendered object in the 3D environment
*/

class ObjectRender{
protected:
    vector<Vector> vertexBuffer;
    MatrixC4 _model;
    GLuint vaoCube;
    GLuint vboCube;
    GLuint IndexVBO;
    //materiel de l'objet (pas eu le temps de faire en sorte qu'on puisse le customiser à la création d'un objet)
    float ka; /*!< Ambiant Coefficient*/
    float kd; /*!< Diffuse Coefficient*/
    float ks; /*!< Specular Coefficient*/
    float kn; /*!< Light Intensity*/
public :
	/*
	\param[in] position: any Vector4f position (the center of the object)
	\brief Generate the ObjectRender
	*/
    ObjectRender(Vector4f position);
	/*
	\param[in] position: any Vector4f position (the center of the object)
	\param[in] Ka: a positive float (ambiant coefficient)
	\param[in] Kd: a positive float (diffuse coefficient)
	\param[in] Ks: a positive float (specular coefficient)
	\param[in] Kn: a positive float (light intensity)
	\brief Generate the ObjectRender with the material coefficient
	*/
    ObjectRender(Vector4f position,float Ka,float Kd,float Ks,float Kn);
	/*
	\param[in] P: The projection matrix 
	\param[in] V: The view matrix 
	\param[in] l: The light on the object
	\param[in] mode:  the rendered mode selected
	\brief Draw the ObjectRender
	*/
    void draw(MatrixC4 P,MatrixC4 V,Light l,int mode);
	/*
	\brief free the ObjectRender
	*/
    void free();
	/*!
	\param[in] m1: the new model matrix
	\brief define model matrix of the object
	*/
    void setModel(MatrixC4 m1);
	/*!
	\param[in] m1: the new model matrix
	\brief combine m1 and the current model matrix of the object.
	*/
    void addModel(MatrixC4 m1);
	/*!
	\return the model matrix of the object.
	*/
    MatrixC4 getModel();
	/*!
	\param[in] Ka: a positive float (ambiant coefficient)
	\param[in] Kd: a positive float (diffuse coefficient)
	\param[in] Ks: a positive float (specular coefficient)
	\param[in] Kn: a positive float (light intensity)
	\brief define the material of the object
	*/
    void setMaterial(float Ka,float Kd,float Ks,float Kn);
	/*!
	\return the ambiant coefficient
	*/
    float getKa();
	/*!
	\return the diffuse coefficient
	*/
    float getKd();
	/*!
	\ return the specular coefficient
	*/
    float getKs();
	/*!
	\return the light intensity
	*/
    float getKn();
};


#endif //PROJETMOTEUR_OBJECTRENDER_H
