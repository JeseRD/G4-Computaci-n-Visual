//============================================================================
// Name        : Diseño de una figura
// Professor   : Herminio Paucar
// Version     :
// Description : Utilizamos los Vertex y Fragment Shaders
//============================================================================

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>


#include "Utils.h"

// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

GLFWwindow* window;

using namespace glm;

GLuint m_VAO;
GLuint m_VAOcirculos;
GLuint m_VAORaton;
GLuint m_VBO;
GLuint m_VBOjoI;
GLuint m_VBOjoD;
GLuint m_VBOboca;
GLuint m_VBOC1;
GLuint m_VBOC2;
GLuint m_VBOC3;
GLuint m_VBORatCab;
GLuint m_VBORatCuer;
GLuint m_VBORatOrIz;
GLuint m_VBORatOrDer;
GLuint m_VBORatCola;

GLuint m_CBO;
GLuint m_CBOjo;
GLuint m_CBOboca;
GLuint m_CBOC1;
GLuint m_CBOC2;
GLuint m_CBOC3;
GLuint m_CBORatCab;
GLuint m_CBORatCuer;
GLuint m_CBORatOre;
GLuint m_CBORatCola;


// GLSL program from the shaders
GLuint programID;


GLint WindowWidth = 600;
GLint WindowHeight = 600;

#define pi 3.14159265359
	GLint dimVertices;
	GLint dimColor;
	GLfloat x=0.0;
	GLfloat y=0.0;
	GLfloat z=0.0;
	GLfloat radius=20.0;
	GLint numberOfVertices = 52;

	GLfloat twicePi = 2.0f * M_PI;
//--------------------------------------------------------------------------------



