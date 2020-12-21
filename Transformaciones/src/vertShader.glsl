#version 410
layout (location=0) in vec3 position;  // coord cuadrilateros
layout (location=1) in vec3 positionC;  // coord circunferencia
uniform float rotate;
uniform float time;
uniform float posx;
uniform float rad;
uniform float radant;

out vec3 oColor;

// funtions to Transformations(Rotate, Translate, Scale)
mat4 buildRotateX(float rad);
mat4 buildRotateY(float rad);
mat4 buildRotateZ(float rad);
mat4 buildTranslate(float dx, float dy, float dz);
mat4 buildScale(float sx, float sy, float sz);

const float radius = 0.07;
const float pi = 3.141592653589793;
const float twicePi = 2*pi;
const float numberOfSides = 12; //Numero de punto donde ser trasladan los triangulos


void main(void) {
	float a, b, c = 0;

	//float i = gl_VertexID;

	//gl_Position = vec4(positionC, 1.0);



	if(gl_InstanceID == 0){ //Triangle in I quadrant
		a = 0; b = 0.4;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(2, 2, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
		oColor = vec3(1.0, 0.0, 0.0);

	}else if(gl_InstanceID == 1){ //Triangle in II quadrant
		a = 0; b = 0.4;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(1.5, 1.5, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
		oColor = vec3(1.0, 1.0, 1.0);

	}else if(gl_InstanceID == 2){ //Triangle in III quadrant
		a = 0; b = 0.4;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(1, 1, 0); //Scale in 50%.
		oColor = vec3(0.4, 0.4, 0.4);

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left

	}else if(gl_InstanceID == 3){  //Triangle in IV quadrant
		a = 0 + radius * cos(0 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(0 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left

	}else if(gl_InstanceID == 4){  //Triangle in IV quadrant
		a = 0 + radius * cos(1 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(1 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 5){  //Triangle in IV quadrant
		a = 0 + radius * cos(2 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(2 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 6){  //Triangle in IV quadrant
		a = 0 + radius * cos(3 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(3 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 7){  //Triangle in IV quadrant
		a = 0 + radius * cos(4 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(4 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 8){  //Triangle in IV quadrant
		a = 0 + radius * cos(5 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(5 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 9){  //Triangle in IV quadrant
		a = 0 + radius * cos(6 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(6 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 10){  //Triangle in IV quadrant
		a = 0 + radius * cos(7 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(7 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 11){  //Triangle in IV quadrant
		a = 0 + radius * cos(8 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(8 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 12){  //Triangle in IV quadrant
		a = 0 + radius * cos(9 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(9 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 13){  //Triangle in IV quadrant
		a = 0 + radius * cos(10 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(10 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 14){  //Triangle in IV quadrant
		a = 0 + radius * cos(11 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(11 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 15){  //Triangle in IV quadrant
		a = 0 + radius * cos(12 * twicePi / numberOfSides);
		b = 0.4 + radius * sin(12 * twicePi / numberOfSides);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 0.07, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 16){  //Bola de pendulo
		a = 0; b = -0.35;

		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.5, 0.5, 0); //Scale in 50%.
		mat4 localRotaZ = buildRotateZ((rotate) * twicePi*50 / 360);

		gl_Position = localRotaZ * localTrans * localScal * vec4(position, 1.0);  // right-to-left
	}else if(gl_InstanceID == 17){ //Triangle in II quadrant
		a = 0; b = 0.4;
		mat4 localTransini = buildTranslate(0, 0.032, 0);
		mat4 localRotaZ = buildRotateZ((time) * twicePi*50 / 360);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.05, 0.32, 0); //Scale in 50%.


		oColor = vec3(0.0, 0.0, 0.0);
		gl_Position = localTrans * localRotaZ * localTransini * localScal * vec4(position, 1.0);  // right-to-left

	}else if(gl_InstanceID == 18){ //Triangle in II quadrant
		a = 0; b = 0.4;
		mat4 localTransini = buildTranslate(0, 0.032, 0);
		mat4 localRotaZ = buildRotateZ((time/12) * twicePi*50 / 360);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.05, 0.28, 0); //Scale in 50%.


		oColor = vec3(0.0, 0.0, 0.0);
		gl_Position = localTrans * localRotaZ * localTransini * localScal * vec4(position, 1.0);  // right-to-left

	}else if(gl_InstanceID == 19){ //Triangle in II quadrant
		a = posx; b = (rad - radant)*2 -0.7;
		mat4 localTransini = buildTranslate(1.11, 0.9, 0);
		mat4 localRotaZ = buildRotateZ((time) * twicePi*50 / 360);
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(rad,rad, 0); //Scale in 50%.



		gl_Position = localTrans * localRotaZ * localScal * localTransini * vec4(position.x-1.11,position.y-0.9, 0, 1.0);  // right-to-left

	}else if(gl_InstanceID == 20){ //Triangle in II quadrant
		a = 0; b = -0.2;

		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.07, 2.0, 0); //Scale in 50%.
		mat4 localRotaZ = buildRotateZ((rotate) * twicePi*50 / 360);

		oColor = vec3(0.0, 0.0, 0.0);
		gl_Position = localRotaZ * localTrans * localScal * vec4(position, 1.0);
	}else if(gl_InstanceID == 21){ //Triangle in II quadrant
		a = -0.3; b = 0.1;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.05, 6.0, 0); //Scale in 50%.

		oColor = vec3(0.5, 0.25, 0.0);
		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left


	}else if(gl_InstanceID == 22){ //Triangle in II quadrant
		a = 0; b = 0.68;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(3.0, 0.05, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
		oColor = vec3(0.5, 0.25, 0.0);

	}else if(gl_InstanceID ==23){ //Triangle in II quadrant
		a = 0.3; b = 0.1;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.05, 6.0, 0); //Scale in 50%.

		oColor = vec3(0.5, 0.25, 0.0);
		gl_Position = localTrans * localScal * vec4(position, 1.0);

	}else if(gl_InstanceID == 24){ //Triangle in II quadrant
		a = 0; b = -0.48;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(3.0, 0.05, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
		oColor = vec3(0.5, 0.25, 0.0);

	}else if(gl_InstanceID == 25){ //Triangle in II quadrant
		a = -0.255; b = -0.2;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.05, 2.0, 0); //Scale in 50%.

		oColor = vec3(0.5, 0.25, 0.0);
		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left


	}else if(gl_InstanceID == 26){ //Triangle in II quadrant
		a = 0; b = -0.01;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(2.55, 0.05, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
		oColor = vec3(0.5, 0.25, 0.0);

	}else if(gl_InstanceID ==27){ //Triangle in II quadrant
		a = 0.255; b = -0.2;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(0.05, 2.0, 0); //Scale in 50%.

		oColor = vec3(0.5, 0.25, 0.0);
		gl_Position = localTrans * localScal * vec4(position, 1.0);

	}else if(gl_InstanceID == 28){ //Triangle in II quadrant
		a = 0; b = -0.4;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(2.55, 0.05, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
		oColor = vec3(0.5, 0.25, 0.0);

	}else if(gl_InstanceID == 29){ //Triangle in II quadrant
		a = 0; b = 0.1;
		mat4 localTrans = buildTranslate(a, b, 0); //Translate in x and y axis.
		mat4 localScal = buildScale(3.0, 0.05, 0); //Scale in 50%.

		gl_Position = localTrans * localScal * vec4(position, 1.0);  // right-to-left
		oColor = vec3(0.5, 0.25, 0.0);

	}


	
	//All Transformation funtions. 	
	
}

// builds and returns a matrix that performs a rotation around the X axis
mat4 buildRotateX(float rad) {
    mat4 xrot = mat4(1.0, 0.0,      0.0,       0.0,
                     0.0, cos(rad), -sin(rad), 0.0,
                     0.0, sin(rad), cos(rad),  0.0,
                     0.0, 0.0,      0.0,       1.0);
    return xrot;
}

// builds and returns a matrix that performs a rotation around the Y axis
mat4 buildRotateY(float rad) {
    mat4 yrot = mat4(cos(rad),  0.0, sin(rad), 0.0,
                     0.0,       1.0, 0.0,      0.0,
                     -sin(rad), 0.0, cos(rad), 0.0,
                     0.0,       0.0, 0.0,      1.0);
    return yrot;
}

// builds and returns a matrix that performs a rotation around the Z axis
mat4 buildRotateZ(float rad) {
    mat4 zrot = mat4(cos(rad), -sin(rad), 0.0, 0.0,
                     sin(rad), cos(rad),  0.0, 0.0,
                     0.0,      0.0,       1.0, 0.0,
                     0.0,      0.0,       0.0, 1.0);
    return zrot;
}

// builds and returns a translation matrix
mat4 buildTranslate(float x, float y, float z) {
    mat4 trans = mat4(1.0, 0.0, 0.0, 0.0,
                      0.0, 1.0, 0.0, 0.0,
                      0.0, 0.0, 1.0, 0.0,
                      x,   y,   z,   1.0);
    return trans;
}

// builds and returns a Scale matrix
mat4 buildScale(float sx, float sy, float sz) {
    mat4 scale = mat4( sx, 0.0, 0.0, 0.0,
                      0.0,  sy, 0.0, 0.0,
                      0.0, 0.0,  sz, 0.0,
                      0.0, 0.0, 0.0, 1.0);
    return scale;
}
