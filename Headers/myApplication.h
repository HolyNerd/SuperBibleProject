#ifndef MY_APPLICATION_H
#define MY_APPLICATION_H

#include <math.h>
#include <sb7.h>
#include <vmath.h>
#include <functions.h>

class MyApplication : public sb7::application {
public:
	virtual void startup();
	virtual void render(double currentTime);
	virtual void shutdown();
private:
	GLuint renderingProgram;
	GLuint vertexArrayObject;
};

#endif // MY_APPLICATION_H