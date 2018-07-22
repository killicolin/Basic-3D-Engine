
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#ifndef PROJETMOTEUR_OPENGLFUNCTION_H
#define PROJETMOTEUR_OPENGLFUNCTION_H
GLuint initShaders(const char* vShaderFile, const char* fShaderFile);
void glew_init();
GLchar* readShaderSource(const char * shaderFile);
#endif //PROJETMOTEUR_OPENGLFUNCTION_H
