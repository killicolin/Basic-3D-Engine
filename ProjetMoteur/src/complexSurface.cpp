#include "ComplexSurface.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))

void splitFunc(istringstream &s_str, vector<vector<short>> &f){
    std::vector<std::string> words;
    std::string word = "";
    while (std::getline(s_str, word, '/')){
        if(word.find(' ')!=string::npos){
            istringstream tmp(word);
            while (std::getline(tmp, word, ' ')){
                words.push_back(word);
            }
        }
        else {
            words.push_back(word);
        }
    }
    for (unsigned int s = 0; s < words.size(); s+=3) {
        vector<short> v3;
        v3.push_back((short)::atof(words.at(s).c_str()));
        v3.push_back((short)::atof(words.at(s+1).c_str()));
        v3.push_back((short)::atof(words.at(s+2).c_str()));
        f.push_back(v3);
    }
}


ComplexSurface::ComplexSurface(Vector4f position,Vector4f color,char* filename):ObjectRender(position){
    vector<Vector4f> v;
    vector<Vector3f> smoothVN;
    vector<Vector3f> vn;
    vector<vector<short>> f;
    _model=MatrixC4();
    _model.setTranslation(position.getX(),position.getY(),position.getZ());
    ifstream in(filename, ios::in);
    if (!in) {
        cerr << "Cannot open " << filename << endl;
        exit(1);
    }
    string line;
    float x,y,z,w;
    while (getline(in, line)) {
        if (line.substr(0, 2) == "v ") {
            istringstream s(line.substr(2));
            s >> x;
            s >> y;
            s >> z, w = 1.0f;
            Vector4f v4=Vector4f(x,y,z,w);
            v.push_back(v4);
            Vector3f v3=Vector3f(0,0,0);
            smoothVN.push_back(v3);
        }
        else if(line.substr(0, 3) == "vt ") {
            istringstream s(line.substr(3));
            stringstream si;
            s >> w;
            s >> w;
        }
        else if(line.substr(0, 3) == "vn ") {
            istringstream s(line.substr(3));
            s >> x;
            s >> y;
            s >> z;
            Vector3f v3=Vector3f(x,y,z);
            vn.push_back(v3);
        }
        else if(line.substr(0, 2) == "f "){
            istringstream s(line.substr(2));
            splitFunc(s,f);
        }
    }
    for (unsigned int i = 0; i < f.size(); ++i) {
        smoothVN[f.at(i).at(0)-1]+=vn.at(f.at(i).at(2)-1);
    }
    for (unsigned int i = 0; i < smoothVN.size(); ++i) {
        smoothVN[i].normalize();
    }
    for (unsigned int i = 0; i < f.size(); ++i) {
        vertexBuffer.push_back(v[f[i][0]-1]);
        vertexBuffer.push_back(color);
        vertexBuffer.push_back(smoothVN[f[i][0] - 1]);
    }
}