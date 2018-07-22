
#include "Sphere.h"
#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))
Sphere::Sphere(Vector4f position,Vector4f color,float radius,int precision):ObjectRender(position,0.2f,0.7f,1.f,10){
    float theta,phi;
    vector<Vector4f> vertex;
    vector<Vector3f> normal;
    Vector4f top=Vector4f(.0,radius,.0,1.);
    Vector4f bottom=Vector4f(.0,-radius,.0,1.);
    Vector3f normalTop=Vector3f(.0,1.,.0);
    Vector3f normalBottom=Vector3f(.0,-1.,.0);
    for (int i = 0; i <= precision; ++i) {
        phi= (float)((i * 2. * M_PI) / ((float)precision));
        for (int j = 1; j < precision; ++j) {
            theta = (float)(((j*M_PI))/((float)precision) -M_PI/2.);
            vertex.push_back(Vector4f(cos(theta)*cos(phi)*radius,sin(theta)*radius,cos(theta)*sin(phi)*radius, 1.));
            normal.push_back(Vector3f(cos(theta)*cos(phi),sin(theta),cos(theta)*sin(phi)));

        }
    }
    int nextLine=precision-1;
    for (int i = 0; i < precision; ++i) {
        vertexBuffer.push_back(bottom);
        vertexBuffer.push_back(color);
        vertexBuffer.push_back(normalBottom);
        vertexBuffer.push_back(vertex[i*nextLine]);
        vertexBuffer.push_back(color);
        vertexBuffer.push_back(normal[i*nextLine]);
        vertexBuffer.push_back(vertex[(i+1)*nextLine]);
        vertexBuffer.push_back(color);
        vertexBuffer.push_back(normal[(i+1)*nextLine]);
        for (int j = 0; j < precision-2; ++j) {
            vertexBuffer.push_back(vertex[j+i*nextLine]);
            vertexBuffer.push_back(color);
            vertexBuffer.push_back(normal[j+i*nextLine]);
            vertexBuffer.push_back(vertex[j+(i+1)*nextLine]);
            vertexBuffer.push_back(color);
            vertexBuffer.push_back(normal[j+(i+1)*nextLine]);
            vertexBuffer.push_back(vertex[j+i*nextLine+1]);
            vertexBuffer.push_back(color);
            vertexBuffer.push_back(normal[j+i*nextLine+1]);
            vertexBuffer.push_back(vertex[j+(i+1)*nextLine]);
            vertexBuffer.push_back(color);
            vertexBuffer.push_back(normal[j+(i+1)*nextLine]);
            vertexBuffer.push_back(vertex[j+i*nextLine+1]);
            vertexBuffer.push_back(color);
            vertexBuffer.push_back(normal[j+i*nextLine+1]);
            vertexBuffer.push_back(vertex[j+(i+1)*nextLine+1]);
            vertexBuffer.push_back(color);
            vertexBuffer.push_back(normal[j+(i+1)*nextLine+1]);
        }
        vertexBuffer.push_back(vertex[(i+1)*nextLine-1]);
        vertexBuffer.push_back(color);
        vertexBuffer.push_back(normal[(i+1)*nextLine-1]);
        vertexBuffer.push_back(vertex[(i+2)*nextLine-1]);
        vertexBuffer.push_back(color);
        vertexBuffer.push_back(normal[(i+2)*nextLine-1]);
        vertexBuffer.push_back(top);
        vertexBuffer.push_back(color);
        vertexBuffer.push_back(normalTop);
    }
}