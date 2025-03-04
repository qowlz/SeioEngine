#pragma once

#include <glad/glad.h>

class VertexArrayObject
{
public:
    VertexArrayObject();
    ~VertexArrayObject();

    void Bind() const;
    void Unbind() const;

    void SetAttributePointer(GLuint index, GLint size, GLenum type,
                           GLboolean normalized, GLsizei stride, const void* pointer);
    void EnableAttribute(GLuint index);

private:
    GLuint id;
};