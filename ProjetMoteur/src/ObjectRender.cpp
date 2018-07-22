

#include "ObjectRender.h"
#include "Light.h"

#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))

ObjectRender::ObjectRender(Vector4f position){
    _model=MatrixC4();
    _model.setTranslation(position.getX(),position.getY(),position.getZ());
    ka=0.2f;
    kd=0.7f;
    ks=1.f;
    kn=10;
}

ObjectRender::ObjectRender(Vector4f position,float Ka,float Kd,float Ks,float Kn):ObjectRender(position){
    ka=Ka;
    kd=Kd;
    ks=Ks;
    kn=Kn;
}

void ObjectRender::draw(MatrixC4 P,MatrixC4 V,Light light,int mode){
    glGenVertexArrays(1, &vaoCube);
    glBindVertexArray(vaoCube);

    glGenBuffers(1, &vboCube);
    glBindBuffer(GL_ARRAY_BUFFER, vboCube);

    int sp =(2*sizeof(float)*4+1*sizeof(float)*3)*(vertexBuffer.size()/3);
    glBufferData(GL_ARRAY_BUFFER, sp, NULL, GL_STATIC_DRAW);
    for (unsigned int i = 0; i <vertexBuffer.size()/3; ++i) {
        glBufferSubData(GL_ARRAY_BUFFER,i*11*sizeof(float),4*sizeof(float), vertexBuffer[i*3].getData());
        glBufferSubData(GL_ARRAY_BUFFER,(i*11+4)*sizeof(float),4*sizeof(float), vertexBuffer[i*3+1].getData());
        glBufferSubData(GL_ARRAY_BUFFER,(i*11+8)*sizeof(float),3*sizeof(float), vertexBuffer[i*3+2].getData());
    }
    GLuint program;
    switch(mode){
        case 0:
            program=initShaders("shader/cube.vert","shader/cube.frag");
            break;
        case 1:
            program=initShaders("shader/brut.vert","shader/brut.frag");
            break;
        case 2:
            program=initShaders("shader/gouraud.vert","shader/gouraud.frag");
            break;
        case 3:
            program=initShaders("shader/phong.vert","shader/phong.frag");
            break;
    }
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
    MatrixC4 MV;
    MV=V*_model;
    MatrixC3 mv=MV.toMatrix3();
    //cout << mv << endl;
    glUniformMatrix3fv(glGetUniformLocation(program, "MV"), 1, GL_FALSE, mv.getData());
    mv.normalize();
    glUniformMatrix3fv(glGetUniformLocation(program, "NM"), 1, GL_FALSE, mv.getData());
    glUniform1f(glGetUniformLocation(program, "Ka"), ka);

    glUniform3f(glGetUniformLocation(program, "lightColor"),  light.getColor()[0], light.getColor()[1], light.getColor()[2]);

    glUniform3f(glGetUniformLocation(program, "lightPosition"), light.getPosition()[0], light.getPosition()[1], light.getPosition()[2]);

    glUniform3f(glGetUniformLocation(program, "viewPosition"), V(0,3), V(1,3), V(2,3));

    glUniform1f(glGetUniformLocation(program, "Kd"), kd);

    glUniform1f(glGetUniformLocation(program, "Ks"), ks);

    glUniform1f(glGetUniformLocation(program, "shininess"),kn);
    glDrawArrays(GL_TRIANGLES, 0, vertexBuffer.size());
}

void ObjectRender::setModel(MatrixC4 m1){
    _model=m1;
}

void ObjectRender::addModel(MatrixC4 m1){
    _model=_model*m1;
}

MatrixC4 ObjectRender::getModel(){
    return _model;
}

void ObjectRender::free(){
    for (unsigned int i = 0; i < vertexBuffer.size(); ++i) {
        delete(vertexBuffer[i].getData());
    }
    glDeleteBuffers(1, &IndexVBO);
    glDeleteBuffers(1, &vboCube);
    glDeleteVertexArrays(1, &vaoCube);
}


float ObjectRender::getKa(){
    return ka;
}

float ObjectRender::getKd(){
    return kd;
}

float ObjectRender::getKs(){
    return ks;
}

float ObjectRender::getKn(){
    return kn;
}

void ObjectRender::setMaterial(float Ka,float Kd,float Ks,float Kn){
    ka=Ka;
    kd=Kd;
    ks=Ks;
    kn=Kn;
}