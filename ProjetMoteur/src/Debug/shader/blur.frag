#version 130
in vec2 UV;
uniform sampler2D renderedTexture;
uniform float SIZEX;
uniform float SIZEY;
out vec4 fColor;

void main(){
    //Blur
    float blurSizeH = 1.0 / SIZEX;
    float blurSizeV = 1.0 / SIZEY;
    vec3 sum=vec3(0.0);
    for (int x = -3; x <= 3; x++)
            for (int y = -3; y <= 3; y++)
                sum += texture(
                    renderedTexture,
                    vec2(UV.x + x * blurSizeH, UV.y + y * blurSizeV)
                ).xyz / 42.;
    fColor = vec4(sum.xyz,1.0);

}