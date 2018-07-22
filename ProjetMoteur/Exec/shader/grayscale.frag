#version 130
in vec2 UV;
uniform sampler2D renderedTexture;
uniform float SIZEX;
uniform float SIZEY;
out vec4 fColor;

void main(){
    // Gray Scale
    vec3 tmpV = texture(renderedTexture, UV).xyz;
    float f= (tmpV.x*0.2126+tmpV.y*0.7152+tmpV.z*0.0722);
    fColor = vec4(f,f,f, 1.0);
}