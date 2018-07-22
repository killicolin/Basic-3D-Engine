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
out vec3 f_coord;
out vec4 color;
void main()
{
    f_coord=vPosition.xyz*MV;
    gl_Position = MVP*vPosition;
    vec3 N = normalize(NM * vNormal);
    float facing;
    vec3 L = normalize(lightPosition-f_coord);
    vec3 R = reflect(L,N);
    vec3 V = normalize(viewPosition-f_coord);
    if(dot(N,L)>0){
        facing=1;
    }
    else{
        facing=0;
    }
    vec4 ambiant = vec4((Ka *vColor.xyz* lightColor),1.0);
    vec4 diffuse=vec4((Kd*vColor.xyz*lightColor*max(dot(N,L),0)),1.0);
    vec4 specular=vec4((Ks*lightColor*facing*pow(max(dot(R,V),0),(shininess))),1.0);
    color=(ambiant+diffuse+specular);
}