#version 410
//color del triangulo
in vec3 colorT;

out vec4 color;

void main(void){
	color = vec4(colorT, 1.0);
}
