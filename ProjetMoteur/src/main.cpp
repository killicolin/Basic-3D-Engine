#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "openglFunction.h"
#include <vector>
#include "Vector4f.h"
#include "MatrixC4.h"
#include "RectangularPrism.h"
#include "Cylinder.h"
#include "Triangle.h"
#include "CoordinateSystem.h"
#include "ComplexSurface.h"
#include "Sphere.h"
#include "Plan.h"
#include "Light.h"
#include <GL/glew.h>
#include <stdlib.h>  
#include "interfaceCreationObjet.h"
#include <stdio.h>
using namespace std;

#define BUFFER_OFFSET(offset) ((GLvoid*)(offset))
int SCREEN_X = 1024;
int SCREEN_Y = 768;
int mode=0;
float dist=6.;
float rotationVX=0;
float rotationVY=0;
float rotationX=0;
float rotationY=0;
float translationX=0;
float translationY=0;
float translationZV=-6;
float tmpx=0;
float tmpy=0;
float scale=1;
int modeColor=1;
int selectorItem=0;
bool leftClic=false;
bool rightClic=false;
bool fillMode=true;
bool projectionMode=true;
using namespace std;

GLuint vaoquad;
GLuint vboquad;
void initQuad()
{
    glGenVertexArrays(1, &vaoquad);
    glBindVertexArray(vaoquad);
    const float vertices[] =
            { -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -1.0f };
    glGenBuffers(1, &vboquad);
    glBindBuffer(GL_ARRAY_BUFFER, vboquad);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
                 GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);
}
GLuint frameBuffer=0;
GLuint renderedTexture=0;
GLuint depthRenderBuffer=0;
void createFrameBuffer() {
    glGenFramebuffers(1, &frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    glGenTextures(1, &renderedTexture);
    glBindTexture(GL_TEXTURE_2D, renderedTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCREEN_X, SCREEN_Y, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glGenRenderbuffers(1, &depthRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthRenderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, SCREEN_X, SCREEN_Y);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderBuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,renderedTexture, 0);
    GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(1, DrawBuffers);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        fprintf(stderr, "Error creating Framebuffer\n"); exit(EXIT_FAILURE);
    }
}

Vector3f toVec3(Vector v){
    if(v.size()<3){
        throw std::invalid_argument("need a vector with a ");
    }
    Vector3f res=Vector3f(v[0],v[1],v[2]);
    return res;
}
vector<ObjectRender> objetList;

void createObject(){
    string forme;
    cout << "What do you want to create? (cf README)" << endl;
	cin>>forme;
    for(unsigned int i = 0; i < forme.size(); i++) {
        forme.at(i) = toupper(forme.at(i));
    }
    if(forme=="CUBE")
        objetList.push_back(creationCube());
    else if(forme=="PRISM")
        objetList.push_back(creationPrism());
    else if(forme=="CYLINDRE")
        objetList.push_back(creationCylinder());
    else if(forme=="PLAN")
        objetList.push_back(creationPlan());
    else if(forme=="TRIANGLE")
        objetList.push_back(creationTriangle());
    else if(forme=="SPHERE")
        objetList.push_back(creationSphere());
    else if(forme=="AUTRE")
        objetList.push_back(creationAutre());
    else
        cout << "Commande ignoré"<< endl;
}

MatrixC4 projection=MatrixC4();
MatrixC4 view=MatrixC4();

MatrixC4 updateRotation(MatrixC4 m){
    MatrixC4 Model = MatrixC4();
    Model.setIdentity();
    MatrixC tmpviewModel=view*m;
    Vector3f vrot=toVec3((tmpviewModel.line(0)));
    vrot.normalize();
    Model.rotationArbitraire(vrot,rotationY*float(M_PI/120));
    MatrixC4 rot = MatrixC4();
    rot.setIdentity();
    vrot=toVec3((tmpviewModel.line(1)));
    vrot.normalize();
    rot.rotationArbitraire(vrot,rotationX*float(M_PI/120));
    Model=Model*rot;
    rotationX=0;
    rotationY=0;
    return Model;
}

void updateViewRotation(){
    MatrixC4 roty=MatrixC4();
    view.setTranslation(0,0,translationZV);
    Vector3f vrot=toVec3((view.line(0)));
    vrot.normalize();
    roty.rotationArbitraire(vrot,rotationVY*float(M_PI/120));
    MatrixC4 rotx=MatrixC4();
    vrot=toVec3((view.line(1)));
    vrot.normalize();
    rotx.rotationArbitraire(vrot,rotationVX*float(M_PI/120));
    view=view*roty*rotx;
    rotationVX=0;
    rotationVY=0;
}

MatrixC4 updateScale(){
    MatrixC4 scaleMatrix = MatrixC4();
    scaleMatrix.scaleCardinal(scale,scale,scale);
    scale=1;
    return scaleMatrix;
}

MatrixC4 updateTranslation(MatrixC4 m){
    MatrixC4 translationMatrix = MatrixC4();
    MatrixC tmpviewModel=view*m;
    Vector3f vx=toVec3((tmpviewModel.line(0)));
    vx.normalize();
    vx*=translationX;
    Vector3f vy=toVec3((tmpviewModel.line(1)));
    vy.normalize();
    vy*=translationY;
    translationMatrix.setTranslation((vx+vy));
    translationX=0;
    translationY=0;
    return translationMatrix;
}
GLuint postProcess;
GLuint sobel;
GLuint grayScale;
GLuint blur;
GLuint pixel;
GLuint processUsed;

