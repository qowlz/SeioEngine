#pragma once

#include <glm/glm.hpp>

namespace Seio
{
    class Renderer
    {
        public:
            virtual ~Renderer() = default;

            virtual void Draw(glm::mat4 mvp)= 0;
    };
}