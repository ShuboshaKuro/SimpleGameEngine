#version 330

layout(location = 0) in vec3 vertexPos_ms;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

out vec3 _uv;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;

void main() {
    gl_Position = Projection * View * Model * vec4(vertexPos_ms, 1);
    _uv = vertexPos_ms;
}