#pragma once

#include <string>

#include "../Terrain/Chunk.hpp"
#include "../Utils/GL.hpp"

#define CAMERA_POSITION vec3(6, 16, 16)

namespace Core {
	namespace Graphics {
		using namespace glm;
		typedef void(*HandleInput)(const GLint* const, const GLint* const);
		class Window {
		private:
			HandleInput handleInputFunc;
			GLFWwindow* window;
			Shader* shader = nullptr;
			int width, height;
			const char* title;
			glm::vec4 clearColor;
			GLuint matrixID;
			mat4 view, projection, model, mvp;
		public:
			Window(const char* title, int width, int height, glm::vec4 clearColor = glm::vec4(.5f, .5f, .9f, .0f));
			~Window();
			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }
			inline void setWidth(int width) { this->width = width; }
			inline void setHeight(int height) { this->height = height; }
			inline void setClearColor(glm::vec4 clearColor) { this->clearColor; }
			inline void setHandleInputFunc(HandleInput _handleInputFunc) { handleInputFunc = _handleInputFunc; }
			inline HandleInput getHandleInputFunc() { return handleInputFunc; }
			void update(Terrain::Chunk* chunks, size_t nrOfChunks, Terrain::RenderMode renderMode) const;
			bool closed() const;
			void setButtonCallback(GLFWmousebuttonfun func);
			void setKeyCallback(GLFWkeyfun func);
		private:
			bool init();
		};
	}
}