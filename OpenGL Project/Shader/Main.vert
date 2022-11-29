#version 450

in vec3 vertexIn;
in vec3 colorIn;
out vec3 colorOut;

void main(void)
{
    colorOut = colorIn;
    gl_Position = vec4(vertexIn, 1.0);

}