#include "CoordinateSystem.h"
#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))

CoordinateSystem::CoordinateSystem(Vector4f position):ObjectRender(position){
    vertexBuffer.push_back(Vector4f(0.f,0.f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(1.f,0.f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(0.1f,0.f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(1.f,0.f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(0.f,0.f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(0.f,1.f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(0.f,.1f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(0.f,1.f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(0.f,0.f,0.f,1.f));
    vertexBuffer.push_back(Vector4f(0.f,0.f,1.f,1.f));
    vertexBuffer.push_back(Vector4f(0.f,0.f,.1f,1.f));
    vertexBuffer.push_back(Vector4f(0.f,0.f,1.f,1.f));
}


void CoordinateSystem::draw(MatrixC4 P,MatrixC4 V){
    glGenVertexArrays(1, &vaoCube);
    glBindVertexArray(vaoCube);

    glGenBuffers(1, &vboCube);
    glBindBuffer(GL_ARRAY_BUFFER, vboCube);

    int sp = vertexBuffer.size()*sizeof(float)*4;
    glBufferData(GL_ARRAY_BUFFER, sp, NULL, GL_STATIC_DRAW);
    for( unsigned int i = 0; i <vertexBuffer.size(); ++i) {
        glBufferSubData(GL_ARRAY_BUFFER,i*4*sizeof(float),4*sizeof(float), vertexBuffer[i].getData());
    }
    GLuint program=initShaders("shader/cube.vert","shader/cube.frag");

    GLuint vPosition =glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE,8*sizeof(GLfloat), BUFFER_OFFSET(0));

    GLuint vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), BUFFER_OFFSET(4*sizeof(GLfloat)));
    glUniformMatrix4fv(glGetUniformLocation(program, "MVP"), 1, GL_FALSE,(P*V*_model).getData());
    glDrawArrays(GL_LINES, 0, vertexBuffer.size());
}
