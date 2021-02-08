#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include <glm/glm.hpp>

#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Utils.h"


#include<Windows.h>
#include<gl/GLU.h>
#include<vector>
#include<cmath>
GLuint renderingProgram;


void detectCharucoBoardWithCalibrationPose();
//void detectCharucoBoardWithoutCalibration();
static bool readCameraParameters(std::string filename, cv::Mat& camMatrix, cv::Mat& distCoeffs)
{
    cv::FileStorage fs(filename, cv::FileStorage::READ);
    if (!fs.isOpened())
        return false;
    fs["Camera_Matrix"] >> camMatrix;
    fs["Distortion_Coefficients"] >> distCoeffs;
    return true;
}
/*void createBoard()
{
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::Ptr<cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(5, 7, 0.04f, 0.02f, dictionary);
    cv::Mat boardImage;
    board->draw(cv::Size(600, 500), boardImage, 10, 1);
    cv::imwrite("BoardImage.jpg", boardImage);
}*/

void drawSquare(
	cv::InputOutputArray image, cv::InputArray cameraMatrix,
	cv::InputArray distCoeffs, cv::InputArray rvec, cv::InputArray tvec,
	float l0
)
{
	float l = l0;  // new square is 5% larger than the aruco marker
	float half_l = l / 2.0;

	// Define the square on the camera frame (this is 3D since the camera
	// frame is 3D).
	std::vector<cv::Point3f> squarePoints;
	squarePoints.push_back(cv::Point3f(half_l, half_l, 0));
	squarePoints.push_back(cv::Point3f(half_l, -half_l, 0));
	squarePoints.push_back(cv::Point3f(-half_l, -half_l, 0));
	squarePoints.push_back(cv::Point3f(-half_l, half_l, 0));
	squarePoints.push_back(cv::Point3f(half_l, half_l, 0.1));
		squarePoints.push_back(cv::Point3f(half_l, -half_l, 0.1));
		squarePoints.push_back(cv::Point3f(-half_l, -half_l, 0.1));
		squarePoints.push_back(cv::Point3f(-half_l, half_l, 0.1));

	// Project the square to the image.
	std::vector<cv::Point2f> imagePoints;
	projectPoints(
		squarePoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints
	);

	// Draw the square on the image.
	cv::line(image, imagePoints[0], imagePoints[1], cv::Scalar(255, 0, 0), 3);
	cv::line(image, imagePoints[1], imagePoints[2], cv::Scalar(255, 0, 0), 3);
	cv::line(image, imagePoints[2], imagePoints[3], cv::Scalar(255, 0, 0), 3);
	cv::line(image, imagePoints[3], imagePoints[0], cv::Scalar(255, 0, 0), 3);
		cv::line(image, imagePoints[4], imagePoints[5], cv::Scalar(255, 0, 0), 3);
		cv::line(image, imagePoints[5], imagePoints[6], cv::Scalar(255, 0, 0), 3);
		cv::line(image, imagePoints[6], imagePoints[7], cv::Scalar(255, 0, 0), 3);
		cv::line(image, imagePoints[7], imagePoints[4], cv::Scalar(255, 0, 0), 3);
			cv::line(image, imagePoints[0], imagePoints[4], cv::Scalar(255, 0, 0), 3);
			cv::line(image, imagePoints[1], imagePoints[5], cv::Scalar(255, 0, 0), 3);
			cv::line(image, imagePoints[2], imagePoints[6], cv::Scalar(255, 0, 0), 3);
			cv::line(image, imagePoints[3], imagePoints[7], cv::Scalar(255, 0, 0), 3);
}

static float angulo = 0.0;
void redimensiona(int w, int h)
{
	glViewport(0, 0, w, h);

	float aspect = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);
}

struct vec3 {
	float x, y, z;
	vec3() :x(0.0), y(0.0), z(0.0) {}
	vec3(float x_, float y_, float z_) :x(x_), y(y_), z(z_) {}
};

typedef float color[3];
color naranja = {0.99f,0.58f,0.02f };
color anaranjado = {1.0, 0.62, 0.07};
color azul = {0.67,0.67,0.67};


