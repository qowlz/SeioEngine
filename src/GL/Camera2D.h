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

    float GetWidth() const
    {
        return width;
    }

    float GetHeight() const
    {
        return height;
    }

    glm::vec3 GetPosition() const
    {
        return position;
    }

    void SetWidth(float value)
    {
        width = value;
    }

    void SetHeight(float value)
    {
        height = value;
    }

    void SetPosition(glm::vec3 value)
    {
        position = value;
    }

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;

    float width;
    float height;
};