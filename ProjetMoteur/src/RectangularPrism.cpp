
#include "RectangularPrism.h"
#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))

RectangularPrism::RectangularPrism(Vector4f position,Vector4f color, float xlen,float ylen, float zlen):ObjectRender(position){
    Vector4f _vertex[8];
    Vector4f _color[6];
    Vector3f _normal[6];
    xlen/=2;
    ylen/=2;
    zlen/=2;
    _vertex[0]=Vector4f(-xlen,-ylen,zlen,1.0);
    _vertex[1]=Vector4f(-xlen,ylen,zlen,1.0);
    _vertex[2]=Vector4f(xlen,-ylen,zlen,1.0);
    _vertex[3]=Vector4f(xlen,ylen,zlen,1.0);
    _vertex[4]=Vector4f(-xlen,-ylen,-zlen,1.0);
    _vertex[5]=Vector4f(-xlen,ylen,-zlen,1.0);
    _vertex[6]=Vector4f(xlen,-ylen,-zlen,1.0);
    _vertex[7]=Vector4f(xlen,ylen,-zlen,1.0);
    _normal[0]=Vector3f(.0,.0,1.0);
    _normal[1]=Vector3f(.0,-1.0,.0);
    _normal[2]=Vector3f(.0,.0,-1.0);
    _normal[3]=Vector3f(.0,1.0,.0);
    _normal[4]=Vector3f(1.0,.0,.0);
    _normal[5]=Vector3f(-1.0,.0,.0);
    for (int i = 0; i < 6; ++i) {
        _color[i]=color;
    }
    colorCube(_vertex,_color,_normal);
}

void RectangularPrism::colorCarre(Vector4f * vertex,Vector4f color,Vector3f normal,int i1,int i2,int i3,int i4){
    i1-=1;
    i2-=1;
    i3-=1;
    i4-=1;
    vertexBuffer.push_back(vertex[i2]);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex[i3]);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex[i1]);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);

    vertexBuffer.push_back(vertex[i2]);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex[i3]);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
    vertexBuffer.push_back(vertex[i4]);
    vertexBuffer.push_back(color);
    vertexBuffer.push_back(normal);
}

void RectangularPrism::colorCube(Vector4f * vertex,Vector4f * color,Vector3f * normal){
    //face
    colorCarre(vertex,color[0],normal[0],1,2,3,4);
    //bas
    colorCarre(vertex,color[1],normal[1],3,7,1,5);
    //derrière
    colorCarre(vertex,color[2],normal[2],5,6,7,8);
    //au dessus
    colorCarre(vertex,color[3],normal[3],2,4,6,8);
    //droite
    colorCarre(vertex,color[4],normal[4],3,7,4,8);
    //gauche
    colorCarre(vertex,color[5],normal[5],1,5,2,6);
}
/*
void RectangularPrism::draw(MatrixC4 P,MatrixC4 V){
        glGenVertexArrays(1, &vaoCube);
        glBindVertexArray(vaoCube);

        glGenBuffers(1, &vboCube);
        glBindBuffer(GL_ARRAY_BUFFER, vboCube);

        int sp =(2*sizeof(float)*4+1*sizeof(float)*3)*(vertexBuffer.size()/3);
        int sc = 8*sizeof(float)*4;
        int si=_indexList.size()* sizeof(int);
        glBufferData(GL_ARRAY_BUFFER, sp, NULL, GL_STATIC_DRAW);
        for (int i = 0; i <vertexBuffer.size()/3; ++i) {
            glBufferSubData(GL_ARRAY_BUFFER,i*11*sizeof(float),4*sizeof(float), vertexBuffer[i*3].getData());
            glBufferSubData(GL_ARRAY_BUFFER,(i*11+4)*sizeof(float),4*sizeof(float), vertexBuffer[i*3+1].getData());
            glBufferSubData(GL_ARRAY_BUFFER,(i*11+8)*sizeof(float),3*sizeof(float), vertexBuffer[i*3+2].getData());
        }
        for (int i = 0; i < 8; ++i) {
            glBufferSubData(GL_ARRAY_BUFFER,i*4*sizeof(float)+sp,4*sizeof(float), _color[i].getData());
        }
        glGenBuffers(1, &IndexVBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, si, &_indexList[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, vboCube);
        GLuint program=initShaders("cube.vert","cube.frag");

        GLuint vPosition =glGetAttribLocation(program, "vPosition");
        glEnableVertexAttribArray(vPosition);
        glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE,11*sizeof(GLfloat), BUFFER_OFFSET(0));

        GLuint vColor = glGetAttribLocation(program, "vColor");
        glEnableVertexAttribArray(vColor);
        glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 11*sizeof(GLfloat), BUFFER_OFFSET(4*sizeof(GLfloat)));

        GLuint vNormal = glGetAttribLocation(program, "vNormal");
        glEnableVertexAttribArray(vNormal);
        glVertexAttribPointer(vNormal, 3, GL_FLOAT, GL_FALSE, 11*sizeof(GLfloat), BUFFER_OFFSET(8*sizeof(GLfloat)));

        glUniformMatrix4fv(glGetUniformLocation(program, "MVP"), 1, GL_FALSE,(P*V*_model).getData());
        //updateMVP(program,MVP,updateModel1());
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBO);
        //glDrawElements(GL_TRIANGLES,_indexList.size(), GL_UNSIGNED_INT, BUFFER_OFFSET(0));
        glDrawArrays(GL_TRIANGLES, 0, vertexBuffer.size());
}
*/
void RectangularPrism::setColorFace(Vector4f *colorFace){
    int len=vertexBuffer.size()/3;
    for  (int i = 0; i < len; ++i) {
        vertexBuffer[3*i+1]=colorFace[i/6];
    }
}
/*
void RectangularPrism::free(){
    for (int i = 0; i < vertexBuffer.size(); ++i) {
        delete(vertexBuffer[i].getData());
    }
    //free(_indexList);
    glDeleteBuffers(1, &IndexVBO);
    glDeleteBuffers(1, &vboCube);
    glDeleteVertexArrays(1, &vaoCube);
}*/