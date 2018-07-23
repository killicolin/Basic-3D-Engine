
#include "interfaceCreationObjet.h"
#include "RectangularPrism.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Plan.h"
#include "Triangle.h"
#include "complexSurface.h"

Vector4f saisiCouleur(){
    float R,G,B;
    cout << "Choose the RGB color from 0 to 1 in this format:  " << endl;
    cout << "R G B"<< endl;
    cin >> R >> G >> B;
    return Vector4f(R,G,B,1.0);
}

Vector4f saisiPosition(){
    float X,Y,Z;
    cout << "Choose an XYZ position in this format: " << endl;
    cout << "X Y Z"<< endl;
    cin >> X >> Y >> Z;
    return Vector4f(X,Y,Z,1.0);
}

Vector3f saisiNormal(){
    float X,Y,Z;
    cout << "Choose a Normal XYZ vector in this format:  " << endl;
    cout << "X Y Z"<< endl;
    cin >> X >> Y >> Z;
    Vector3f res=Vector3f(X,Y,Z);
    res.normalize();
    return res;
}

float saisiRayon(){
    float R;
    cout << "Choose a radius: " << endl;
    cin >> R;
    return R;
}

int saisiPrecision(){
    int P;
    cout << "Choose a rendering accuracy (integer) (from 32 the rendering starts to be clean):  " << endl;
    cin >> P;
    return P;
}

ObjectRender creationCube(){
    float D;
    cout << "Choose Cube Size " << endl;
    cin >> D;
    RectangularPrism t=RectangularPrism(Vector4f(0.0,0.0,0.0,1.0),saisiCouleur(),D,D,D);
    return t;
}
ObjectRender creationPrism(){
    float Dx,Dy,Dz;
    cout << "Choose Prism size in X" << endl;
    cin >> Dx;
    cout << "Choose Prism size in Y" << endl;
    cin >> Dy;
    cout << "Choose Prism size in Z" << endl;
    cin >> Dz;
    RectangularPrism t=RectangularPrism(Vector4f(0.0,0.0,0.0,1.0),saisiCouleur(),Dx,Dy,Dz);
    return t;
}
ObjectRender creationCylinder(){
    cout << "Top of cylinder " << endl;
    Vector4f c1=saisiCouleur();
    cout << "Bottom of cylinder " << endl;
    Vector4f c2=saisiCouleur();
    cout << "Cylinder turn " << endl;
    Vector4f c3=saisiCouleur();
    float r=saisiRayon();
    float h;
    cout << "Choose cylinder height " << endl;
    cin >> h;
    Cylinder cy=Cylinder(Vector4f(0.0,0.0,0.0,1.0),c3,c2,c1,r,h,saisiPrecision());
    return cy;
}
ObjectRender creationSphere(){
    Sphere sp=Sphere(Vector4f(0.0,0.0,0.0,1.0),saisiCouleur(),saisiRayon(),saisiPrecision());
    return sp;
}
ObjectRender creationPlan(){
    Vector4f c1=saisiCouleur();
    cout << "the normal of the plan" << endl;
    Vector3f n1=saisiNormal();
    float Dx,Dy;
    cout << "Choose Plan dimension in length" << endl;
    cin >> Dx;
    cout << "Choose Plan dimension in width" << endl;
    cin >> Dy;
    Plan pl=Plan(Vector4f(0.0,0.0,0.0,1.0),c1,n1,Dx,Dy);
    return pl;
}

ObjectRender creationTriangle(){
    cout << "point 1: " << endl;
    Vector4f p1=saisiPosition();
    cout << "point 2:" << endl;
    Vector4f p2=saisiPosition();
    cout << "point 3:" << endl;
    Vector4f p3=saisiPosition();
    Triangle tr=Triangle(p1,p2,p3,saisiCouleur());
    return tr;
}

ObjectRender creationAutre(){
    char forme[1000];
    cout << "File name: (example: suzanne.obj)" << endl;
    cin >> forme;
    ComplexSurface cs= ComplexSurface(Vector4f(0.0,0.0,0.0,1.0),saisiCouleur(),forme);
    return cs;
}