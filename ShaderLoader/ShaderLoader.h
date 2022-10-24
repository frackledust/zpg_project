#pragma once
//GLEW - The OpenGL Extension Wrangler Library
#include <GL/glew.h>

#include <string.h> 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>



using namespace std;

class ShaderLoader
{
	GLuint vertexID = 0;
	GLuint fragmentID = 0;
protected:
	GLuint	shaderProgramID=0;

    string loadFile(const char *fname);

public:
	GLuint loadShader(const char *vertexFile, const char *fragmentFile);
	void deleteShader() const;
	ShaderLoader() = default;
	ShaderLoader(const char *vertexFile, const char *fragmentFile, GLuint *shaderID);
	~ShaderLoader() = default;
};
