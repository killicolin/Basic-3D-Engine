#include <cmath>
#include <iostream>
#include <stdexcept>
#include "MatrixC.h"
#include "MatrixC3.h"

MatrixC::MatrixC(int i){
    this->_value=new float[(i*i)];
    this->_size=i;
    this->setIdentity();
}
float * MatrixC::getData(){
    return _value;
}

float MatrixC::operator()(int i,int j) const{
    if (i>=_size&&i<0 || j>=_size&&j<0) {
        throw std::invalid_argument("the index need to be postive and under the size of the Matrix.");
    }
    return _value[j*_size+i];
}

void MatrixC::set(int i,int j, float res){
    if (i>=_size&&i<0) {
        throw std::invalid_argument("the first integer need to be postive and under the size of the vector.");
    }
    _value[j*_size+i]=res;
}

int MatrixC::size() const{
    return this->_size;
}

Vector MatrixC::line(int i) const{
    if (i>=_size&&i<0) {
        throw std::invalid_argument("the iterator is out of the matrix range");
    }
    Vector res =Vector(_size);
    for (int j = 0; j < _size; j++) {
        res.set(j,(*this)(i,j));
    }
    return res;
}

Vector MatrixC::column(int i) const{
    if (i>=_size&&i<0) {
        throw std::invalid_argument("the iterator is out of the matrix range");
    }
    Vector res =Vector(_size);
    for (int j = 0; j < _size; j++) {
        res.set(j,(*this)(j,i));
    }
    return res;
}

MatrixC operator+(MatrixC const& m1,MatrixC const& m2){
    if (m2.size()!=m1.size()) {
        throw std::invalid_argument("need a matrix with the same _size");
    }
    MatrixC res=MatrixC(m1.size());
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            res.set(i,j,m1(i,j)+m2(i,j));
        }
    }
    return res;
}

void MatrixC::operator=( MatrixC const& m){
    if (_size!=m.size()) {
        throw std::invalid_argument("need a matrix with the same _size");
    }
    for(int i=0;i<_size;i++){
        for(int j=0;j<_size;j++){
            this->set(i,j,m(i,j));
        }
    }
}


void MatrixC::operator+=(MatrixC const& m1){
    if (_size!=m1.size()) {
        throw std::invalid_argument("need a matrix with the same _size");
    }
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            this->set(i,j,(*this)(i,j)+m1(i,j));
        }
    }
}

void MatrixC::operator-=(MatrixC const& m1){
    if (_size!=m1.size()) {
        throw std::invalid_argument("need a matrix with the same _size");
    }
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            this->set(i,j,(*this)(i,j)-m1(i,j));
        }
    }
}

void MatrixC::operator*=(MatrixC const& m1){
    if (_size!=m1.size()) {
        throw std::invalid_argument("need a matrix with the same _size");
    }
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            this->set(i,j,(*this)(i,j)*m1(i,j));
        }
    }
}

bool MatrixC::operator==(MatrixC const& m){
    bool res =_size!=m.size();
	int i = 0;
	int j = 0;
    while(res && i<_size){
        while(res && j<_size){
            res=(*this)(i,j)==m(i,j);
            j++;
        }
        i++;
        j=0;
    }
    return res;
}

MatrixC operator-(MatrixC const& m1,MatrixC const& m2){
    if (m2.size()!=m1.size()) {
        throw std::invalid_argument("need a matrix with the same _size");
    }
    MatrixC res=MatrixC(m1.size());
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            res.set(i,j,m1(i,j)-m2(i,j));
        }
    }
    return res;
}


MatrixC operator*(MatrixC const& m1,MatrixC const& m2){
    if (m2.size()!=m1.size()) {
        throw std::invalid_argument("need a matrix with the same _size");
    }
    MatrixC res=MatrixC(m1.size());
    res.empty();
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1.size(); j++) {
            for (int k = 0; k < m1.size(); ++k) {
                res.set(i,j,res(i,j)+m1(i,k)*m2(k,j));
            }
        }
    }
    return res;
}

Vector MatrixC::operator*(Vector& v){
    if (_size!= v.size()) {
        throw std::invalid_argument("need a matrix with the same size of the vector");
    }
    Vector res =Vector(_size);
    float tmp;
    for (int i = 0; i < _size; i++) {
        tmp=0;
        for (int j = 0; j < _size; j++) {
            tmp+=(*this)(i,j)*v[j];
        }
        res.set(i,tmp);
    }
    return res;
}

void MatrixC::T(){
    float tmp=0;
    for (int i = 0; i < _size; i++) {
        for (int j = i; j < _size; j++) {
            tmp=(*this)(j,i);
            this->set(j,i,(*this)(i,j));
            this->set(i,j,tmp);
        }
    }
}

void MatrixC::setIdentity(){
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if(i==j){
                this->set(i,j,1);
            }
            else{
                this->set(i,j,0);
            }
        }
    }
}

void MatrixC::empty(){
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            this->set(i,j,0);
        }
    }
}


void MatrixC::clear(){
    delete[] _value;
    _size=0;
}

bool MatrixC::isOrthogonal(){
    MatrixC transpose=MatrixC(_size);
    MatrixC id=MatrixC(_size);
    id.setIdentity();
    transpose=*this;
    transpose.T();
    return id==*this*transpose;
}

std::ostream& operator<<(std::ostream& out, MatrixC m){
    int size=m.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            out <<m(i,j)<<" ";
        }
        out<<"\n";
    }
    return out;
}

float MatrixC::determinant(){
    float res=0;
    if(_size<3){
        return this->det();
    }
    else{
        for (int i = 0; i < _size; ++i) {
            res+=(float)(pow(-1,i))*(*this)(0,i)*sousComatrix(0,i);
        }
    }
    return res;
}


float MatrixC::det(){
    float res=0;
    float tmpPlus,tmpMoins;
    for (int i = 0; i < _size; ++i) {
        tmpPlus=1;
        tmpMoins=0;
        for (int k = 0; k < _size; ++k) {
            tmpPlus*=(*this)((k)%_size,(i+k)%_size);
            tmpMoins*=(*this)((k)%_size,(i+(_size-k))%_size);
        }
        res+=tmpPlus;
        res-=tmpMoins;
    }
    return res;
}

float MatrixC::sousComatrix(int x,int y){
    int k,h;
    MatrixC calc=MatrixC(_size-1);
    for (int i = 0; i < calc.size(); ++i) {
        for (int j = 0; j < calc.size(); j++) {
            k=i<x?i:i+1;
            h=j<y?j:j+1;
            calc.set(i,j,(*this)(k,h));
        }
    }
    return calc.determinant();
}

void MatrixC::coMatrix(){
    MatrixC temp=MatrixC(_size);
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            temp.set(i,j,(float)(pow(-1,i+j))*this->sousComatrix(i,j));
        }
    }
    *this=temp;
}

MatrixC MatrixC::operator/(float f)const{
    MatrixC temp=MatrixC(_size);
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            temp.set(i,j,(*this)(i,j)/f);
        }
    }
    return temp;
}

void MatrixC::operator/=(float f){
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            this->set(i,j,(*this)(i,j)/f);
        }
    }
}

void MatrixC::inv(){
    float det=this->determinant();
    this->coMatrix();
    this->T();
    *this/=det;
}