void transferDataToGPUMemory(void){
    // VAO
	GLfloat verticesX[numberOfVertices];
	GLfloat verticesY[numberOfVertices];
	GLfloat verticesZ[numberOfVertices];
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);


    verticesX[0] = x;
	verticesY[0] = y;
	verticesZ[0] = z;

    // Create and compile our GLSL program from the shaders
    programID = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");

    //CARA

    for (int i = 1; i < numberOfVertices; i++) {
    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
    			verticesZ[i] = z;

    		}

    				verticesX[numberOfVertices-1] = verticesX[1];
        			verticesY[numberOfVertices-1] = verticesY[1];
        			verticesZ[numberOfVertices-1] = z;


    dimVertices = (numberOfVertices) * 3;
    	GLfloat m_VerticesCara[dimVertices];

    	for (int i = 0; i < numberOfVertices; i++) {
    		m_VerticesCara[i * 3] = verticesX[i];
    		m_VerticesCara[i * 3 + 1] = verticesY[i];
    		m_VerticesCara[i * 3 + 2] = verticesZ[i];

    	}

   // OJOS
    	//OJO IZQUIERDO
    	x=-5.0;
    	y=5.0;
    	z=0.0;
    	radius=2.0;
    	verticesX[0] = x;
    		verticesY[0] = y;
    		verticesZ[0] = z;
    	for (int i = 1; i < numberOfVertices; i++) {
    	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
    	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
    	    			verticesZ[i] = z;

    	    		}

    							verticesX[numberOfVertices-1] = verticesX[1];
    	    	    			verticesY[numberOfVertices-1] = verticesY[1];
    	    	    			verticesZ[numberOfVertices-1] = z;

    	    	GLfloat m_VerticesOjosI[dimVertices];

    	    	for (int i = 0; i < numberOfVertices; i++) {
    	    		m_VerticesOjosI[i * 3] = verticesX[i];
    	    		m_VerticesOjosI[i * 3 + 1] = verticesY[i];
    	    		m_VerticesOjosI[i * 3 + 2] = verticesZ[i];

    	    	}
    	 //OJO DERECHO

    	    			x=5.0;
    	    	    	y=5.0;
    	    	    	z=0.0;
    	    	    	radius=2.0;
    	    	    	verticesX[0] = x;
    	    	    	verticesY[0] = y;
    	    	    	verticesZ[0] = z;
    	    	    	for (int i = 1; i < numberOfVertices; i++) {
    	    	    	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
    	    	    	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
    	    	    	    			verticesZ[i] = z;

    	    	    	    		}

    	    	    							verticesX[numberOfVertices-1] = verticesX[1];
    	    	    	    	    			verticesY[numberOfVertices-1] = verticesY[1];
    	    	    	    	    			verticesZ[numberOfVertices-1] = z;

    	    	    	    	GLfloat m_VerticesOjosD[dimVertices];

    	    	    	    	for (int i = 0; i < numberOfVertices; i++) {
    	    	    	    		m_VerticesOjosD[i * 3] = verticesX[i];
    	    	    	    		m_VerticesOjosD[i * 3 + 1] = verticesY[i];
    	    	    	    		m_VerticesOjosD[i * 3 + 2] = verticesZ[i];

    	    	    	    	}



    	 //BOCA

    	    	    	    	x=0.0;
    	    	    	    	y=0.0;
    	    	    	    	z=0.0;
    	    	    	    	radius=10.0;
    	    	    	    	verticesX[0] = x;
    	    	    	    	verticesY[0] = y;
    	    	    	    	verticesZ[0] = z;
    	    	    	    	    	    	    	for (int i = 1; i < numberOfVertices; i++) {
    	    	    	    	    	    	    	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
    	    	    	    	    	    	    	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
    	    	    	    	    	    	    	    			verticesZ[i] = z;

    	    	    	    	    	    	    	    		}

    	    	    	    	    	    	    							verticesX[numberOfVertices-1] = verticesX[1];
    	    	    	    	    	    	    	    	    			verticesY[numberOfVertices-1] = verticesY[1];
    	    	    	    	    	    	    	    	    			verticesZ[numberOfVertices-1] = z;

    	    	    	    	    	    	    	    	GLfloat m_VerticesBoca[dimVertices];

    	    	    	    	    	    	    	    	for (int i = 0; i < numberOfVertices; i++) {
    	    	    	    	    	    	    	    		m_VerticesBoca[i * 3] = verticesX[i];
    	    	    	    	    	    	    	    		m_VerticesBoca[i * 3 + 1] = verticesY[i];
    	    	    	    	    	    	    	    		m_VerticesBoca[i * 3 + 2] = verticesZ[i];

    	    	    	    	    	    	    	    	}


    	int dimColorCara=(numberOfVertices)*3;
    	GLfloat m_ColorCara[dimColorCara];

    	for (int i = 0; i < numberOfVertices; i++) {
    	    			m_ColorCara[i*3] = 1.0;
    	    			m_ColorCara[i*3 + 1] = 1.0;
    	    			m_ColorCara[i*3 + 2] = 0.0;

    	    		}

    	int dimColorOjos=(numberOfVertices)*3;
    	    	GLfloat m_ColorOjos[dimColorOjos];

    	    	for (int i = 0; i < numberOfVertices; i++) {
    	    	    			m_ColorOjos[i*3] = 0.0;
    	    	    			m_ColorOjos[i*3 + 1] = 0.0;
    	    	    			m_ColorOjos[i*3 + 2] = 0.0;

    	    	    		}


    	    	int dimColorBoca=(numberOfVertices)*3;
    	    	   	  GLfloat m_ColorBoca[dimColorBoca];

    	    	    	    	for (int i = 0; i < numberOfVertices/2; i++) {
    	    	    	    	    			m_ColorBoca[i*3] = 1.0;
    	    	    	    	    			m_ColorBoca[i*3 + 1] = 1.0;
    	    	    	    	    			m_ColorBoca[i*3 + 2] = 0.0;

    	    	    	    	    		}
    	    	    	    	for (int i = numberOfVertices/2; i < numberOfVertices; i++) {
    	    	    	    	    	    	m_ColorBoca[i*3] = 0.0;
    	    	    	    	    	    	m_ColorBoca[i*3 + 1] = 0.0;
    	    	    	    	    	    	m_ColorBoca[i*3 + 2] = 0.0;

    	    	    	    	    	    	    	    	    		}

    // Move vertex data to video memory; specifically to VBO called m_VBO
    	//cara
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(m_VerticesCara),
		m_VerticesCara,
        GL_STATIC_DRAW);
    	//VERTICES OJO IZQUIERDO
    glGenBuffers(1, &m_VBOjoI);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBOjoI);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_VerticesOjosI),
			m_VerticesOjosI,
            GL_STATIC_DRAW);

        //VERTICES OJO DERECHO

        glGenBuffers(1, &m_VBOjoD);
                glBindBuffer(GL_ARRAY_BUFFER, m_VBOjoD);
                glBufferData(
                    GL_ARRAY_BUFFER,
                    sizeof(m_VerticesOjosD),
        			m_VerticesOjosD,
                    GL_STATIC_DRAW);

         // VERTICES BOCA

        glGenBuffers(1, &m_VBOboca);
                  glBindBuffer(GL_ARRAY_BUFFER, m_VBOboca);
                  glBufferData(
                     GL_ARRAY_BUFFER,
                     sizeof(m_VerticesBoca),
					 m_VerticesBoca,
                     GL_STATIC_DRAW);



    // Move color data to video memory; specifically to CBO called m_CBO

        glGenBuffers(1, &m_CBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_CBO);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_ColorCara),
			m_ColorCara,
            GL_STATIC_DRAW);


        //COLOR OJO IZQUIERDO
        glGenBuffers(1, &m_CBOjo);
                glBindBuffer(GL_ARRAY_BUFFER, m_CBOjo);
                glBufferData(
                    GL_ARRAY_BUFFER,
                    sizeof(m_ColorOjos),
					m_ColorOjos,
                    GL_STATIC_DRAW);

        //COLOR OJO BOCA

         glGenBuffers(1, &m_CBOboca);
                glBindBuffer(GL_ARRAY_BUFFER, m_CBOboca);
                glBufferData(
                     GL_ARRAY_BUFFER,
                     sizeof(m_ColorBoca),
					 m_ColorBoca,
                     GL_STATIC_DRAW);

