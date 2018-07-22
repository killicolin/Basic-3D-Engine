
#include "Cylinder.h"
#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))
Cylinder::Cylinder(Vector4f position,Vector4f color1,Vector4f color2,Vector4f color3, float radius,float ylen,int precision):ObjectRender(position){
    vector<Vector4f> vertex;
    vector<Vector3f> normal;
    ylen/=2.;
    _model=MatrixC4();
    _model.setTranslation(position.getX(),position.getY(),position.getZ());
    float angle;
    vertex.push_back(Vector4f(.0,-ylen,.0,1));
    vertex.push_back(Vector4f(.0,ylen,.0,1));
    Vector3f normalBas=Vector3f(.0,-1.,.0);
    Vector3f normalHaut=Vector3f(.0,1.,.0);
    for (int i = 0; i <= precision; ++i) {
        angle=(float)((i*2.*M_PI)/((float)precision));
        vertex.push_back(Vector4f(radius*cos(angle),-ylen,radius*sin(angle),1.));
        vertex.push_back(Vector4f(radius*cos(angle),ylen,radius*sin(angle),1.));
        normal.push_back(Vector3f(cos(angle),0.,sin(angle)));
    }
    for (int i = 1; i <= precision; i++) {
        //cercle Bas
        vertexBuffer.push_back(vertex[0]);
        vertexBuffer.push_back(color1);
        vertexBuffer.push_back(normalBas);
        vertexBuffer.push_back(vertex[i*2]);
        vertexBuffer.push_back(color1);
        vertexBuffer.push_back(normalBas);
        vertexBuffer.push_back(vertex[(i+1)*2]);
        vertexBuffer.push_back(color1);
        vertexBuffer.push_back(normalBas);
        //cercle Haut
        vertexBuffer.push_back(vertex[1]);
        vertexBuffer.push_back(color2);
        vertexBuffer.push_back(normalHaut);
        vertexBuffer.push_back(vertex[i*2+1]);
        vertexBuffer.push_back(color2);
        vertexBuffer.push_back(normalHaut);
        vertexBuffer.push_back(vertex[(i+1)*2+1]);
        vertexBuffer.push_back(color2);
        vertexBuffer.push_back(normalHaut);
        //contour
        vertexBuffer.push_back(vertex[i*2]);
        vertexBuffer.push_back(color3);
        vertexBuffer.push_back(normal[i-1]);
        vertexBuffer.push_back(vertex[i*2+1]);
        vertexBuffer.push_back(color3);
        vertexBuffer.push_back(normal[i-1]);
        vertexBuffer.push_back(vertex[(i+1)*2]);
        vertexBuffer.push_back(color3);
        vertexBuffer.push_back(normal[i]);
        vertexBuffer.push_back(vertex[i*2+1]);
        vertexBuffer.push_back(color3);
        vertexBuffer.push_back(normal[i-1]);
        vertexBuffer.push_back(vertex[(i+1)*2]);
        vertexBuffer.push_back(color3);
        vertexBuffer.push_back(normal[i]);
        vertexBuffer.push_back(vertex[(i+1)*2+1]);
        vertexBuffer.push_back(color3);
        vertexBuffer.push_back(normal[i]);
    }
}
void Cylinder::setColorFace(Vector4f colorBase,Vector4f colorTop,Vector4f colorAround){
    int len=vertexBuffer.size()/3;
    for (int i = 0; i <= len; i+=18) {
        vertexBuffer[i+0*3+1]=colorBase;
        vertexBuffer[i+1*3+1]=colorBase;
        vertexBuffer[i+2*3+1]=colorBase;
        vertexBuffer[i+3*3+1]=colorTop;
        vertexBuffer[i+4*3+1]=colorTop;
        vertexBuffer[i+5*3+1]=colorTop;
        vertexBuffer[i+6*3+1]=colorAround;
        vertexBuffer[i+7*3+1]=colorAround;
        vertexBuffer[i+8*3+1]=colorAround;
        vertexBuffer[i+9*3+1]=colorAround;
        vertexBuffer[i+10*3+1]=colorAround;
        vertexBuffer[i+11*3+1]=colorAround;
    }
}