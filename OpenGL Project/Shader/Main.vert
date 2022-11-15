#version 460

layout (location = 0) in vec3 aPos;

void main(void)
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
unsigned int vertexShader;
vertexShader = glCreateShader(GL_VERTEX_SHADER);