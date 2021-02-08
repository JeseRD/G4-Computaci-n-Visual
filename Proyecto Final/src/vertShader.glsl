/*
 * vertShader.glsl
 *
 *  Created on: 6 feb. 2021
 *      Author: Admin
 */
#version 410

layout (location = 0) in vec3 position;

//uniform mat4 m_matrix;
//uniform mat4 v_matrix;
//uniform mat4 proj_matrix;

#ifndef SRC_VERTSHADER_GLSL_
#define SRC_VERTSHADER_GLSL_

void main(void) {
	//M->V->P
    gl_Position = vec4(position, 1.0);
}



#endif /* SRC_VERTSHADER_GLSL_ */
