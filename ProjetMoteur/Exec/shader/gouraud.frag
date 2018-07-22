#version 130
in vec4 color;
in vec3 f_coord;
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 viewPosition;
uniform float Ka;
uniform float Kd;
uniform float Ks;
uniform float shininess;
out vec4 fColor; // final fragment color
void main()
{
    fColor=color;
}