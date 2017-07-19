#include <functions.h>

GLuint compileShaders() {
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint tessellationShader;
	GLuint evaluationShader;
	GLuint geometryShader;

	GLuint program;

	vertexShader = createShader(
		GL_VERTEX_SHADER, 
		"vertexShader"
	);
	fragmentShader = createShader(
		GL_FRAGMENT_SHADER, 
		"fragmentShader"
	);
	tessellationShader = createShader(
		GL_TESS_CONTROL_SHADER,
		"tessellation"
	);
	evaluationShader = createShader(
		GL_TESS_EVALUATION_SHADER,
		"evaluation"
	);
	geometryShader = createShader(
		GL_GEOMETRY_SHADER,
		"geometry"
	);


	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	glCompileShader(tessellationShader);
	glCompileShader(evaluationShader);
	glCompileShader(geometryShader);

	// Create program, attach shaders to it, and link it
	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	//glAttachShader(program, tessellationShader);
	//glAttachShader(program, evaluationShader);
	//glAttachShader(program, geometryShader);

	glLinkProgram(program);

	// Delete the staders as the program has them now
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(tessellationShader);
	glDeleteShader(evaluationShader);
	glDeleteShader(geometryShader);

	return program;
}