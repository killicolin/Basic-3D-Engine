#version 130
in vec4 vPosition;
in vec4 vColor;
in vec3 vNormal;
uniform mat4 MVP;
uniform mat3 NM; // Normal Matrix
uniform mat3 MV; // Model View
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 viewPosition;
uniform float Ka;
uniform float Kd;
uniform float Ks;
uniform float shininess;
out vec3 N;
out vec3 f_coord;
out vec3 color;
void main()
{
    N = normalize(NM * vNormal);
    f_coord=vPosition.xyz*MV;
    gl_Position = MVP*vPosition;
    color=vColor.xyz;
}