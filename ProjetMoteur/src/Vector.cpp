#include <cmath>
#include <iostream>
#include <stdexcept>
#include "Vector.h"

Vector::Vector(int l){
    this->_value=new float[l];
    this->_size=l;
    int len=sizeof(_value);
}

float Vector::operator[](int i)const{
    return _value[i];
}

int Vector::size()const{
    return this->_size;
}

void Vector::operator=(Vector const& v){
    if(v.size()!=_size){
        throw std::invalid_argument("need a couple of vector with the same size");
    }
    for (int i = 0; i < _size; i++) {
        _value[i]=v[i];
    }
}

void Vector::operator+=(Vector& v){
    if(v.size()!=_size){
        throw std::invalid_argument("need a couple of vector with the same size");
    }
    for (int i = 0; i < _size; i++) {
        _value[i]+=v[i];
    }
}

void Vector::operator-=(Vector& v){
    if(v.size()!=_size){
        throw std::invalid_argument("need a couple of vector with the same size");
    }
    for (int i = 0; i < _size; i++) {
        _value[i]-=v[i];
    }
}

void Vector::operator^=(Vector& v){
    *this=*this^v;
}


void Vector::operator+=(float f){
    for (int i = 0; i < _size; i++) {
        _value[i]+=f;
    }
}

void Vector::operator-=(float f){
    for (int i = 0; i < _size; i++) {
        _value[i]-=f;
    }
}

void Vector::operator*=(float f){
    for (int i = 0; i < _size; i++) {
        _value[i]*=f;
    }
}

bool Vector::operator!=(Vector const& v2){
    return !(*this==v2);
}


Vector Vector::operator+(Vector const& v2)const{
    if(_size!=v2.size()){
        throw std::invalid_argument("need a couple of vector with the same size");
    }
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,_value[i]+v2[i]);
    }
    return res;
}
Vector Vector::operator-(Vector const& v2)const{
    if(_size!=v2.size()){
        throw std::invalid_argument("need a couple of vector with the same size");
    }
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,_value[i]-v2[i]);
    }
    return res;
}
Vector Vector::operator^(Vector const& v2)const{
    if(_size!=v2.size()){
        throw std::invalid_argument("need a couple of vector with the same size");
    }
    Vector res =Vector(_size);
    if(_size<=3)
    for (int i = 0; i < _size; i++) {
        res.set(i,_value[(i+1)%_size]*v2[(i+2)%_size]-v2[(i+1)%_size]*_value[(i+2)%_size]);
    }
	//only for 
    else {
        res.set(0,_value[1]*v2[2]-_value[2]*v2[1]);
        res.set(1,_value[2]*v2[0]-_value[0]*v2[2]);
        res.set(2,_value[0]*v2[1]-_value[1]*v2[0]);
    }
    return res;
}

float Vector::operator*(Vector const& v2)const{
    float res=0;
    if(_size!=v2.size()){
        throw std::invalid_argument("need a couple of vector with the same size");
    }
    for (int i = 0; i <_size; i++) {
        res+=_value[i]*v2[i];
    }
    return res;
}

Vector Vector::operator+(float d)const{
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,_value[i]+d);
    }
    return res;
}

Vector Vector::operator-(float d)const{
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,_value[i]-d);
    }
    return res;
}

Vector Vector::operator*(float d)const{
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,_value[i]*d);
    }
    return res;
}

Vector Vector::operator/(float f)const{
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,_value[i]/f);
    }
    return res;
}

void Vector::operator/=(float f){
    for (int i = 0; i < _size; i++) {
        _value[i]/=f;
    }
}

Vector Vector::operator/(int j){
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,_value[i]/j);
    }
    return res;
}

float Vector::norm()const{
    return sqrt(this->normPow());
}

float Vector::normPow()const{
    float res = 0;
    for (int i = 0; i < _size; i++) {
        res+=pow(_value[i],2);
    }
    return res;
}
float* Vector::getData(){
    return _value;
}

Vector Vector::distance(Vector& v){
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,sqrt(pow(_value[i]-v[i],2)));
    }
    return res;
}

Vector Vector::distancePow(Vector& v){
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,pow(_value[i]-v[i],2));
    }
    return res;
}

void Vector::normalize(){
    *this/=this->norm();
}

void Vector::set(int i, float res){
    if (i>=_size&&i<0) {
        throw std::invalid_argument("the first integer need to be postive and under the size of the vector.");
    }
    _value[i]=res;
}

float Vector::angle(Vector& v){
    return acos(((*this)*v)/(this->norm()*v.norm()));
}

Vector Vector::neg()const{
    Vector res =Vector(_size);
    for (int i = 0; i < _size; i++) {
        res.set(i,-_value[i]);
    }
    return res;
}

std::ostream& operator<<(std::ostream& out, Vector v){
    int size=v.size();
    for (int i = 0; i < size; i++) {
        out <<v[i]<<" ";
    }
    out<<"\n";
    return out;
}

bool Vector::operator==(Vector const& v){
    bool res =_size!=v.size();
    int i=0;
    while(res && i<_size){
        res=_value[i]==v[i];
    }
    return res;
}

Vector::Vector(){}