///////////////////////////////////////////////////////////////////////////////////////////////////////

          //3 CIRCULOS


                glGenVertexArrays(1, &m_VAOcirculos);
                glBindVertexArray(m_VAOcirculos);
                //CIRCULO 1
                x=-5.0;
                y=5.0;
                z=0.0;
                radius=5.0;
                verticesX[0] = x;
                verticesY[0] = y;
                verticesZ[0] = z;
                   	for (int i = 1; i < numberOfVertices; i++) {
                   	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
                   	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
                   	    			verticesZ[i] = z;
                    	    		}

           							verticesX[numberOfVertices-1] = verticesX[1];
           	    	    			verticesY[numberOfVertices-1] = verticesY[1];
           	    	    			verticesZ[numberOfVertices-1] = z;

                    	    	GLfloat m_Verticescirculo1[dimVertices];

                    	    	for (int i = 0; i < numberOfVertices; i++) {
                    	    		m_Verticescirculo1[i * 3] = verticesX[i];
                    	    		m_Verticescirculo1[i * 3 + 1] = verticesY[i];
                    	    		m_Verticescirculo1[i * 3 + 2] = verticesZ[i];
                    	    	}

                    	    		//CIRCULO 2
                    	    		                x=5.0;
                    	    		                y=5.0;
                    	    		                z=0.0;
                    	    		                radius=5.0;
                    	    		                verticesX[0] = x;
                    	    		                verticesY[0] = y;
                    	    		                verticesZ[0] = z;
                    	    		                   	for (int i = 1; i < numberOfVertices; i++) {
                    	    		                   	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
                    	    		                   	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
                    	    		                   	    			verticesZ[i] = z;
                    	    		                    	    		}

                    	    		           							verticesX[numberOfVertices-1] = verticesX[1];
                    	    		           	    	    			verticesY[numberOfVertices-1] = verticesY[1];
                    	    		           	    	    			verticesZ[numberOfVertices-1] = z;

                    	    		                    	    	GLfloat m_Verticescirculo2[dimVertices];

                    	    		                    	    	for (int i = 0; i < numberOfVertices; i++) {
                    	    		                    	    		m_Verticescirculo2[i * 3] = verticesX[i];
                    	    		                    	    		m_Verticescirculo2[i * 3 + 1] = verticesY[i];
                    	    		                    	    		m_Verticescirculo2[i * 3 + 2] = verticesZ[i];
                    	    		                    	    	}

                    	    		                    	    		//CIRCULO 3
                    	    		                    	    		                x=0.0;
                    	    		                    	    		                y=-3.7;
                    	    		                    	    		                z=0.0;
                    	    		                    	    		                radius=5.0;
                    	    		                    	    		                verticesX[0] = x;
                    	    		                    	    		                verticesY[0] = y;
                    	    		                    	    		                verticesZ[0] = z;
                    	    		                    	    		                   	for (int i = 1; i < numberOfVertices; i++) {
                    	    		                    	    		                   	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
                    	    		                    	    		                   	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
                    	    		                    	    		                   	    			verticesZ[i] = z;
                    	    		                    	    		                    	    		}

                    	    		                    	    		           							verticesX[numberOfVertices-1] = verticesX[1];
                    	    		                    	    		           	    	    			verticesY[numberOfVertices-1] = verticesY[1];
                    	    		                    	    		           	    	    			verticesZ[numberOfVertices-1] = z;

                    	    		                    	    		                    	    	GLfloat m_Verticescirculo3[dimVertices];

                    	    		                    	    		                    	    	for (int i = 0; i < numberOfVertices; i++) {
                    	    		                    	    		                    	    		m_Verticescirculo3[i * 3] = verticesX[i];
                    	    		                    	    		                    	    		m_Verticescirculo3[i * 3 + 1] = verticesY[i];
                    	    		                    	    		                    	    		m_Verticescirculo3[i * 3 + 2] = verticesZ[i];
                    	    		                    	    		                    	    	}

					int dimColorC1=(numberOfVertices)*3;
    	    	   	GLfloat m_ColorC1[dimColorC1];

    	    	    	    	for (int i = 0; i < numberOfVertices; i++) {
    	    	    	    	    	m_ColorC1[i*3] = 1.0;
    	    	    	    	    	m_ColorC1[i*3 + 1] = 0.0;
    	    	    	    	    	m_ColorC1[i*3 + 2] = 0.0;
    	    	    	    	 }




					int dimColorC2=(numberOfVertices)*3;
                    GLfloat m_ColorC2[dimColorC2];

                    		   	for (int i = 0; i < numberOfVertices; i++) {
                    		   		m_ColorC2[i*3] = 0.0;
                    		   		m_ColorC2[i*3 + 1] = 1.0;
                    		   		m_ColorC2[i*3 + 2] = 0.0;
          	  	  	  	  	  	 }

					int dimColorC3=(numberOfVertices)*3;
                    GLfloat m_ColorC3[dimColorC3];

                    		   	for (int i = 0; i < numberOfVertices; i++) {
                    		   		m_ColorC3[i*3] = 0.0;
                    		   		m_ColorC3[i*3 + 1] = 0.0;
                    		   		m_ColorC3[i*3 + 2] = 1.0;
                    		   	}




        glGenBuffers(1, &m_VBOC1);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBOC1);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_Verticescirculo1),
			m_Verticescirculo1,
            GL_STATIC_DRAW);


        glGenBuffers(1, &m_VBOC2);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBOC2);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_Verticescirculo2),
        	m_Verticescirculo2,
            GL_STATIC_DRAW);


        glGenBuffers(1, &m_VBOC3);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBOC3);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_Verticescirculo3),
          	m_Verticescirculo3,
            GL_STATIC_DRAW);



        //COLOR CIRCULOS

        glGenBuffers(1, &m_CBOC1);
        glBindBuffer(GL_ARRAY_BUFFER, m_CBOC1);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_ColorC1),
			m_ColorC1,
            GL_STATIC_DRAW);


        glGenBuffers(1, &m_CBOC2);
        glBindBuffer(GL_ARRAY_BUFFER, m_CBOC2);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_ColorC2),
			m_ColorC2,
            GL_STATIC_DRAW);


        glGenBuffers(1, &m_CBOC3);
        glBindBuffer(GL_ARRAY_BUFFER, m_CBOC3);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_ColorC3),
			m_ColorC3,
            GL_STATIC_DRAW);



        //RATON

        glGenVertexArrays(1, &m_VAORaton);
        glBindVertexArray(m_VAORaton);
        //CABEZA


        				x=0.0;
                        y=15.0;
                        z=0.0;
                        radius=10.0;
                        verticesX[0] = x;
                        verticesY[0] = y;
                        verticesZ[0] = z;
                           	for (int i = 1; i < numberOfVertices; i++) {
                           	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
                           	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
                           	    			verticesZ[i] = z;
                            	    		}

                   							verticesX[numberOfVertices-1] = verticesX[1];
                   	    	    			verticesY[numberOfVertices-1] = verticesY[1];
                   	    	    			verticesZ[numberOfVertices-1] = z;

                            	    	GLfloat m_VerticesRatonCab[dimVertices];

                            	    	for (int i = 0; i < numberOfVertices; i++) {
                            	    		m_VerticesRatonCab[i * 3] = verticesX[i];
                            	    		m_VerticesRatonCab[i * 3 + 1] = verticesY[i];
                            	    		m_VerticesRatonCab[i * 3 + 2] = verticesZ[i];
                            	    	}


          //CUERPO

                        x=0.0;
                        y=-8.0;
                        z=0.0;
                        radius=15.0;
                        verticesX[0] = x;
                        verticesY[0] = y;
                        verticesZ[0] = z;
                           	for (int i = 1; i < numberOfVertices; i++) {
                           	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
                           	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
                           	    			verticesZ[i] = z;
                            	    		}

                   							verticesX[numberOfVertices-1] = verticesX[1];
                   	    	    			verticesY[numberOfVertices-1] = verticesY[1];
                   	    	    			verticesZ[numberOfVertices-1] = z;

                            	    	GLfloat m_VerticesRatonCue[dimVertices];

                            	    	for (int i = 0; i < numberOfVertices; i++) {
                            	    		m_VerticesRatonCue[i * 3] = verticesX[i];
                            	    		m_VerticesRatonCue[i * 3 + 1] = verticesY[i];
                            	    		m_VerticesRatonCue[i * 3 + 2] = verticesZ[i];
                            	    	}



           //OREJA IZQ

                        x=-8.0;
                        y=25.0;
                        z=0.0;
                        radius=4.0;
                        verticesX[0] = x;
                        verticesY[0] = y;
                        verticesZ[0] = z;
                           	for (int i = 1; i < numberOfVertices; i++) {
                           	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
                           	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
                           	    			verticesZ[i] = z;
                            	    		}

                   							verticesX[numberOfVertices-1] = verticesX[1];
                   	    	    			verticesY[numberOfVertices-1] = verticesY[1];
                   	    	    			verticesZ[numberOfVertices-1] = z;

                            	    	GLfloat m_VerticesRatonOrIz[dimVertices];

                            	    	for (int i = 0; i < numberOfVertices; i++) {
                            	    		m_VerticesRatonOrIz[i * 3] = verticesX[i];
                            	    		m_VerticesRatonOrIz[i * 3 + 1] = verticesY[i];
                            	    		m_VerticesRatonOrIz[i * 3 + 2] = verticesZ[i];
                            	    	}

           // OREJA DER

                        x=8.0;
                        y=25.0;
                        z=0.0;
                        radius=4.0;
                        verticesX[0] = x;
                        verticesY[0] = y;
                        verticesZ[0] = z;
                           	for (int i = 1; i < numberOfVertices; i++) {
                           	    			verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
                           	    			verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
                           	    			verticesZ[i] = z;
                            	    		}

                   							verticesX[numberOfVertices-1] = verticesX[1];
                   	    	    			verticesY[numberOfVertices-1] = verticesY[1];
                   	    	    			verticesZ[numberOfVertices-1] = z;

                            	    	GLfloat m_VerticesRatonOrDr[dimVertices];

                            	    	for (int i = 0; i < numberOfVertices; i++) {
                            	    		m_VerticesRatonOrDr[i * 3] = verticesX[i];
                            	    		m_VerticesRatonOrDr[i * 3 + 1] = verticesY[i];
                            	    		m_VerticesRatonOrDr[i * 3 + 2] = verticesZ[i];
                            	    	}

            // COLA

                            	x=25.0;
    	    	    	    	y=0.0;
    	    	    	    	z=0.0;
    	    	    	    	radius=15.0;
    	    	    	    	verticesX[0] = x;
    	    	    	    	verticesY[0] = y;
    	    	    	    	verticesZ[0] = z;
    	    	    	    	    	    	    	for (int i = 1; i < numberOfVertices; i++) {
    	    	    	    	    	    	    	    	verticesX[i] = x + (radius * cos(i * twicePi / numberOfVertices));
    	    	    	    	    	    	    	    	verticesY[i] = y + (radius * sin(i * twicePi / numberOfVertices));
    	    	    	    	    	    	    	    	verticesZ[i] = z;

    	    	    	    	    	    	    	  }

    	    	    	    	    	    	    			verticesX[numberOfVertices-1] = verticesX[1];
    	    	    	    	    	    	    	    	verticesY[numberOfVertices-1] = verticesY[1];
    	    	    	    	    	    	    	    	verticesZ[numberOfVertices-1] = z;

    	    	    	    	    	    	    	    	GLfloat m_VerticesRatonCola[dimVertices];

    	    	    	    	    	    	    	    	for (int i = 0; i < numberOfVertices; i++) {
    	    	    	    	    	    	    	    		m_VerticesRatonCola[i * 3] = verticesX[i];
    	    	    	    	    	    	    	    		m_VerticesRatonCola[i * 3 + 1] = verticesY[i];
    	    	    	    	    	    	    	    		m_VerticesRatonCola[i * 3 + 2] = verticesZ[i];

    	    	    	    	    	    	    	    	}



    	    	   // CUERPO
					int dimColorRatCuer=(numberOfVertices)*3;
    	    	   	GLfloat m_ColorRatCuer[dimColorRatCuer];

    	    	    	    	for (int i = 0; i < numberOfVertices; i++) {
    	    	    	    		m_ColorRatCuer[i*3] = 1.0;
    	    	    	    		m_ColorRatCuer[i*3 + 1] = 0.0;
    	    	    	    		m_ColorRatCuer[i*3 + 2] = 0.0;
    	    	    	    	 }

					// COLA
					int dimColorRatCola=(numberOfVertices)*3;
    	    	   	GLfloat m_ColorRatCola[dimColorRatCola];

    	    	    	    	for (int i = 0; i < numberOfVertices; i++) {
    	    	    	    		m_ColorRatCola[i*3] = 0.0;
    	    	    	    		m_ColorRatCola[i*3 + 1] = 0.0;
    	    	    	    		m_ColorRatCola[i*3 + 2] = 0.0;
    	    	    	    	 }
    	    	    	    	for(int i=0; i<30;i++){
    	    	    	    		m_ColorRatCola[i*3] = 1.0;
    	    	    	    		m_ColorRatCola[i*3 + 1] = 1.0;
    	    	    	    		m_ColorRatCola[i*3 + 2] = 1.0;
    	    	    	    	}


    	glGenBuffers(1, &m_VBORatCab);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBORatCab);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_VerticesRatonCab),
			m_VerticesRatonCab,
            GL_STATIC_DRAW);


        glGenBuffers(1, &m_VBORatCuer);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBORatCuer);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_VerticesRatonCue),
			m_VerticesRatonCue,
            GL_STATIC_DRAW);


        glGenBuffers(1, &m_VBORatOrIz);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBORatOrIz);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_VerticesRatonOrIz),
			m_VerticesRatonOrIz,
            GL_STATIC_DRAW);

        glGenBuffers(1, &m_VBORatOrDer);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBORatOrDer);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_VerticesRatonOrDr),
			m_VerticesRatonOrDr,
            GL_STATIC_DRAW);


        glGenBuffers(1, &m_VBORatCola);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBORatCola);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_VerticesRatonCola),
			m_VerticesRatonCola,
            GL_STATIC_DRAW);


        //Colores


        glGenBuffers(1, &m_CBORatCuer);
        glBindBuffer(GL_ARRAY_BUFFER, m_CBORatCuer);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_ColorRatCuer),
			m_ColorRatCuer,
            GL_STATIC_DRAW);


        glGenBuffers(1, &m_CBORatCola);
        glBindBuffer(GL_ARRAY_BUFFER, m_CBORatCola);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(m_ColorRatCola),
			m_ColorRatCola,
            GL_STATIC_DRAW);
}
//--------------------------------------------------------------------------------
void cleanupDataFromGPU(){
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_CBO);
    glDeleteBuffers(1, &m_VBOjoI);
    glDeleteBuffers(1, &m_VBOjoD);
    glDeleteBuffers(1, &m_VBOC1);
    glDeleteBuffers(1, &m_VBOC2);
    glDeleteBuffers(1, &m_VBOC3);
    glDeleteBuffers(1, &m_VBORatCab);
    glDeleteBuffers(1, &m_VBORatCuer);
    glDeleteBuffers(1, &m_VBORatOrIz);
    glDeleteBuffers(1, &m_VBORatOrDer);
    glDeleteBuffers(1, &m_VBORatCola);
    glDeleteBuffers(1, &m_CBOjo);
    glDeleteBuffers(1, &m_CBOboca);
    glDeleteBuffers(1, &m_CBOC1);
    glDeleteBuffers(1, &m_CBOC2);
    glDeleteBuffers(1, &m_CBOC3);
    glDeleteBuffers(1, &m_CBORatCuer);
    glDeleteBuffers(1, &m_CBORatCola);
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteVertexArrays(1, &m_VAOcirculos);
    glDeleteVertexArrays(1, &m_VAORaton);
    glDeleteProgram(programID);
}

