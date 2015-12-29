#pragma once

#include "Block.hpp"
#include "../Graphics/Shader.hpp"
#include "../Graphics/Renderer.hpp"
#include "../Graphics/Texture.hpp"
#include "../Utils/Output.hpp"

#define CHUNK_SIZE_X 3
#define CHUNK_SIZE_Y 3
#define CHUNK_SIZE_Z 3
#define BLOCKSIZE 1

namespace Core {
	namespace Terrain {
		using namespace Graphics;
		/* A chunk in our world */
		class Chunk {
		private:
			GLuint64 chunkID;
			Block**** blocks;
			Chunk *lchunk, *tchunk, *bchunk;
			Renderer* renderer;
			RenderMode mode = RenderMode::SOLID;
			Texture texture;
			GLuint vertexCount = 36;
			vec3 position;
			mat4 model = mat4(1), mvp;
		public:
			Chunk(vec3 position, Chunk* lchunk, Chunk* tchunk, Chunk* bchunk);
			~Chunk();

			void setRenderMode(RenderMode mode);
			RenderMode getRenderMode() const { return mode; }
			/* Switch between Rendermodes */
			void toggleRenderMode();

			/* Draws the chunk */
			void draw(mat4 projection, mat4 view, RenderMode renderMode);
		};
	}
}