#version 130
in vec3 color;
in vec3 N;
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
    vec4 ambiant = vec4((Ka *color* lightColor),1.0);
    vec4 diffuse=vec4((Kd*color*lightColor*max(dot(N,L),0)),1.0);
    vec4 specular=vec4((Ks*lightColor*facing*pow(max(dot(R,V),0),(shininess))),1.0);
    fColor=(ambiant+diffuse+specular);
}