//--------------------------------------------------------------------------------
void drawSmile (void){
    // Use our shader
    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    GLuint matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glVertexAttribPointer(
                          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );



    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_CBO);
    glVertexAttribPointer(
                          1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                          3,                                // size
                          GL_FLOAT,                         // type
                          GL_FALSE,                         // normalized?
                          0,                                // stride
                          (void*)0                          // array buffer offset
                          );



    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLE_FAN, 0, 52); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_POINTS, 0, 9); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    //ojos

    //OJO IZQUIERDO
    glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, m_VBOjoI);
            glVertexAttribPointer(
                                  0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                  3,                  // size
                                  GL_FLOAT,           // type
                                  GL_FALSE,           // normalized?
                                  0,                  // stride
                                  (void*)0            // array buffer offset
                                  );

            glEnableVertexAttribArray(1);
                   glBindBuffer(GL_ARRAY_BUFFER, m_CBOjo);
                   glVertexAttribPointer(
                                         1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                         3,                                // size
                                         GL_FLOAT,                         // type
                                         GL_FALSE,                         // normalized?
                                         0,                                // stride
                                         (void*)0                          // array buffer offset
                                         );

                   glDrawArrays(GL_TRIANGLE_FAN, 0, 52);


                   glDisableVertexAttribArray(0);
                   glDisableVertexAttribArray(1);

        //OJO DERECHO

                   glEnableVertexAttribArray(0);
                               glBindBuffer(GL_ARRAY_BUFFER, m_VBOjoD);
                               glVertexAttribPointer(
                                                     0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                                     3,                  // size
                                                     GL_FLOAT,           // type
                                                     GL_FALSE,           // normalized?
                                                     0,                  // stride
                                                     (void*)0            // array buffer offset
                                                     );

                               glEnableVertexAttribArray(1);
                                      glBindBuffer(GL_ARRAY_BUFFER, m_CBOjo);
                                      glVertexAttribPointer(
                                                            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                                            3,                                // size
                                                            GL_FLOAT,                         // type
                                                            GL_FALSE,                         // normalized?
                                                            0,                                // stride
                                                            (void*)0                          // array buffer offset
                                                            );

                                      glDrawArrays(GL_TRIANGLE_FAN, 0, 52);


                                      glDisableVertexAttribArray(0);
                                      glDisableVertexAttribArray(1);


        //BOCA

                                      glEnableVertexAttribArray(0);
                                                  glBindBuffer(GL_ARRAY_BUFFER, m_VBOboca);
                                                  glVertexAttribPointer(
                                                            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                                            3,                  // size
                                                            GL_FLOAT,           // type
                                                            GL_FALSE,           // normalized?
                                                            0,                  // stride
                                                            (void*)0            // array buffer offset
                                                            );

                                      glEnableVertexAttribArray(1);
                                      glBindBuffer(GL_ARRAY_BUFFER, m_CBOboca);
                                      glVertexAttribPointer(
                                                            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                                            3,                                // size
                                                            GL_FLOAT,                         // type
                                                            GL_FALSE,                         // normalized?
                                                            0,                                // stride
                                                            (void*)0                          // array buffer offset
                                                            );

                                      glDrawArrays(GL_LINE_STRIP, 0, 52);


                                      glDisableVertexAttribArray(0);
                                      glDisableVertexAttribArray(1);

}
//--------------------------------------------------------------------------------


