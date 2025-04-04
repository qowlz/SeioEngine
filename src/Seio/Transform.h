#pragma once

#include <glm/glm.hpp>

namespace Seio
{
    class Transform
    {
        public:
            Transform()
                : position { 0, 0, 0 }
                , rotation { 0, 0, 0 }
                , scale { 0, 0, 0 }
            {
            }

            glm::vec3 GetPosition() const;
            glm::vec3 GetRotation() const;
            glm::vec3 GetScale() const;

            glm::vec3 SetPosition();
            glm::vec3 SetRotation();
            glm::vec3 SetScale();

        private:
            glm::vec3 position;

            glm::vec3 rotation;

            glm::vec3 scale;
    };
}