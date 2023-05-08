#include "HLSLProgram.h"
#include<vector>
#include<fstream>
#include<iostream>
#include "Error.h"

using namespace std;

HLSLProgram::HLSLProgram():programID(0),vertexShaderID(0),fragmentShaderID(0),numAtribute(0) {

}
HLSLProgram::~HLSLProgram() {

}

void HLSLProgram::addAtributte(const string attributeName) {

}
void HLSLProgram::use() {


}
void HLSLProgram::unuse() {

}
void HLSLProgram::compileShaders(const string& vertexshaderFilePath, const string& fragmentShahderFilePath) {
	programID = glCreateProgram();
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (vertexShaderID == 0) {
		fatalError("Error creating Vertext Shader");
	}
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (fragmentShaderID == 0) {
		fatalError("Error creating Fragment Shader");
	}
	compileShader(vertexshaderFilePath, vertexShaderID);
	compileShader(fragmentShahderFilePath, fragmentShaderID);


}

void HLSLProgram::compileShader(const string& shaderPath, GLuint id) {
	string filecontent = "";
	string line = "";
	ifstream shaderFile(shaderPath);
	if (shaderFile.fail()) {
		fatalError(" Could not open " + shaderPath);
	}
	while (getline(shaderFile, line)) {
		filecontent += line + "\n";
	}
	shaderFile.close();
	const char* contents = filecontent.c_str();
	glShaderSource(id, 1, &contents, nullptr);
	glCompileShader(id);
	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	
}
void HLSLProgram::linkShader() {

}
