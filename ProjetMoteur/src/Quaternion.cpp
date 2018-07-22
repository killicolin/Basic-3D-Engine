
#include "Quaternion.h"
#include "math.h"

Quaternion::Quaternion(){
    _w=1;
    _v=Vector3f(0,0,0);
}

Quaternion::Quaternion(float w,Vector3f v){
    _w=w;
    _v=v;
}

Quaternion::Quaternion(Vector3f n,float teta){
    _w=cos(teta/2);
    _v=n*sin(teta/2);
}

float Quaternion::getW()const{
    return _w;
}

Vector3f Quaternion::getV()const{
    return _v;
}

void Quaternion::setW(float w){
    _w=w;
}
void Quaternion::setV( Vector3f v){
    _v=v;
}

Quaternion operator-(Quaternion const& q1){
    Vector3f v = q1.getV().neg();
    return Quaternion(-q1.getW(),v);
}

float Quaternion::magnitudePow()const{
    return pow(_w,2)+_v.normPow();
}

float Quaternion::magnitude()const{
    return sqrt(magnitudePow());
}

Quaternion Quaternion::conjug()const{
    return Quaternion(_w,_v.neg());
}

Quaternion Quaternion::log()const{
    Vector3f tmp;
    tmp=_v;
    tmp.normalize();
    return Quaternion(0,tmp*angleAlpha());
}

Quaternion Quaternion::exp()const{
    if (_w!=0) {
        throw std::invalid_argument("W must be equal to 0.");
    }
    float alpha=_v.norm();
    Vector3f tmp;
    tmp=_v;
    tmp.normalize();
    return Quaternion(cos(alpha),tmp*sin(alpha));
}

Quaternion Quaternion::inverse()const{
    return this->conjug()/this->magnitude();
}

float Quaternion::scalaire(Quaternion const& q1){
    float res=0;
    for (int i = 0; i < 3; ++i) {
        res+=_v[i]*q1.getV()[i];
    }
    return _w*q1.getW()+res;
}

float Quaternion::angleAlpha()const{
    return acos(_w);
}

Quaternion operator*(Quaternion const& q1,float f){
    return Quaternion(q1.getW()*f,q1.getV()*f);
}

Quaternion operator/(Quaternion const& q1,float f){
    return Quaternion(q1.getW()/f,q1.getV()/f);
}

void Quaternion::operator/=(float f){
    _w/=f;
    _v/=f;
}

Quaternion operator*(Quaternion const& q1,Quaternion const& q2){
    float resW=q1.getW()*q2.getW()-q1.getV()*q2.getV();
    Vector3f resV=(q2.getV()*q1.getW())+(q1.getV()*q2.getW())+(q1.getV()^q2.getV());
    return Quaternion(resW,resV);
}

std::ostream& operator<<(std::ostream& out, Quaternion q){
    out <<q.getW()<<" : "<<q.getV()<<" ";
    return out;
}

Quaternion Quaternion::operator+(Quaternion const& q1)const{
    return Quaternion(_w+q1.getW(),_v+q1.getV());
}

Quaternion Quaternion::difference(Quaternion const& q1)const{
    return q1*this->inverse();
}

MatrixC3 Quaternion::toMatrix()const{
    float m=this ->magnitude();
    Vector3f v3;
    v3=_v/m;
    float w=_w/m;
    return MatrixC3{
            1-2*pow(v3[1],2)-2*pow(v3[2],2),
            2*v3[0]*v3[1]-2*w*v3[2],
            2*v3[0]*v3[2]+2*w*v3[1],
            2*v3[0]*v3[1]+2*w*v3[2],
            1-2*pow(v3[0],2)-2*pow(v3[2],2),
            2*v3[1]*v3[2]-2*w*v3[0],
            2*v3[0]*v3[2]-2*w*v3[1],
            2*v3[1]*v3[2]+2*w*v3[0],
            1-2*pow(v3[0],2)-2*pow(v3[1],2),
    };
}

AngleEuler Quaternion::toEuler()const{
    float p=asin(-2*(_v[1]*_v[2]-_w*_v[0]));
    float h;
    float b;
    if(cos(p)!=0){
        h=atan2(2*_v[0]*_v[2]+2*_w*_v[1],1-2*pow(_v[0],2)-2*pow(_v[1],2));
        b=atan2(2*_v[0]*_v[1]+2*_w*_v[2],1-2*pow(_v[0],2)-2*pow(_v[2],2));
    }
    else{
        h=atan2(-2*_v[0]*_v[2]+_w*_v[1],1-2*pow(_v[1],2)-2*pow(_v[2],2));
        b=0;
    }
    AngleEuler res=AngleEuler(p,h,b);
    return res;
}

Quaternion Quaternion::slerp(Quaternion const& q1,float t){
    float tempo=this->scalaire(q1);
    if(tempo<0){
        tempo=this->scalaire(-q1);
    }
    float angleW=acos(tempo);
    return (*this*(sin((1-t)*angleW)/sin(angleW))+q1*(sin(t*angleW)/sin(angleW)));
}