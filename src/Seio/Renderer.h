#pragma once

#include <glm/glm.hpp>

#include "Component.h"

namespace Seio
{
    class Renderer : public Component
    {
        public:
            virtual ~Renderer() = default;

            virtual void Draw(glm::mat4 mvp)= 0;
    };
}