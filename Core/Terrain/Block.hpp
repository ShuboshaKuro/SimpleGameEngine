#pragma once

#include "../Utils/GL.hpp"
#include "../Graphics/Drawable.hpp"
#include "../Graphics/BlockContext.hpp"
#include "../Graphics/Renderer.hpp"

namespace Core {
	namespace Terrain {
		/*
			Types of Blocks like sand, stone ...
		*/
		enum class BlockType
		{
			NONE,
			WATER,
			STONE_ROUGH,
			STONE_DARK,
			STONE_BRIGHT,
			GRASS_GREEN,
			GRASS_SEMI,
			GRASS_LONG_BROWN,
			SAND,
			KIES,
			SNOW
		};

		/*
			Presentation of an Block in our world
		*/
		class Block : public Graphics::Drawable {
		protected:
			BlockType type;
			// Should the block be rendered
			GLboolean enabled = GL_TRUE, covered = GL_FALSE;
		public:
			Block(glm::ivec3 position, BlockType type, Graphics::TextureID textureOffset, GLboolean enabled);
			~Block();

			/* Enable the Block */
			void enable();
			/* Disable the Block */
			void disable();
			/* Transform the Block */
			void transformTo(BlockType type);

			GLboolean isEnabled() const { return enabled; };
			GLboolean isCovered() const { return covered; };
			/* Checks the presence of the Block */
			GLboolean check() const { return (covered || enabled) && type != BlockType::WATER; };
			void isCovered(GLboolean isCovered) { covered = isCovered; }
			BlockType getBlockType() const { return type; };

			/* Submit Block for rendering */
			void submit(Graphics::Renderer* renderer, Graphics::BlockContext* context, glm::vec2& range = glm::vec2(0, 0)) const;
		};
	}
}