#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"
#include "imgui\imgui_impl_opengl3.h"

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#include "fun.h"

///IMPORTADO
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
/*
#define WIDTH 1280
#define HEIGHT 720
*/

#define WIDTH 800
#define HEIGHT 500

///IMPORTADO
GLuint renderingProgram;
GLuint m_VBO;
GLuint m_VAO;

float x = 0.5f;
float y = 0.5f;
float R = 1.0f;
float G = 1.0f;
float B = 1.0f;
float Rf = 0.0f;
float Gf = 0.0f;
float Bf = 0.0f;
using namespace std;



/* ImGui */
void display();
void init(GLFWwindow *window);

/* Temas */
void CherryTheme();

int main(){
    if (!glfwInit()) return 1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_RESIZABLE, false);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    // glfwSetWindowSizeCallback(window, resize_callback);
    if (window == NULL) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    if (glewInit() != GLEW_OK) return 1;

    init(window);

    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        display();
        glfwSwapBuffers(window);
    }

    /*--[CLEAN IMGUI]-----------*/
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    /*--[CLEAN IMGUI]-----------*/

}


void init(GLFWwindow *window){

	renderingProgram = Utils::createShaderProgram("vertShader.glsl", "fragShader.glsl");
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	/*--[INICIALIZACION IMGUI]-----------*/
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // TEMAS: 
    // ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();
    // ImGui::StyleColorsLight();
    // CherryTheme();
    
    /*--[INICIALIZACION IMGUI]-----------*/

}