void desenhaEsfera(GLfloat x_ini, GLfloat y_ini, GLfloat z_ini, GLfloat raio, GLuint nStacks, GLuint nSectors)
{
	std::vector< std::vector<GLuint> > indices;

	std::vector<vec3> pontos;
	const GLfloat PI = 3.14159265359;

	GLfloat deltaPhi = PI / nStacks;
	GLfloat deltaTheta = 2 * PI / nSectors;

	for (GLuint i = 0; i <= nStacks; i++)
	{
		GLfloat phi = -PI / 2.0 + i * deltaPhi;
		GLfloat temp = raio * cos(phi);
		GLfloat y = -y_ini*100 + raio * sin(phi);

		std::vector<GLuint> pt;

		for (GLuint j = 0; j < nSectors; j++)
		{
			GLfloat theta = j * deltaTheta;
			GLfloat x = x_ini*100 + temp * sin(theta);
			GLfloat z = -z_ini*100 + temp * cos(theta);

			pontos.push_back(vec3(x, y, z));
			GLuint index = pontos.size() - 1;
			pt.push_back(index);
		}// next j

		indices.push_back(pt);
	}// next i


	//glColor3fv(laranja);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (GLuint i = 0; i < nStacks; i++)
	{

		if (i % 3 == 0)
			glColor3fv(naranja);
		else if (i % 3 == 1)
			glColor3fv(anaranjado);
		else
			glColor3fv(naranja);

		glBegin(GL_TRIANGLE_STRIP);

		for (GLuint j = 0; j < nSectors; j++)
		{
			GLuint index = indices[i][j];
			glVertex3fv(&pontos[index].x);
			index = indices[i + 1][j];
			glVertex3fv(&pontos[index].x);

			if (j == nSectors - 1)
			{
				index = indices[i][0];
				glVertex3fv(&pontos[index].x);
				index = indices[i+1][0];
				glVertex3fv(&pontos[index].x);
			}
		}
		glEnd();
	}
}

void desenha(GLfloat x_ini, GLfloat y_ini, GLfloat z_ini)
{
	glLoadIdentity();

	glTranslatef(0.0, 0.0, -50.0);
	glRotatef(angulo, 1.0, 1.0, 0.0);
	desenhaEsfera(x_ini,y_ini,z_ini,10.0, 20.0, 20.0);


	//angulo += 0.1;
}

int main(int argc, char* argv[])
{

	const int LARGURA = 800;
		const int ALTURA = 600;

		/* Initialize the library */
		glfwInit();

		/* Create a windowed mode window and its OpenGL context */
		GLFWwindow* window = glfwCreateWindow(LARGURA, ALTURA, "Desenha Esfera", NULL, NULL);

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		// -- inicio
		glClearColor(0.0, 0.15, 0.25, 1.0); //
		glEnable(GL_DEPTH_TEST);

		cv::VideoCapture vid;
		    vid.open(0);
		    cv::Mat cameraMatrix, distCoeffs;
		    std::string filename = "C:\\Users\\Admin\\Desktop\\Jesé\\UNMSM\\2020-2\\CG\\proyecto\\Avance 1 Proyecto\\images\\DataCam.txt";
		    bool readOk = readCameraParameters(filename, cameraMatrix, distCoeffs);

		    if (!readOk) {
		        std::cerr << "Invalid camera file" << std::endl;
		    } else {


		    	std::vector<cv::Vec3d> rotationVectors, translationVectors;
		        cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
		        //cv::Ptr<cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(5, 7, 0.034f, 0.02f, dictionary);
		        cv::Ptr<cv::aruco::DetectorParameters> params = cv::aruco::DetectorParameters::create();
		        cv::Mat frame;
		        while (true)
		            {

					/* Poll for and process events */
					glfwPollEvents();
					if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
					{
						glfwSetWindowShouldClose(window, GLFW_TRUE);
					}

					/* Render here */
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

					int largura, altura;
					glfwGetFramebufferSize(window, &largura, &altura);

					redimensiona(largura, altura);

					/*desenha(20.0,20.0,20.0);

					/* Swap front and back buffers */
					//glfwSwapBuffers(window);

		        	std::vector<int> markerIds;
		        	            std::vector<std::vector<cv::Point2f> > markerCorners;
		                if (!vid.read(frame))
		                    break;

		                cv::aruco::detectMarkers(frame, dictionary, markerCorners, markerIds);
		                cv::aruco::estimatePoseSingleMarkers(markerCorners, 0.119f, cameraMatrix,
		                		distCoeffs, rotationVectors, translationVectors);

		                for (int i = 0; i < markerIds.size(); i++)
		                {
		                    //cv::aruco::drawAxis(frame, cameraMatrix, distCoeffs, rotationVectors[i], translationVectors[i], 0.1f);
		                	//drawSquare(frame,cameraMatrix,distCoeffs,rotationVectors[i],translationVectors[i],0.119f);

		                	desenha(translationVectors[i][0],translationVectors[i][1],translationVectors[i][2]);
		                	/* Swap front and back buffers */
		                	glfwSwapBuffers(window);



		                }
		                imshow("Webcam", frame);
		                if (cv::waitKey(30) >= 0) {
		                	glfwTerminate();
		                	break;
		                }
		            }

		    }



		/* Loop until the user closes the window */
		//while (!glfwWindowShouldClose(window))
		{
			/* Poll for and process events */
			/*glfwPollEvents();
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				glfwSetWindowShouldClose(window, GLFW_TRUE);
			}

			/* Render here */
			/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			int largura, altura;
			glfwGetFramebufferSize(window, &largura, &altura);

			redimensiona(largura, altura);

			desenha(20.0,20.0,20.0);

			/* Swap front and back buffers */
			//glfwSwapBuffers(window);
		}


    return 0;
}



