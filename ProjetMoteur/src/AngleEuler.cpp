#include <functional>
#include "AngleEuler.h"
#include "MatrixC3.h"
#include <math.h>

AngleEuler::AngleEuler(float pitch,float heading,float bank){
    setPitch(pitch);
    setHeading(heading);
    setBank(bank);
}

float AngleEuler::getHeading(){
    return _h;
}

float AngleEuler::getPitch(){
    return _p;
}

float AngleEuler::getBank(){
    return _b;
}

void AngleEuler::setHeading(float heading){

    while(heading>M_PI){
        heading-=2*(float)M_PI;
    }
    while(heading<=-M_PI){
        heading+=2* (float)M_PI;
    }
    _h=heading;
}

void AngleEuler::setBank(float bank){

    while(bank>M_PI){
        bank-=2* (float)M_PI;
    }
    while(bank<=-M_PI){
        bank+=2* (float)M_PI;
    }
    _b=bank;
}

void AngleEuler::setPitch(float pitch){

    while((pitch)>M_PI/2){
        setHeading(_h+ (float)M_PI);
        setBank(_b+ (float)M_PI);
        pitch= (float)M_PI-pitch;
    }
    while((pitch)<-M_PI/2){
        setHeading(_h+ (float)M_PI);
        setBank(_b+ (float)M_PI);
        pitch= (float)M_PI+pitch;
    }
    if(fabs(pitch)==M_PI/2){
        setBank(0);
    }
    _p=pitch;
}

MatrixC3 AngleEuler::toMatrix3(){
    MatrixC3 res=MatrixC3();
    res.set(0,0,cos(_h)*cos(_b)+sin(_h)*sin(_p)*sin(_b));
    res.set(0,1,-cos(_h)*sin(_b)+sin(_h)*sin(_p)*cos(_b));
    res.set(0,2,sin(_h)*cos(_p));
    res.set(1,0,sin(_b)*cos(_p));
    res.set(1,1,cos(_b)*cos(_p));
    res.set(1,2,-sin(_p));
    res.set(2,0,-sin(_h)*cos(_b)+cos(_h)*sin(_p)*sin(_b));
    res.set(2,1,sin(_b)*sin(_h)+cos(_h)*sin(_p)*cos(_b));
    res.set(2,2,cos(_h)*cos(_p));
    return res;
}

Quaternion AngleEuler::toQuaternion(){
    Vector3f v3 = Vector3f(
            (float)(cos(_h/2.)*sin(_p/2.)*cos(_b/2.)+sin(_h/2.)*cos(_p/2.)*sin(_b/2.)),
			(float)(sin(_h/2.)*cos(_p/2.)*cos(_b/2.)-cos(_h/2.)*sin(_p/2.)*sin(_b/2.)),
			(float)(cos(_h/2.)*cos(_p/2.)*sin(_b/2.)-sin(_h/2.)*sin(_p/2.)*cos(_b/2.))
    );
    Quaternion res=Quaternion((float)(cos(_h/2.)*cos(_p/2.)*cos(_b/2.)+sin(_h/2.)*sin(_p/2.)*sin(_b/2.)),v3);
    return res;
}

std::ostream& operator<<(std::ostream& out, AngleEuler ae){
    out << ae.getPitch()<<" "<<ae.getHeading()<< " " << ae.getBank()<<"\n";
    return out;
}

AngleEuler AngleEuler::Lerp(AngleEuler efinal, float t){
    std::function<AngleEuler (AngleEuler)> wrapPI = [](AngleEuler e) -> AngleEuler {
        std::function<AngleEuler (AngleEuler)> roundAE = [](AngleEuler e) -> AngleEuler {
            return AngleEuler(round(e.getPitch()),round(e.getHeading()),round(e.getBank()));
        };
        return e-roundAE((e+ (float)M_PI)/((float)M_PI*2))*((float)M_PI*2);
    };
    return (*this + wrapPI(efinal-*this)*t);
}

AngleEuler AngleEuler::operator+(AngleEuler ae)const{
    return AngleEuler(_p+ae.getPitch(),_h+ae.getHeading(),_b+ae.getBank());
}

AngleEuler AngleEuler::operator-(AngleEuler ae)const{
    return AngleEuler(_p-ae.getPitch(),_h-ae.getHeading(),_b-ae.getBank());
}

AngleEuler AngleEuler::operator*(float d)const{
    return AngleEuler(_p*d,_h*d,_b*d);
}

AngleEuler AngleEuler::operator/(float d)const{
    return AngleEuler(_p/d,_h/d,_b/d);
}

AngleEuler AngleEuler::operator+(float d)const{
    return AngleEuler(_p+d,_h+d,_b+d);
}

AngleEuler AngleEuler::operator-(float d)const{
    return AngleEuler(_p-d,_h-d,_b-d);
}