#pragma once

#include "../Utils/GL.hpp"
#include "Texture.hpp"

namespace Core {
	namespace Graphics {
		/* Type of rendering (Solid/Wired) */
		enum class RenderMode { SOLID, WIRED };

		/* Entity, which will be rendered */
		class Drawable {
		protected:
			GLsizei nrOfVertices;
			glm::ivec3 position;
			TextureID textureOffset;
			glm::vec4 color;
			glm::vec2 texturePercentage;
		public:
			Drawable(glm::ivec3 position, TextureID textureOffset, glm::vec2 texturePercentage, GLuint vertexAttrSize)
				: nrOfVertices(vertexAttrSize), textureOffset(textureOffset), texturePercentage(texturePercentage), position(position) {}

			virtual ~Drawable() {}

			void setPosition(glm::ivec3 position) { this->position = position; }
			glm::vec3 getPosition() const { return position; }

			void setTextureOffset(TextureID textureOffset) { this->textureOffset = textureOffset; }
			glm::vec2 getTextureOffset() const { return glm::vec2((GLubyte)textureOffset & 0x0F, ((GLubyte)textureOffset >> 4) & 0x0F); }
			TextureID getTextureID() const { return textureOffset; }
			void setColor(glm::vec4 color) { this->color = color; }
			glm::vec4 getColor() const { return color; }

			GLsizei getSize() { return nrOfVertices; }
		};
	}
}