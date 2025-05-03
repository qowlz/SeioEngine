#pragma once

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// #define GLM_ENABLE_EXPERIMENTAL
// #include <glm/gtx/string_cast.hpp>

#include "Component.h"

namespace Seio
{
    class Transform : public Component
    {
        public:
            Transform()
                : position { 0, 0, 0 }
                , rotation { 0, 0, 0 }
                , scale { 1, 1, 1 }
            {
            }

            // 복사 생성자 삭제
            Transform(const Transform& src) = delete;

            glm::vec3 GetPosition() const
            {
                return this->position;
            }
            glm::vec3 GetRotation() const
            {
                return this->rotation;
            }
            glm::vec3 GetScale() const
            {
                return this->scale;
            }

            glm::mat4 GetMatrix() const
            {
                glm::mat4 ret { 1.0f };
                ret = glm::translate(ret, position);

                // z - y - x order rotation
                // FIXME: 3번 연산하는게 비효율적임
                ret = glm::rotate(ret, glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
                ret = glm::rotate(ret, glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
                ret = glm::rotate(ret, glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));

                ret = glm::scale(ret, scale);

                // std::cout << glm::to_string(ret) << std::endl;

                return ret;
            }

            void SetPosition(float x, float y, float z)
            {
                this->position = glm::vec3(x, y, z);
            }
            void SetRotation(float x, float y, float z)
            {
                this->rotation = glm::vec3(x, y, z);
            }
            void SetScale(float x, float y, float z)
            {
                this->scale = glm::vec3(x, y, z);
            }

            void OnDrawImGui() override;

        private:
            glm::vec3 position;

            glm::vec3 rotation;

            glm::vec3 scale;
    };
}