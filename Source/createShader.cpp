#include <functions.h>

GLuint createShader(GLenum pname, std::string source) {
	const GLchar* shaderSource[1];
	std::string tmp = readShader("/home/holynerd/Desktop/Projects/SuperBibleProject/Shaders/" + source + ".glsl");
	shaderSource[0] = tmp.c_str();

	GLuint shader = glCreateShader(pname);
	glShaderSource(shader, 1, shaderSource, NULL);

	return shader;
}