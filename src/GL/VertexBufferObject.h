#pragma once

#include <vector>
#include <glad/glad.h>

class VertexBufferObject
{
public:
    VertexBufferObject();
    ~VertexBufferObject();

    void Bind() const;
    void Unbind() const;

    void Write(const std::vector<float>& vertices);

    GLuint GetID() const;

private:
    GLuint id;
};