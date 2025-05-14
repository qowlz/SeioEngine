#pragma once

#include "glad/glad.h"

#include "Vertex.h"

namespace Seio
{
    class Batch
    {
        public:
            Batch();
            ~Batch();

            Batch(const Batch& other) = delete;
            Batch& operator=(const Batch&) = delete;

            Batch(Batch&& other) noexcept = default;
            Batch& operator=(Batch&& other) noexcept = default;

            void AppendVertices(Vertex* vertices, size_t count);

            void AppendIndices(unsigned int* indices, size_t count);

            GLuint GetVAO() const
            {
                return vao;
            }

            GLuint GetVBO() const
            {
                return vbo;
            }

            GLuint GetIBO() const
            {
                return ibo;
            }

            unsigned int GetElementsSize() const
            {
                return ibOffset / sizeof(unsigned int);
            }

        private:
            GLuint vao;

            GLuint vbo;

            GLuint ibo;

            GLintptr vbOffset = 0;
            GLintptr ibOffset = 0;
    };
}