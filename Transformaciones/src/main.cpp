//============================================================================
// Name        : Display Multiply object only with object
// Professor   : Herminio Paucar
// Version     :
// Description : Display Multiply object only with object
//============================================================================

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>

#include "Utils.h"

GLuint renderingProgram;
GLfloat* m_VerticesCuad;
GLuint n_CoordsCuad;
GLuint m_VBOCuad;

GLfloat m_VerticesCirc[150];
GLuint n_CoordsCirc=150;
GLuint m_VBOCirc;
GLuint m_VAO;

const float radius = 0.1;
const float pi = 3.141592653589793;
const float twicePi = 2.0f*pi;
const float numberOfSides = 50;
float x_vertex[50];
float y_vertex[50];

float x=0.0;
float inc = 0.02;

float posi=-1.1;
float incpos = 0.005955555;
float rad = 1;
float incrad = 1.0025;
float radant = rad;

using namespace std;

void init (GLFWwindow* window) {
	renderingProgram = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");

	// Cria um ID na GPU para um array de  buffers
	glGenVertexArrays(1, &m_VAO);


	glBindVertexArray(m_VAO);
	for(int i=0;i<50;i++){
			x_vertex[i] = radius * cos(i * twicePi / numberOfSides);
			y_vertex[i] = radius * sin(i * twicePi / numberOfSides);
		}
		x_vertex[49] = radius * cos(50 * twicePi / numberOfSides);
		y_vertex[49] = radius * sin(50 * twicePi / numberOfSides);


		for(int i=0;i<50;i++){
			m_VerticesCirc[i*3] = x_vertex[i];
			m_VerticesCirc[i*3+1] = y_vertex[i];
			m_VerticesCirc[i*3+2] = 0.0;
		}


	glGenBuffers(1, &m_VBOCirc);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOCirc);

	glBufferData(
			GL_ARRAY_BUFFER,	// TARGET associado ao nosso buffer
			n_CoordsCirc * sizeof(GLfloat),	// tamanho do buffer
			m_VerticesCirc,			// Dados a serem copiados pra GPU
			GL_STATIC_DRAW		// Política de acesso aos dados, para otimização
		);

	glVertexAttribPointer(
				0,			// Lembra do (layout = 0 ) no vertex shader ? Esse valor indica qual atributo estamos indicando
				3,			// cada vertice é composto de 3 valores
				GL_FLOAT,	// cada valor do vértice é do tipo GLfloat
				GL_FALSE,	// Quer normalizar os dados e converter tudo pra NDC ? ( no nosso caso, já esta tudo correto, então deixamos como FALSE)
				0 ,// De quantos em quantos bytes, este atributo é encontrado no buffer ? No nosso caso 3 floats pros vertices + 3 floats pra cor = 6 floats
				(void*) 0	// Onde está o primeiro valor deste atributo no buffer. Nesse caso, está no início do buffer
			);
		// Habilita este atributo
	glEnableVertexAttribArray(0);


}

void display(GLFWwindow* window, double currentTime) {
    glUseProgram(renderingProgram);
    
    // clear the background to black, each time
    glClear(GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    x += inc;
    		    // switch to moving the triangle to the left
    		if (x > 0.7f) {
    			inc = -0.02f;

    		}
    		    // switch to moving the triangle to the right
    		if (x < -0.7f) {
    			inc = 0.02f;

    		}

    posi += incpos;
    rad *= incrad;
    radant = rad;

    		if (posi - rad*radius > 1.1f) {
        			posi = -1.1;
        			rad = 1;
        	}




    GLuint rotateLoc = glGetUniformLocation(renderingProgram, "rotate");
    glProgramUniform1f(renderingProgram, rotateLoc, x);

    GLuint tiempo = glGetUniformLocation(renderingProgram, "time");
    glProgramUniform1f(renderingProgram, tiempo, currentTime);

    GLuint posicion = glGetUniformLocation(renderingProgram, "posx");
    glProgramUniform1f(renderingProgram, posicion, posi);

    GLuint radio = glGetUniformLocation(renderingProgram, "rad");
    glProgramUniform1f(renderingProgram, radio, rad);

    GLuint radioant = glGetUniformLocation(renderingProgram, "radant");
    glProgramUniform1f(renderingProgram, radioant, radant);

    // Use este VAO e suas configurações
    glBindVertexArray(m_VAO);

    //Draw Triangles using Instances
	glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, 50, 30);

	//glDrawArraysInstanced(GL_LINE_STRIP, 0, 50, 6);
}

int main(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            //
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); 	// Resizable option.

    GLFWwindow* window = glfwCreateWindow(800, 800, "Lab06.0.4.2: Display Multiply object only with object", NULL, NULL);
    glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}
    glfwSwapInterval(1);
    
    init(window);
    
    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