void initProgram(){
    postProcess=initShaders("shader/pass.vert","shader/pass.frag");
    grayScale=initShaders("shader/pass.vert","shader/grayscale.frag");
    blur=initShaders("shader/pass.vert","shader/blur.frag");
    pixel=initShaders("shader/pass.vert","shader/pixel.frag");
    sobel=initShaders("shader/pass.vert","shader/sobel.frag");
}

Light light=Light(Vector4f(1,1,1,1.0),Vector3f(1,1,1));
CoordinateSystem cs=CoordinateSystem(Vector4f(0.0,0.0,0.0,1.0));

void display()
{
    glEnable(GL_DEPTH_TEST);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    updateViewRotation();
    cs.draw(projection,view);
    if(fillMode)
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    else
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    if(objetList.size()>0){
        objetList[selectorItem].addModel(updateRotation(objetList[selectorItem].getModel()));
        objetList[selectorItem].addModel(updateScale());
        objetList[selectorItem].addModel(updateTranslation(objetList[selectorItem].getModel()));
    }
    for (unsigned int i = 0; i < objetList.size(); ++i) {
        objetList[i].draw(projection,view,light,modeColor);
    }
    switch(mode){
        case 0:
            processUsed=postProcess;
            break;
        case 1:
            processUsed=grayScale;
            break;
        case 2:
            processUsed=blur;
            break;
        case 3:
            processUsed=pixel;
            break;
        case 4:
            processUsed=sobel;
            break;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //on recupère le rendu comme texture
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glActiveTexture(GL_TEXTURE0 + 0);
    glBindTexture(GL_TEXTURE_2D, renderedTexture);
    glUseProgram(processUsed);
    glUniform1f(glGetUniformLocation(processUsed, "SIZEX"), float(SCREEN_X));
    glUniform1f(glGetUniformLocation(processUsed, "SIZEY"), float(SCREEN_Y));
    glBindVertexArray(vaoquad);
    //on affiche la texture récupéré en appliquant le filtre choisi
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
        case 'q':case 'Q':
            rotationVX-=1;
            break;
        case 'z':case 'Z':
            rotationVY-=1;
            break;
        case 's':case 'S':
            rotationVY+=1;
            break;
        case 'd':case 'D':
            rotationVX+=1;
            break;
        case 'a':case 'A':
            translationZV-=0.1f;
            break;
        case 'e':case 'E':
            translationZV+=0.1f;
            break;
        case 27:
            glDeleteBuffers(1, &vboquad);
            glDeleteVertexArrays(1, &vaoquad);
            for (unsigned int i = 0; i < objetList.size(); ++i) {
                objetList[i].free();
            }
            exit(EXIT_SUCCESS);
        case '0':
            modeColor=0;
            break;
        case '1':
            modeColor=1;
            break;
        case '2':
            modeColor=2;
            break;
        case '3':
            modeColor=3;
            break;
        case '4':
            mode=0;
            break;
        case '5':
            mode=1;
            break;
        case '6':
            mode=2;
            break;
        case '7':
            mode=3;
            break;
        case '8':
            mode=4;
            break;
        case 'f':case 'F':
            fillMode=!fillMode;
            break;
        case 'p':case 'P':
            if(projectionMode)
                projection.perspective(float(M_PI/6),1.0f, 100.0f);
            else
                projection.orthographic(-1,1,-1,1,-100,100);
            projectionMode=!projectionMode;
            break;
        case '+':
            if(objetList.size()>0)
                selectorItem=(selectorItem+1)%objetList.size();
            break;
        case '-':
            if(objetList.size()>0)
                selectorItem=(objetList.size()+selectorItem-1)%objetList.size();
            break;
        case 'c':case 'C':
            createObject();
            break;
    }
    glutPostRedisplay();
}

void init(){
    glew_init();
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    glViewport(0,0,SCREEN_X,SCREEN_Y);
    createFrameBuffer();
    initQuad();
    initProgram();
    projection.perspective(float(M_PI/6),1.0f, 100.0f);
    view.setTranslation(0,0,translationZV);
}

void mousefunc(int button,int state, int x, int y){
    if (button==3 || button==4){
        if(state==GLUT_UP)return;
        if(button==3){
            scale+=0.05f;
        }
        if(button==4){
            scale-=0.05f;
        }
        glutPostRedisplay();
    }
    if(state==GLUT_DOWN) {
        tmpx=(x / ((float) SCREEN_X));
        tmpy=(-y / ((float) SCREEN_Y));
        leftClic = button == 0;
        rightClic = button == 2;
    }
}

void motionfunc(int x, int y) {
    float tx = (x / ((float) SCREEN_X));
    float ty = (-y / ((float) SCREEN_Y));
    if(leftClic) {
        rotationX += (tx - tmpx) * 100;
        rotationY += (tmpy - ty) * 100;
        glutPostRedisplay();
    }else if(rightClic){
        translationX = (tx-tmpx)*4;
        translationY = (ty-tmpy)*4;
        glutPostRedisplay();
    }
    tmpx = tx;
    tmpy = ty;
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutCreateWindow("Moteur 3D");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mousefunc);
    glutMotionFunc(motionfunc);
    glutMainLoop();
    return 0;
}