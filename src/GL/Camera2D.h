#pragma once

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Camera2D
{
public:
    Camera2D() = delete;

    Camera2D(glm::vec2 position, int width, int height);
    glm::mat4 GetViewM() const;
    glm::mat4 GetProjectionM() const;

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;

    int width;
    int height;
};