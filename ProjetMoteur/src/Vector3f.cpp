
#include "Vector3f.h"
#include "math.h"

Vector3f::Vector3f():Vector::Vector(3){

}

Vector3f::Vector3f(int l):Vector::Vector(l){

}

Vector3f::Vector3f(Vector v):Vector::Vector(3){
    if(v.size()==3) {
        for (int i = 0; i < 3; ++i) {
            _value[i] = v[i];
        }
    }
    else{
        throw std::invalid_argument("need a Vector 3");
    }
}


Vector3f::Vector3f(float x , float y, float z):Vector::Vector(3){
    this->_value[0]=x;
    this->_value[1]=y;
    this->_value[2]=z;
}

void Vector3f::operator=(Vector const& v){
    Vector::operator=(v);
}

float Vector3f::getX(){
    return this->_value[0];
}

float Vector3f::getY(){
    return this->_value[2];
}

float Vector3f::getZ(){
    return this->_value[2];
}

void Vector3f::setX(float x){
    this->_value[0]=x;
}

void Vector3f::setY(float y){
    this->_value[1]=y;
}

void Vector3f::setZ(float z){
    this->_value[2]=z;
}

CoordSpherique Vector3f::convertCoordSpherique(){
    float r=sqrt(pow(_value[0],2)+pow(_value[1],2)+pow(_value[2],2));
    float p=asin(-_value[1]/r);
    float h=atan2(_value[0],_value[2]);
    return CoordSpherique(r,p,h);
}

Vector3f operator-(Vector3f const& v1){
    return Vector3f(-v1[0], -v1[1], -v1[2]);
}

Vector3f Vector3f::operator+(Vector3f const& v2)const{
    return Vector3f(Vector::operator+(v2));
}

Vector3f Vector3f::operator-(Vector3f const& v2)const{
    return Vector3f(Vector::operator-(v2));
}

Vector3f Vector3f::operator^(Vector3f const& v2)const{
    return Vector3f(Vector::operator^(v2));
}

float Vector3f::operator*(Vector3f const& v2)const{
    return (Vector::operator*(v2));
}

Vector3f Vector3f::operator+(float d)const{
    return Vector3f(Vector::operator+(d));
}

Vector3f Vector3f::operator-(float d)const{
    return Vector3f(Vector::operator-(d));
}

Vector3f Vector3f::operator*(float d)const{
    return Vector3f(Vector::operator*(d));
}

Vector3f Vector3f::operator/(float d)const{
    return Vector3f(Vector::operator/(d));
}