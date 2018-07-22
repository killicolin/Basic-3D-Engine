
#include "Light.h"
Light::Light(Vector4f position,Vector3f color){
    lightPosition=position;
    lightColor=color;
}

Vector4f Light::getPosition(){
    return lightPosition;
}

Vector3f Light::getColor(){
    return lightColor;
}