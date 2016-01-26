#version 330

in vec2 _uv;

out vec4 color;

uniform sampler2D texSampler;

void main() {
    color = texture(texSampler, _uv);
}