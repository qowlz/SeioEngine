#pragma once

#include <glad/glad.h>

class VertexArrayObject
{
public:
    VertexArrayObject();
    ~VertexArrayObject();

    void Bind() const;
    void Unbind() const;

    // TODO: OpenGL API랑 1:1 매칭을 해놔서 사용감이 매우 구림. 개선해야함.
    void SetAttributePointer(GLuint index, GLint size, GLenum type,
                           GLboolean normalized, GLsizei stride, const void* pointer);
    void EnableAttribute(GLuint index);

private:
    GLuint id;
};