#pragma once

#include <vector>
#include <glad/glad.h>

class IndexBufferObject
{
public:
    IndexBufferObject();
    ~IndexBufferObject();

    IndexBufferObject(const IndexBufferObject&) = delete;
    IndexBufferObject& operator=(const IndexBufferObject&) = delete;

    void Bind() const;

    void UnBind() const;

    void Write(const std::vector<unsigned int>& indices);

private:
    GLuint id;
};
