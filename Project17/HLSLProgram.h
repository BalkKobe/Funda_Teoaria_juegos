#pragma once
#include<Gl/glew.h>
#include<string>

using namespace std;


class HLSLProgram
{
private:
	GLuint programID;
	GLuint fragmentShaderID;
	GLuint vertexShaderID;
	void compileShader(const string& shaderPath, GLuint id);

public:
	HLSLProgram();
	~HLSLProgram();
	int numAtribute;
	void addAtributte(const string attributeName);
	void use();
	void unuse();
	void compileShaders(const string& vertexshaderFilePath, const string& fragmentShahderFilePath);
	void linkShader();
	GLuint getUniformLocation(const string& name);

};

