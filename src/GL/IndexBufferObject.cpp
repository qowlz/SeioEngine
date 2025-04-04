#include "GL/IndexBufferObject.h"

IndexBufferObject::IndexBufferObject()
{
    glGenBuffers(1, &this->id);
}

IndexBufferObject::~IndexBufferObject()
{
    glDeleteBuffers(1, &this->id);
}

void IndexBufferObject::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
}

void IndexBufferObject::UnBind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBufferObject::Write(const std::vector<unsigned int>& indices)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}