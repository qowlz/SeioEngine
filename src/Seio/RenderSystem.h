#pragma once

#include <queue>

#include "Singleton.h"
#include "glad/glad.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

namespace Seio
{
    struct DrawCall
    {
        // vao를 받는게 가장 좋을까?


        GLuint textureID;
        GLuint shaderID;
    };

    class RenderSystem : public Singleton<RenderSystem>
    {
        public:
            void Render();

            void RequestDrawQuad(GLuint textureID, GLuint shaderID, glm::mat4 mvp);

        private:
            std::queue<DrawCall> renderQueue;
    };
} // namespace Seio