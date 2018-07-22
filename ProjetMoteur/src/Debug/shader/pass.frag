#version 130
in vec2 UV;
uniform sampler2D renderedTexture;
uniform float SIZEX;
uniform float SIZEY;
out vec4 fColor;

void main(){
    //clear
    fColor = vec4(texture(renderedTexture, UV).xyz, 1.0);
}