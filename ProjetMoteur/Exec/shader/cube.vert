#version 130
in vec4 vPosition;
in vec4 vColor;
in vec3 vNormal;
uniform mat4 MVP;
out vec4 color;

void main()
{
    color = vColor;
    gl_Position = MVP * vPosition;
}