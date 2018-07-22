#version 130
in vec2 UV;
uniform sampler2D renderedTexture;
uniform float SIZEX;
uniform float SIZEY;
out vec4 fColor;

void main(){
    //Pixel
    float blurSizeH = 1.0 / SIZEX;
    float blurSizeV = 1.0 / SIZEY;
    float pixX= (int(UV.x*SIZEX) / 8)/SIZEX;
    float pixY= (int(UV.y*SIZEY) / 8)/SIZEY;
    vec3 sum=vec3(0.0);
    for (int x = 0; x < 8; x++)
            for (int y = 0; y < 8; y++)
                sum += texture(
                    renderedTexture,
                    vec2(pixX*8 + x * blurSizeH, pixY*8 + y * blurSizeV)
                ).xyz / 64.;
    fColor = vec4(sum.xyz,1.0);
}