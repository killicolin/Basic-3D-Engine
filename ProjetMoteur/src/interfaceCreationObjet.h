

#ifndef PROJETMOTEUR_INTERFACECREATIONOBJET_H
#define PROJETMOTEUR_INTERFACECREATIONOBJET_H

#include "Vector4f.h"
#include "ObjectRender.h"

Vector4f saisiCouleur();
Vector4f saisiPosition();
Vector3f saisiNormal();
float saisiRayon();
int saisiPrecision();
ObjectRender creationCube();
ObjectRender creationPrism();
ObjectRender creationCylinder();
ObjectRender creationSphere();
ObjectRender creationPlan();
ObjectRender creationTriangle();
ObjectRender creationAutre();
#endif //PROJETMOTEUR_INTERFACECREATIONOBJET_H
