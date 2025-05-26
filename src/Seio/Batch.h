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

            void Clear();

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

            unsigned int GetElementCount() const
            {
                return ibOffset / sizeof(unsigned int);
            }

            unsigned int GetVertexCount() const
            {
                return vbOffset / sizeof(Vertex);
            }

        private:
            GLuint vao = 0, vbo = 0, ibo = 0;

            GLintptr vbOffset = 0;
            GLintptr ibOffset = 0;

            // 상수 모음

            static constexpr unsigned int maxVertexCount = 1000;
            static constexpr GLsizeiptr vertexBufferMaxSize = sizeof(Vertex) * maxVertexCount;
            static constexpr GLsizeiptr indexBufferMaxSize = maxVertexCount / 4 * 6 * sizeof(unsigned int); // quad는 4개의 버텍스를 요구하고, quad 1개 당 6개의 indices가 필요함
    };
}