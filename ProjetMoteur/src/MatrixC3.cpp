
#include <cmath>
#include "MatrixC3.h"
#include <iostream>
MatrixC3::MatrixC3():MatrixC(3){

}

MatrixC3::MatrixC3(int l):MatrixC(l){

}

void MatrixC3::normalize(){
    Vector3f l0=this->line(0);
    Vector3f l1=this->line(1);
    Vector3f l2=this->line(2);
    l0.normalize();
    l1.normalize();
    l2.normalize();
    for (int i = 0; i < 3; ++i) {
        this->set(0,i,l0[i]);
        this->set(1,i,l1[i]);
        this->set(2,i,l2[i]);
    }
}


MatrixC3::MatrixC3(float m00,float m01,float m02,float m10,float m11,float m12,
                   float m20,float m21,float m22):MatrixC(3){
    this->set(0,0,m00);
    this->set(0,1,m01);
    this->set(0,2,m02);
    this->set(1,0,m10);
    this->set(1,1,m11);
    this->set(1,2,m12);
    this->set(2,0,m20);
    this->set(2,1,m21);
    this->set(2,2,m22);
}

void MatrixC3::rotationCardinalX(float angle) {
    this->setIdentity();
    this->set(1, 1, cos(angle));
    this->set(1, 2, -sin(angle));
    this->set(2, 2, cos(angle));
    this->set(2, 1, sin(angle));
}
void MatrixC3::rotationCardinalY(float angle){
    this->setIdentity();
    this->set(0,0,cos(angle));
    this->set(0,2,sin(angle));
    this->set(2,2,cos(angle));
    this->set(2,0,-sin(angle));
}

void MatrixC3::rotationCardinalZ(float angle){
    this->setIdentity();
    this->set(0,0,cos(angle));
    this->set(0,1,-sin(angle));
    this->set(1,1,cos(angle));
    this->set(1,0,sin(angle));

}

void MatrixC3::rotationArbitraire(Vector3f const& n, float angle){
    this->set(0,0,pow(n[0],2)*(1-cos(angle))+cos(angle));
    this->set(0,1,n[0]*n[1]*(1-cos(angle))-n[2]*sin(angle));
    this->set(0,2,n[0]*n[2]*(1-cos(angle))+n[1]*sin(angle));
    this->set(1,0,n[1]*n[0]*(1-cos(angle))+n[2]*sin(angle));
    this->set(1,1,pow(n[1],2)*(1-cos(angle))+cos(angle));
    this->set(1,2,n[1]*n[2]*(1-cos(angle))-n[0]*sin(angle));
    this->set(2,0,n[2]*n[0]*(1-cos(angle))-n[1]*sin(angle));
    this->set(2,1,n[2]*n[1]*(1-cos(angle))+n[0]*sin(angle));
    this->set(2,2,pow(n[2],2)*(1-cos(angle))+cos(angle));
}

void MatrixC3::scaleCardinal(float kx,float ky,float kz){
    this->setIdentity();
    this->set(0,0,kx);
    this->set(1,1,ky);
    this->set(2,2,kz);
}

void MatrixC3::scaleArbitraire(Vector3f const& n,float k){
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if(i!=j){
                this->set(i,j,n[i]*n[j]*(k-1));
            }
            else{
                this->set(i,j,1+pow(n[i],2)*(k-1));
            }
        }
    }
}

void MatrixC3::orthoXY(){
    this->setIdentity();
    this->set(2,2,0);
}

void MatrixC3::orthoXZ(){
    this->setIdentity();
    this->set(1,1,0);
}

void MatrixC3::orthoYZ(){
    this->setIdentity();
    this->set(0,0,0);
}

void MatrixC3::orthoArbitraire(Vector3f const& n){
    this->set(0,0,1-pow(n[0],2));
    this->set(0,1,-n[0]*n[1]);
    this->set(0,2,-n[0]*n[2]);
    this->set(1,0,-n[1]*n[0]);
    this->set(1,1,1-pow(n[1],2));
    this->set(1,2,-n[1]*n[2]);
    this->set(2,0,-n[2]*n[0]);
    this->set(2,1,-n[2]*n[1]);
    this->set(2,2,1-pow(n[2],2));
}