void draw3Circulos (void){
    // Use our shader
    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    GLuint matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBOC1);
    glVertexAttribPointer(
                          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );



    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_CBOC1);
    glVertexAttribPointer(
                          1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                          3,                                // size
                          GL_FLOAT,                         // type
                          GL_FALSE,                         // normalized?
                          0,                                // stride
                          (void*)0                          // array buffer offset
                          );



    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLE_FAN, 0, 52); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_POINTS, 0, 9); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    //ojos

    //C2
    glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, m_VBOC2);
            glVertexAttribPointer(
                                  0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                  3,                  // size
                                  GL_FLOAT,           // type
                                  GL_FALSE,           // normalized?
                                  0,                  // stride
                                  (void*)0            // array buffer offset
                                  );

            glEnableVertexAttribArray(1);
                   glBindBuffer(GL_ARRAY_BUFFER, m_CBOC2);
                   glVertexAttribPointer(
                                         1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                         3,                                // size
                                         GL_FLOAT,                         // type
                                         GL_FALSE,                         // normalized?
                                         0,                                // stride
                                         (void*)0                          // array buffer offset
                                         );

                   glDrawArrays(GL_TRIANGLE_FAN, 0, 52);


                   glDisableVertexAttribArray(0);
                   glDisableVertexAttribArray(1);

        // C3

                   glEnableVertexAttribArray(0);
                               glBindBuffer(GL_ARRAY_BUFFER, m_VBOC3);
                               glVertexAttribPointer(
                                                     0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                                     3,                  // size
                                                     GL_FLOAT,           // type
                                                     GL_FALSE,           // normalized?
                                                     0,                  // stride
                                                     (void*)0            // array buffer offset
                                                     );

                               glEnableVertexAttribArray(1);
                                      glBindBuffer(GL_ARRAY_BUFFER, m_CBOC3);
                                      glVertexAttribPointer(
                                                            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                                            3,                                // size
                                                            GL_FLOAT,                         // type
                                                            GL_FALSE,                         // normalized?
                                                            0,                                // stride
                                                            (void*)0                          // array buffer offset
                                                            );

                                      glDrawArrays(GL_TRIANGLE_FAN, 0, 52);


                                      glDisableVertexAttribArray(0);
                                      glDisableVertexAttribArray(1);

}


