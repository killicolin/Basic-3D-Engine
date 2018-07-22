#version 130
in vec4 vPosition;
in vec3 vNormal;
uniform mat4 MVP;
uniform mat3 NM; // Normal Matrix
uniform mat3 MV; // Model View
out vec3 f_coord;
out vec4 color;
void main()
{
    vec3 N = normalize(MV * vNormal);
    f_coord=vPosition.xyz*MV;
    gl_Position = MVP*vPosition;
    color = vec4(abs(N),1.0f);
}