#include <myApplication.h>
#include <iostream>

void MyApplication::startup() {
	renderingProgram = compileShaders();
	glCreateVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);
}

void MyApplication::render(double currentTime) {
	static const float data[] = {
		0.25, -0.25, 0.5, 1.0,
		-0.25, -0.25, 0.5, 1.0,
		0.25, 0.25, 0.5, 1.0
	};
	GLuint buffer;
	
	glCreateBuffers(1, &buffer);
	glNamedBufferStorage (
		buffer,
		1024 * 1024,
		NULL,
		GL_MAP_WRITE_BIT
	);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);

	const GLfloat color[] = {
		(float)sin(currentTime) * 0.5f + 0.5f,
		(float)cos(currentTime) * 0.5f + 0.5f,
		0.0f, 1.0f
	};

	glClearBufferfv(GL_COLOR, 0, color);

	glUseProgram(renderingProgram);

	GLfloat attrib[] = {
		(float)sin(currentTime) * 0.5f,
		(float)cos(currentTime) * 0.6f,
		0.0f, 0.0f
	};


	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyApplication::shutdown() {
	glDeleteVertexArrays(1, &vertexArrayObject);
	glDeleteProgram(renderingProgram);
	glDeleteVertexArrays(1, &vertexArrayObject);
}

DECLARE_MAIN(MyApplication);
