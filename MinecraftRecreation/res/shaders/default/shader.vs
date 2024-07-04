#version 330 core
layout (location = 0) in vec3 aPos;  
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;
  
out vec3 oVertexColor;
out vec2 oVertexTextureCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    oVertexColor = aColor;
    oVertexColor = aColor * vec3(aPos.z / 16, aPos.x / 16, 0);
    oVertexTextureCoord = aTexCoord;
} 