void drawRaton (void){
    // Use our shader
    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    GLuint matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


// COLA

                                      glEnableVertexAttribArray(0);
                               glBindBuffer(GL_ARRAY_BUFFER, m_VBORatCola);
                               glVertexAttribPointer(
                                                     0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                                     3,                  // size
                                                     GL_FLOAT,           // type
                                                     GL_FALSE,           // normalized?
                                                     0,                  // stride
                                                     (void*)0            // array buffer offset
                                                     );

                               glEnableVertexAttribArray(1);
                                      glBindBuffer(GL_ARRAY_BUFFER, m_CBORatCola);
                                      glVertexAttribPointer(
                                                            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                                            3,                                // size
                                                            GL_FLOAT,                         // type
                                                            GL_FALSE,                         // normalized?
                                                            0,                                // stride
                                                            (void*)0                          // array buffer offset
                                                            );

                                      glDrawArrays(GL_LINE_STRIP, 0, 52);


                                      glDisableVertexAttribArray(0);
                                      glDisableVertexAttribArray(1);



    //CABEZA

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBORatCab);
    glVertexAttribPointer(
                          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );



    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_CBORatCuer);
    glVertexAttribPointer(
                          1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                          3,                                // size
                          GL_FLOAT,                         // type
                          GL_FALSE,                         // normalized?
                          0,                                // stride
                          (void*)0                          // array buffer offset
                          );



    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLE_FAN, 0, 52); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_POINTS, 0, 9); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    //ojos

    //CUERPO
    glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, m_VBORatCuer);
            glVertexAttribPointer(
                                  0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                  3,                  // size
                                  GL_FLOAT,           // type
                                  GL_FALSE,           // normalized?
                                  0,                  // stride
                                  (void*)0            // array buffer offset
                                  );

            glEnableVertexAttribArray(1);
                   glBindBuffer(GL_ARRAY_BUFFER, m_CBORatCuer);
                   glVertexAttribPointer(
                                         1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                         3,                                // size
                                         GL_FLOAT,                         // type
                                         GL_FALSE,                         // normalized?
                                         0,                                // stride
                                         (void*)0                          // array buffer offset
                                         );

                   glDrawArrays(GL_TRIANGLE_FAN, 0, 52);


                   glDisableVertexAttribArray(0);
                   glDisableVertexAttribArray(1);

        // OREJA IZQ

                   glEnableVertexAttribArray(0);
                               glBindBuffer(GL_ARRAY_BUFFER, m_VBORatOrIz);
                               glVertexAttribPointer(
                                                     0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                                     3,                  // size
                                                     GL_FLOAT,           // type
                                                     GL_FALSE,           // normalized?
                                                     0,                  // stride
                                                     (void*)0            // array buffer offset
                                                     );

                               glEnableVertexAttribArray(1);
                                      glBindBuffer(GL_ARRAY_BUFFER, m_CBORatCuer);
                                      glVertexAttribPointer(
                                                            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                                            3,                                // size
                                                            GL_FLOAT,                         // type
                                                            GL_FALSE,                         // normalized?
                                                            0,                                // stride
                                                            (void*)0                          // array buffer offset
                                                            );

                                      glDrawArrays(GL_TRIANGLE_FAN, 0, 52);


                                      glDisableVertexAttribArray(0);
                                      glDisableVertexAttribArray(1);

         // OREJA DER

                               glEnableVertexAttribArray(0);
                               glBindBuffer(GL_ARRAY_BUFFER, m_VBORatOrDer);
                               glVertexAttribPointer(
                                                     0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                                     3,                  // size
                                                     GL_FLOAT,           // type
                                                     GL_FALSE,           // normalized?
                                                     0,                  // stride
                                                     (void*)0            // array buffer offset
                                                     );

                               glEnableVertexAttribArray(1);
                                      glBindBuffer(GL_ARRAY_BUFFER, m_CBORatCuer);
                                      glVertexAttribPointer(
                                                            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                                            3,                                // size
                                                            GL_FLOAT,                         // type
                                                            GL_FALSE,                         // normalized?
                                                            0,                                // stride
                                                            (void*)0                          // array buffer offset
                                                            );

                                      glDrawArrays(GL_TRIANGLE_FAN, 0, 52);


                                      glDisableVertexAttribArray(0);
                                      glDisableVertexAttribArray(1);




}

