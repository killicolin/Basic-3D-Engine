
#include "Plan.h"
Plan::Plan(Vector4f position,Vector4f color,Vector3f normal, float wlen,float hlen):ObjectRender(position){
    normal.normalize();
    Vector3f wBase=Vector3f();
    Vector3f hBase=Vector3f();
    if((normal^Vector3f(1,0,0))!=Vector3f(0,0,0))
        wBase=normal^Vector3f(1,0,0);
    else
        wBase=normal^Vector3f(0,1,0);
    wBase.normalize();
    hBase=normal^wBase;
    hBase.normalize();
    wBase=normal^hBase;
    wBase.normalize();
    Vector3f tmp=wBase*(wlen/2)+hBase*(hlen/2);
    Vector4f vertex1=Vector4f(tmp[0],tmp[1],tmp[2],1);
    tmp=wBase*(-wlen/2)+hBase*(hlen/2);
    Vector4f vertex2=Vector4f(tmp[0],tmp[1],tmp[2],1);
    tmp=wBase*(wlen/2)+hBase*(-hlen/2);
    Vector4f vertex3=Vector4f(tmp[0],tmp[1],tmp[2],1);
    tmp=wBase*(-wlen/2)+hBase*(-hlen/2);
    Vector4f vertex4=Vector4f(tmp[0],tmp[1],tmp[2],1);
    vertexBuffer.push_back(vertex1);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex2);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex3);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex4);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex2);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex3);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
}