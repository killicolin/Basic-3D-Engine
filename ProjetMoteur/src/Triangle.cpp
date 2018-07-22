
#include "Triangle.h"
Triangle::Triangle(Vector4f position1,Vector4f position2,Vector4f position3,Vector4f color):ObjectRender(Vector4f()){
    Vector position=((position1+position2+position3));
    position.set(3,0);
    position/=3;
    _model=MatrixC4();
    _model.setTranslation(position[0],position[1],position[2]);
    Vector e3=Vector4f();
    Vector e1=Vector4f();
    Vector normal4=Vector4f();
    e3=position2-position1;
    e1=position3-position2;
    normal4=(e3^e1);
    normal4.normalize();
    Vector3f normal=Vector3f(normal4[0],normal4[1],normal4[2]);
    vertexBuffer.push_back((position1-position));
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back((position2-position));
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back((position3-position));
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
}