#pragma once

#include <queue>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

#include "Singleton.h"
#include "GL/VertexArrayObject.h"
#include "GL/VertexBufferObject.h"
#include "GL/IndexBufferObject.h"

namespace Seio
{
    struct Vertex
    {
        glm::vec3 pos;
        glm::vec2 texCoord;
    };


    struct DrawCall
    {
        GLuint textureID;
        GLuint shaderID;
        glm::mat4 mvp;
    };

    class RenderSystem : public Singleton<RenderSystem>
    {
        public:
            RenderSystem();

            void Render();

            void RequestDrawQuad(GLuint textureID, GLuint shaderID, glm::mat4 mvp);

        private:
            // std::queue<DrawCall> renderQueue;

            VertexArrayObject vao;

            VertexBufferObject vbo;

            IndexBufferObject ibo;

            GLintptr vertexBufferOffset = 0;
            GLintptr indexBufferOffset = 0;
    };
}