#include "GL/VertexArrayObject.h"

VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &id);
}

VertexArrayObject::~VertexArrayObject()
{
    glDeleteVertexArrays(1, &id);
}

void VertexArrayObject::Bind() const
{
    glBindVertexArray(id);
}

void VertexArrayObject::Unbind() const
{
    glBindVertexArray(0);
}

void VertexArrayObject::SetAttributePointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void VertexArrayObject::EnableAttribute(GLuint index)
{
    glEnableVertexAttribArray(index);
}