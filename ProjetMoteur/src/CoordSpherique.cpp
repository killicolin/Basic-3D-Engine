#include <math.h>
#include "CoordSpherique.h"

CoordSpherique::CoordSpherique(float r,float p,float h){
    if(r==0){
        _r=0;
        _p=0;
        _h=0;
        return;
    }
    if(r<0){
        r=-r;
        p=-p;
        h=(float)(h+M_PI);
    }
    while(p<-M_PI/2){
        p+= (float)M_PI*2;
    }
    while(p>3*M_PI/2){
        p-= (float)M_PI*2;
    }
    if(p>M_PI/2){
        h+= (float)M_PI;
        p= (float)M_PI-p;
    }
    while(h<=-M_PI){
        h+= (float)M_PI*2;
    }
    while(h>M_PI){
        h-= (float)M_PI*2;
    }
    _r=r;
    _p=p;
    _h=h;
}


void CoordSpherique::setR(float r){
    if(r==0){
        _r=0;
        _p=0;
        _h=0;
        return;
    }
    if(r<0){
        _r=-r;
        _p=-_p;
        setH(_h+ (float)M_PI);
    }
}


void CoordSpherique::setP(float p){
    while(p<-M_PI/2){
        p+= (float)M_PI*2;
    }
    while(p>3*M_PI/2){
        p-= (float)M_PI*2;
    }
    if(p>90){
        setH(_h+ (float)M_PI);
        _p= (float)M_PI-p;
    }
}


void CoordSpherique::setH(float h){
    while(h<=-M_PI){
        h+= (float)M_PI*2;
    }
    while(h>M_PI){
        h-= (float)M_PI*2;
    }
    _h=h;
}

float CoordSpherique::getR(){
    return _r;
}

float CoordSpherique::getP(){
    return _p;
}

float CoordSpherique::getH(){
    return _h;
}

Vector3f CoordSpherique::convertToVector(){
    return Vector3f(_r*sin(_p)*sin(_h),
                    -_r*sin(_p),
                    _r*cos(_p)*cos(_h));
}