void MatrixC3::mirror(Vector3f const& n){
    this->set(0,0,1-2*pow(n[0],2));
    this->set(0,1,-2*n[0]*n[1]);
    this->set(0,2,-2*n[0]*n[2]);
    this->set(1,0,-2*n[1]*n[0]);
    this->set(1,1,1-2*pow(n[1],2));
    this->set(1,2,-2*n[1]*n[2]);
    this->set(2,0,-2*n[2]*n[0]);
    this->set(2,1,-2*n[2]*n[1]);
    this->set(2,2,1-2*pow(n[2],2));
}

void MatrixC3::cisaillementXY(float s,float t){
    this->setIdentity();
    this->set(0,2,s);
    this->set(1,2,t);
}
void MatrixC3::cisaillementXZ(float s,float t){
    this->setIdentity();
    this->set(0,1,s);
    this->set(2,1,t);
}
void MatrixC3::cisaillementYZ(float s,float t){
    this->setIdentity();
    this->set(1,0,s);
    this->set(2,0,t);
}

void MatrixC3::operator=( MatrixC const& m){
    MatrixC::operator=(m);
}

Quaternion MatrixC3::toQuaternion(){
    float qw,qx,qy,qz;
    auto SIGN = [](float x) -> int {
        return (x >= 0.0f) ? +1 : -1;
    };
    qw = ( (*this)(0,0) + (*this)(1,1) + (*this)(2,2) + 1.0f) / 4.0f;
    qx = ( (*this)(0,0) - (*this)(1,1) - (*this)(2,2) + 1.0f) / 4.0f;
    qy = (-(*this)(0,0) + (*this)(1,1) - (*this)(2,2) + 1.0f) / 4.0f;
    qz = (-(*this)(0,0) - (*this)(1,1) + (*this)(2,2) + 1.0f) / 4.0f;
    if(qw < 0.0f) qw = 0.0f;
    if(qx < 0.0f) qx = 0.0f;
    if(qy < 0.0f) qy = 0.0f;
    if(qz < 0.0f) qz = 0.0f;
    qw = sqrt(qw);
    qx = sqrt(qx);
    qy = sqrt(qy);
    qz = sqrt(qz);
    if(qw >= qx && qw >= qy && qw >= qz) {
        qw *= +1.0f;
        qx *= SIGN((*this)(2,1) - (*this)(1,2));
        qy *= SIGN((*this)(0,2) - (*this)(2,0));
        qz *= SIGN((*this)(1,0) - (*this)(0,1));
    } else if(qx >= qw && qx >= qy && qx >= qz) {
        qw *= SIGN((*this)(2,1) - (*this)(1,2));
        qx *= +1.0f;
        qy *= SIGN((*this)(1,0) + (*this)(0,1));
        qz *= SIGN((*this)(0,2) + (*this)(2,0));
    } else if(qy >= qw && qy >= qx && qy >= qz) {
        qw *= SIGN((*this)(0,2) - (*this)(2,0));
        qx *= SIGN((*this)(1,0) + (*this)(0,1));
        qy *= +1.0f;
        qz *= SIGN((*this)(2,1) + (*this)(1,2));
    } else if(qz >= qw && qz >= qx && qz >= qy) {
        qw *= SIGN((*this)(1,0) - (*this)(0,1));
        qx *= SIGN((*this)(2,0) + (*this)(0,2));
        qy *= SIGN((*this)(2,1) + (*this)(1,2));
        qz *= +1.0f;
    } else {
        printf("coding error\n");
    }
    Quaternion q;
    q= Quaternion(qw, Vector3f(qx,qy,qz));
    q /= q.magnitude();
    return q;
}

AngleEuler MatrixC3::toEuler(){
    float p=asin(-(*this)(1,2));
    float h=atan2((*this)(0,2)/cos(p),(*this)(2,2)/cos(p));
    float b=atan2((*this)(1,0)/cos(p),(*this)(1,1)/cos(p));
    AngleEuler res(p,h,b);
    return res;
}