int main( void )
{
    // Initialise GLFW
    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window
    window = glfwCreateWindow( 600, 600, "House in 4 Viewports", NULL, NULL);

    // Create window context
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    glewInit();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // transfer my data (vertices, colors, and shaders) to GPU side
    transferDataToGPUMemory();

    GLuint FramebufferName = 0;
    glGenFramebuffers(1, &FramebufferName);
    //glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

    // render scene for each frame
    do{
        // White background
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

        // Clear the screen
        glClear( GL_COLOR_BUFFER_BIT );

        //IZQUIERDA INFERIOR
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //glViewport(0, 0, WindowWidth*0.5, WindowHeight*0.5);
        //draw();

        //DERECHA INFERIOR
        glViewport(WindowWidth*0.5, 0, WindowWidth*0.5, WindowHeight*0.5);
        draw3Circulos();

        //IZQUIERDA SUPERIOR
        glViewport(0, WindowHeight*0.5, WindowWidth*0.5, WindowHeight*0.5);
        drawRaton();

        //DERECHA SUPERIOR
        glViewport(WindowWidth*0.5, WindowHeight*0.5, WindowWidth*0.5, WindowHeight*0.5);
        drawSmile();

        // Swap buffers
        glfwSwapBuffers(window);
        // looking for events
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0 );

    // delete framebuffer
    glDeleteFramebuffers(1, &FramebufferName);

    // Cleanup VAO, VBOs, and shaders from GPU
    cleanupDataFromGPU();

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

