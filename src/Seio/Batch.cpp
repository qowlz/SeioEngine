#include "Batch.h"

namespace Seio
{
    Batch::Batch()
    {
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ibo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 1000, nullptr, GL_DYNAMIC_DRAW); // FIXME: 일단 버퍼의 크기를 정점 1000개정도로 잡음. 추후에 동적으로 성장하는 방식으로 바꿔야 함.

        glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (const void*) offsetof(Vertex, pos));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(Vertex), (const void*) offsetof(Vertex, texCoord));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 250 * 6, nullptr, GL_DYNAMIC_DRAW); // quad가 최대 250개 생성될 수 있고, quad 1개 당 6개의 indices가 필요함
    }

    Batch::~Batch()
    {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ibo);
    }

    void Batch::AppendVertices(Vertex* vertices, size_t count)
    {
        unsigned int totalSize = sizeof(Vertex) * count;
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferSubData(GL_ARRAY_BUFFER, vbOffset, totalSize, vertices);

        vbOffset += totalSize;
    }

    void Batch::AppendIndices(unsigned int* indices, size_t count)
    {
        unsigned int orderOffset = ibOffset / sizeof(unsigned int);
        for (size_t i = 0; i < count; i++)
            indices[i] += orderOffset;

        unsigned int totalSize = sizeof(unsigned int) * count;
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, ibOffset, totalSize, indices);

        ibOffset += totalSize;
    }
}