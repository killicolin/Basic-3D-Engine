
#include "Vector4f.h"
Vector4f::Vector4f():Vector3f(4){

}

Vector4f::Vector4f(Vector v):Vector3f(4){
    if(v.size()==4) {
        for (int i = 0; i < 4; ++i) {
            _value[i] = v[i];
        }
    }
    else{
        throw std::invalid_argument("need a Vector 3");
    }
}


Vector4f::Vector4f(float x , float y, float z, float w):Vector3f(4){
    this->_value[0]=x;
    this->_value[1]=y;
    this->_value[2]=z;
    this->_value[3]=w;
}

void Vector4f::operator=( Vector const& v){
    Vector::operator=(v);
}

float Vector4f::getW(){
    return this->_value[3];
}

void Vector4f::setW(float w){
    this->_value[3]=w;
}

Vector4f Vector4f::operator+(Vector4f const& v2)const{
    return Vector4f(Vector::operator+(v2));
}


Vector4f Vector4f::operator-(Vector4f const& v2)const{
    return Vector4f(Vector::operator-(v2));
}


Vector4f Vector4f::operator^(Vector4f const& v2)const{
    return Vector4f(Vector::operator^(v2));
}

float Vector4f::operator*(Vector4f const& v2)const{
    return (Vector::operator*(v2));
}

Vector4f Vector4f::operator+(float d)const{
    return Vector4f(Vector::operator+(d));
}

Vector4f Vector4f::operator-(float d)const{
    return Vector4f(Vector::operator-(d));
}

Vector4f Vector4f::operator*(float d)const{
    return Vector4f(Vector::operator*(d));
}
