#include "GL/VertexBufferObject.h"

VertexBufferObject::VertexBufferObject()
{
    glGenBuffers(1, &id);
}

VertexBufferObject::~VertexBufferObject()
{
    glDeleteBuffers(1, &id);
}

void VertexBufferObject::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBufferObject::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferObject::Write(const std::vector<float>& vertices)
{
    Bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), &vertices.front(), GL_STATIC_DRAW);
}