void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(R, G, B, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(renderingProgram);

    	glm::vec2 newPos(x, y);
    	glm::vec3 colorFig(Rf, Gf, Bf);

    	//Obtiene el valor de la posición(No su valor) de la variable uniforme "offset"
    	GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");
    	//void glProgramUniform2fv(	GLuint program,	GLint location,	GLsizei count, 	const GLfloat *value);
    	glProgramUniform2fv(renderingProgram, offsetLoc, 1, glm::value_ptr(newPos));
    	glDrawArrays(GL_TRIANGLES, 0, 3);

    	GLuint offsetCol = glGetUniformLocation(renderingProgram, "offCol");
    	    	//void glProgramUniform2fv(	GLuint program,	GLint location,	GLsizei count, 	const GLfloat *value);
    	glProgramUniform3fv(renderingProgram, offsetCol, 1, glm::value_ptr(colorFig));
    	glDrawArrays(GL_TRIANGLES, 0, 3);


    /*--[FRAME IMGUI]-----------*/
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::SetNextWindowSize(ImVec2(400, HEIGHT));
    ImGui::SetNextWindowPos(ImVec2(0,0));
    /*--[FRAME IMGUI]-----------*/




    /*--[CODIGO IMGUI]-----------*/

    ImGuiStyle& style = ImGui::GetStyle();    
    style.FrameBorderSize = 1.0f;
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_MenuBar;
    window_flags |= ImGuiWindowFlags_NoCollapse;
    
    ImGui::Begin("Ventana principal", nullptr, window_flags);

    static bool show_ex_sort = false, show_fibo = false;
    static bool edit_apar = false;

    if (ImGui::BeginMenuBar()){
        if (ImGui::BeginMenu("Change")){
            ImGui::MenuItem("Obect Color", NULL, &show_fibo);
            ImGui::MenuItem("Background Color", NULL, &show_ex_sort);
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Mover")){
            ImGui::MenuItem("Mover triangulo", NULL, &edit_apar);
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    if (show_fibo) {
        if (ImGui::CollapsingHeader("Color figura")){
			static int e = 0;
            ImGui::RadioButton("Dark", &e, 0); ImGui::SameLine();
            ImGui::RadioButton("Rojo", &e, 1); ImGui::SameLine();
            ImGui::RadioButton("Verde", &e, 2);
            ImGui::RadioButton("Azul", &e, 3);

            if (e == 0) {Rf = 0.0; Gf = 0.0; Bf = 0.0;}
            if (e == 1) {Rf = 1.0; Gf = 0.0; Bf = 0.0;}
            if (e == 2) {Rf = 0.0; Gf = 1.0; Bf = 0.0;}
            if (e == 3) {Rf = 0.0; Gf = 0.0; Bf = 1.0;}
        }
    }

    if (show_ex_sort){
        if (ImGui::CollapsingHeader("Color fondo")){
            static int e = 0;
            ImGui::RadioButton("White", &e, 0); ImGui::SameLine();
            ImGui::RadioButton("Dark", &e, 1); ImGui::SameLine();
            ImGui::RadioButton("Red", &e, 2);
            ImGui::RadioButton("Green", &e, 3);

            if (e == 0) {R=1.0;G=1.0;B=1.0;}
            if (e == 1) {R=0.0;G=0.0;B=0.0;}
            if (e == 2) {R=1.0;G=0.0;B=0.0;}
            if (e == 3) {R=0.0;G=1.0;B=0.0;}
        }
    }
    
    if (edit_apar){
        ImGui::Begin("Mover triangulo");


            ImGui::Text("\n");
            ImGui::SameLine(80);
            if (ImGui::Button("Arriba")){
            	y += 0.01f;

            }

            if (ImGui::Button("Izquierda")){
            	x += -0.01f;

            }

            ImGui::SameLine();

            if (ImGui::Button("Abajo")){
            	y += -0.01f;

            }
            ImGui::SameLine();

            if (ImGui::Button("Derecha")){
            	x += 0.01f;

                        }

        ImGui::End();
    }
    
    // ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();

    /*--[CODIGO IMGUI]-----------*/

    /*--[RENDER IMGUI]-----------*/
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    /*--[RENDER IMGUI]-----------*/
}


void CherryTheme() {
    // cherry colors, 3 intensities
    #define HI(v)   ImVec4(0.502f, 0.075f, 0.256f, v)
    #define MED(v)  ImVec4(0.455f, 0.198f, 0.301f, v)
    #define LOW(v)  ImVec4(0.232f, 0.201f, 0.271f, v)
    // backgrounds (@todo: complete with BG_MED, BG_LOW)
    #define BG(v)   ImVec4(0.200f, 0.220f, 0.270f, v)
    // text
    #define TEXT(v) ImVec4(0.860f, 0.930f, 0.890f, v)

    auto &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_Text]                  = TEXT(0.78f);
    style.Colors[ImGuiCol_TextDisabled]          = TEXT(0.28f);
    style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
    // style.Colors[ImGuiCol_ChildWindowBg]         = BG( 0.58f);
    style.Colors[ImGuiCol_PopupBg]               = BG( 0.9f);
    style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
    style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg]               = BG( 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered]        = MED( 0.78f);
    style.Colors[ImGuiCol_FrameBgActive]         = MED( 1.00f);
    style.Colors[ImGuiCol_TitleBg]               = LOW( 1.00f);
    style.Colors[ImGuiCol_TitleBgActive]         = HI( 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed]      = BG( 0.75f);
    style.Colors[ImGuiCol_MenuBarBg]             = BG( 0.47f);
    style.Colors[ImGuiCol_ScrollbarBg]           = BG( 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]  = MED( 0.78f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]   = MED( 1.00f);
    style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
    style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_Button]                = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
    style.Colors[ImGuiCol_ButtonHovered]         = MED( 0.86f);
    style.Colors[ImGuiCol_ButtonActive]          = MED( 1.00f);
    style.Colors[ImGuiCol_Header]                = MED( 0.76f);
    style.Colors[ImGuiCol_HeaderHovered]         = MED( 0.86f);
    style.Colors[ImGuiCol_HeaderActive]          = HI( 1.00f);
    // style.Colors[ImGuiCol_Column]                = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
    // style.Colors[ImGuiCol_ColumnHovered]         = MED( 0.78f);
    // style.Colors[ImGuiCol_ColumnActive]          = MED( 1.00f);
    style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
    style.Colors[ImGuiCol_ResizeGripHovered]     = MED( 0.78f);
    style.Colors[ImGuiCol_ResizeGripActive]      = MED( 1.00f);
    style.Colors[ImGuiCol_PlotLines]             = TEXT(0.63f);
    style.Colors[ImGuiCol_PlotLinesHovered]      = MED( 1.00f);
    style.Colors[ImGuiCol_PlotHistogram]         = TEXT(0.63f);
    style.Colors[ImGuiCol_PlotHistogramHovered]  = MED( 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg]        = MED( 0.43f);
    // [...]
    style.Colors[ImGuiCol_ModalWindowDarkening]  = BG( 0.73f);

    style.WindowPadding            = ImVec2(6, 4);
    style.WindowRounding           = 0.0f;
    style.FramePadding             = ImVec2(5, 2);
    style.FrameRounding            = 3.0f;
    style.ItemSpacing              = ImVec2(7, 1);
    style.ItemInnerSpacing         = ImVec2(1, 1);
    style.TouchExtraPadding        = ImVec2(0, 0);
    style.IndentSpacing            = 6.0f;
    style.ScrollbarSize            = 12.0f;
    style.ScrollbarRounding        = 16.0f;
    style.GrabMinSize              = 20.0f;
    style.GrabRounding             = 2.0f;

    style.WindowTitleAlign.x = 0.50f;

    style.Colors[ImGuiCol_Border] = ImVec4(0.539f, 0.479f, 0.255f, 0.162f);
    style.FrameBorderSize = 0.0f;
    style.WindowBorderSize = 1.0f;
}
