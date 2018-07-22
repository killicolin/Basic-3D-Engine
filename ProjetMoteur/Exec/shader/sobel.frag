#version 130
in vec2 UV;
uniform sampler2D renderedTexture;
uniform float SIZEX;
uniform float SIZEY;
out vec4 fColor;

void main(){
    //fColor = vec4(texture(renderedTexture, UV).xyz, 1.0);
    // Gray Scale
    /*
        vec3 tmpV = texture(renderedTexture, UV).xyz;
        float f= (tmpV.x*0.2126+tmpV.y*0.7152+tmpV.z*0.0722);
        fColor = vec4(f,f,f, 1.0);
    */
    //Blur
    /*
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
    */

    //Pixel
    /*
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
       */
    //sobel
    vec4 top= texture(renderedTexture, vec2(UV.x, UV.y+1.0 / SIZEY));
    vec4 bottom= texture(renderedTexture, vec2(UV.x, UV.y-1.0 / SIZEY));
    vec4 left= texture(renderedTexture, vec2(UV.x - 1.0/SIZEX, UV.y));
    vec4 right= texture(renderedTexture, vec2(UV.x + 1.0/SIZEX, UV.y));
    vec4 topLeft= texture(renderedTexture, vec2(UV.x - 1.0/SIZEX, UV.y + 1.0 / SIZEY));
    vec4 topRight= texture(renderedTexture, vec2(UV.x + 1.0/SIZEX, UV.y + 1.0 / SIZEY));
    vec4 bottomLeft = texture(renderedTexture, vec2(UV.x - 1.0/SIZEX, UV.y - 1.0 / SIZEY));
    vec4 bottomRight = texture(renderedTexture, vec2(UV.x + 1.0/SIZEX, UV.y - 1.0 / SIZEY));
    vec4 sx = -topLeft - 2 * left - bottomLeft + topRight+ 2*right + bottomRight;
    vec4 sy = -topLeft - 2 * top - topRight+ bottomLeft + 2*bottom + bottomRight;
    vec4 sobel = sqrt(sx * sx + sy * sy);
    fColor = sobel;

}