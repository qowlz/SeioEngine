#pragma once

#include <glm/glm.hpp>

namespace Seio
{
    class Renderer
    {
        public:
            virtual void Draw(glm::mat4 trM)= 0;
    };
}