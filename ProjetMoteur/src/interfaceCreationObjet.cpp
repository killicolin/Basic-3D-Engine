
#include "interfaceCreationObjet.h"
#include "RectangularPrism.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Plan.h"
#include "Triangle.h"
#include "complexSurface.h"

Vector4f saisiCouleur(){
    float R,G,B;
    cout << "Choisissez la couleur RGB compris entre 0 et 1 sous ce format: " << endl;
    cout << "R G B"<< endl;
    cin >> R >> G >> B;
    return Vector4f(R,G,B,1.0);
}

Vector4f saisiPosition(){
    float X,Y,Z;
    cout << "Choisissez une position XYZ sous ce format: " << endl;
    cout << "X Y Z"<< endl;
    cin >> X >> Y >> Z;
    return Vector4f(X,Y,Z,1.0);
}

Vector3f saisiNormal(){
    float X,Y,Z;
    cout << "Choisissez un vecteur Normal XYZ sous ce format: " << endl;
    cout << "X Y Z"<< endl;
    cin >> X >> Y >> Z;
    Vector3f res=Vector3f(X,Y,Z);
    res.normalize();
    return res;
}

float saisiRayon(){
    float R;
    cout << "Choisissez un rayon: " << endl;
    cin >> R;
    return R;
}

int saisiPrecision(){
    int P;
    cout << "Choisissez une précision de rendu en valeur entière (à partir de 32 le rendu commence à être propre): " << endl;
    cin >> P;
    return P;
}

ObjectRender creationCube(){
    float D;
    cout << "Choisissez Dimension du cube " << endl;
    cin >> D;
    RectangularPrism t=RectangularPrism(Vector4f(0.0,0.0,0.0,1.0),saisiCouleur(),D,D,D);
    return t;
}
ObjectRender creationPrism(){
    float Dx,Dy,Dz;
    cout << "Choisissez Dimension du prism en X" << endl;
    cin >> Dx;
    cout << "Choisissez Dimension du prism en Y" << endl;
    cin >> Dy;
    cout << "Choisissez Dimension du prism en Z" << endl;
    cin >> Dz;
    RectangularPrism t=RectangularPrism(Vector4f(0.0,0.0,0.0,1.0),saisiCouleur(),Dx,Dy,Dz);
    return t;
}
ObjectRender creationCylinder(){
    cout << "Haut du cylindre " << endl;
    Vector4f c1=saisiCouleur();
    cout << "Bas du cylindre " << endl;
    Vector4f c2=saisiCouleur();
    cout << "Tour du cylindre " << endl;
    Vector4f c3=saisiCouleur();
    float r=saisiRayon();
    float h;
    cout << "Choisissez la hauteur du cylindre " << endl;
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
    cout << "la normale du plan" << endl;
    Vector3f n1=saisiNormal();
    float Dx,Dy;
    cout << "Choisissez Dimension du plan en longueur" << endl;
    cin >> Dx;
    cout << "Choisissez Dimension du plan en largeur" << endl;
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
    cout << "Nom du fichier: (exemple: suzanne.obj)" << endl;
    cin >> forme;
    ComplexSurface cs= ComplexSurface(Vector4f(0.0,0.0,0.0,1.0),saisiCouleur(),forme);
    return cs;
}