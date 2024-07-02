#version 330 core

out vec4 FragColor;  

in vec3 oVertexColor;
in vec2 oVertexTextureCoord;
 
uniform sampler2D oTexture;

void main()
{
    FragColor = texture(oTexture, oVertexTextureCoord) * vec4(oVertexColor, 1);
    //FragColor = vec4(oVertexTextureCoord, 0.0, 1.0);
}