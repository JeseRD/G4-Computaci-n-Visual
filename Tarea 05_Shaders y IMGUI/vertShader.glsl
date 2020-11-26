#version 410

uniform vec2 offset;
uniform vec3 offCol;
out vec3 colorT;

void main(void) {
    if (gl_VertexID == 0) 
    	gl_Position = vec4(0.25 + offset.x, -0.25 + offset.y, 0.0, 1.0);
    else if (gl_VertexID == 1) 
    	gl_Position = vec4(-0.25 + offset.x, -0.25 + offset.y, 0.0, 1.0);
    else 
    	gl_Position = vec4(0.25 + offset.x, 0.25 + offset.y, 0.0, 1.0);

    colorT = offCol;
}
