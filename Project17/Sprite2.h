#pragma once
#include<GL/glew.h>
using namespace std;

class Sprite2
{
private:
	float x, y;
	int width, height;
	GLuint vboID;
public:
	Sprite2();
	~Sprite2();
	void init(float x, float y, int width, int height);
	void draw();
};


