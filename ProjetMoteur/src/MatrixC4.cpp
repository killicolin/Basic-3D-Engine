
#include "MatrixC4.h"
#include <math.h>
MatrixC4::MatrixC4():MatrixC3(4){

}

MatrixC4::MatrixC4(float m00,float m01,float m02,float m03, float m10,float m11,float m12,float m13,
         float m20,float m21,float m22,float m23, float m30,float m31,float m32,float m33):MatrixC3(4){
    this->_value[0]=m00;
    this->_value[1]=m10;
    this->_value[2]=m20;
    this->_value[3]=m30;
    this->_value[4]=m01;
    this->_value[5]=m11;
    this->_value[6]=m21;
    this->_value[7]=m31;
    this->_value[8]=m02;
    this->_value[9]=m12;
    this->_value[10]=m22;
    this->_value[11]=m32;
    this->_value[12]=m03;
    this->_value[13]=m13;
    this->_value[14]=m23;
    this->_value[15]=m33;
}

void MatrixC4::operator=( MatrixC const& m){
    MatrixC3::operator=(m);
}

void MatrixC4::setTranslation(float x,float y, float z){
    this->set(0,3,x);
    this->set(1,3,y);
    this->set(2,3,z);
}
void MatrixC4::setTranslation(Vector3f n){
    setTranslation(n[0],n[1],n[2]);
}

void MatrixC4::orthographic(float left,float right,float bottom,float top,float near,float far){
    this->setIdentity();
    this->set(0,0,2/(right-left));
    this->set(1,1,2/(top-bottom));
    this->set(2,2,-2/(far-near));
    this->set(0,3,-(right+left)/(right-left));
    this->set(1,3,-(top+bottom)/(top-bottom));
    this->set(2,3,-(far+near)/(far-near));
}

void MatrixC4::perspective(float angle,float near,float far){
    this->setIdentity();
    this->set(0,0,1/tan(angle/2));
    this->set(1,1,1/tan(angle/2));
    this->set(2,2,-(far)/(far-near));
    this->set(2,3,-(far*near)/(far-near));
    this->set(3,2,-1);
    this->set(3,3,0);
}

MatrixC3 MatrixC4::toMatrix3(){
    return MatrixC3((*this)(0,0),(*this)(0,1),(*this)(0,2),(*this)(1,0),(*this)(1,1),(*this)(1,2),(*this)(2,0),(*this)(2,1),(*this)(2,2));
}
