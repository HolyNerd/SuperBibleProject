#pragma once
#include <sb7.h>
#include <string>


GLuint compileShaders();
std::string readShader(const std::string fileName);
GLuint createShader(GLenum, std::string source);