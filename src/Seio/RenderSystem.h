#pragma once

#include <unordered_map>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

#include "Singleton.h"
#include "GL/VertexArrayObject.h"
#include "GL/VertexBufferObject.h"
#include "GL/IndexBufferObject.h"
#include "Batch.h"

namespace Seio
{
    class RenderSystem : public Singleton<RenderSystem>
    {
        public:
            RenderSystem() = default;

            void Render();

            void RequestDrawQuad(GLuint textureID, GLuint shaderID, glm::mat4 mvp);

        private:
            std::unordered_map<GLuint, Batch> batchMap;
    };
}