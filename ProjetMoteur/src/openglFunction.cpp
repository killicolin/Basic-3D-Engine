
#include <iostream>
#include "openglFunction.h"

GLchar* readShaderSource(const char * shaderFile)
{
    FILE* fp;
    fp=fopen(shaderFile, "r");
    GLchar* buf;
    long size;
    if (fp == NULL) return NULL;
    fseek(fp, 0L, SEEK_END);//go to end
    size = ftell(fp);
    //get size
    fseek(fp, 0L, SEEK_SET);//go to beginning
    buf = (GLchar*)malloc((size+1)*sizeof(GLchar));
    fread(buf, 1, size, fp);
    buf[size] = 0;
    fclose(fp);
    return buf;
}


void glew_init(){
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
/* glewInit failed*/
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Using GLEW %s\n",
            glewGetString(GLEW_VERSION));
}


GLuint initShaders(const char* vShaderFile, const char* fShaderFile) {
    struct Shader {
        const char *filename;
        GLenum type;
        GLchar *source;
    }
            shaders[2] = {
            {vShaderFile, GL_VERTEX_SHADER,   NULL},
            {fShaderFile, GL_FRAGMENT_SHADER, NULL}
    };

    GLuint program = glCreateProgram();
    for (int i = 0; i < 2; ++i) {
        Shader &s = shaders[i];
        s.source = readShaderSource(s.filename);
        if (shaders[i].source == NULL) {
            printf("Failed to read %s\n", s.filename);
            exit(EXIT_FAILURE);
        }
        GLuint shader = glCreateShader(s.type);
        glShaderSource(shader, 1, (const GLchar **) &s.source, NULL);
        glCompileShader(shader);
        GLint compiled;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            printf("%s failed to compile:\n", s.filename);
            GLint logSize;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
            char *logMsg = new char[logSize];
            glGetShaderInfoLog(shader, logSize, NULL, logMsg);
            printf("%s\n", logMsg);
            delete[] logMsg;
            exit(EXIT_FAILURE);
        }
        delete[] s.source;
        glAttachShader(program, shader);
    }
    /* link and error check */
    glLinkProgram(program);
    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked) {
        printf("Shader program failed to link:\n");
        GLint logSize;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
        char *logMsg = new char[logSize];
        glGetProgramInfoLog(program, logSize, NULL, logMsg);
        printf("%s\n", logMsg);
        delete[] logMsg;
        exit(EXIT_FAILURE);
    }
    /* use program object */
    glUseProgram(program);
    return program;
}