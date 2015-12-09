#version 330

layout(location = 0) in vec3 vertexPos_ms;

uniform mat4 MVP;

void main() {
	gl_Position = MVP * vec4(vertexPos_ms, 1);
}