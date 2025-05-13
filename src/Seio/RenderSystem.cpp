#include "RenderSystem.h"

namespace Seio
{
    RenderSystem::RenderSystem()
    {
        vao.Bind();

        vbo.Bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 1000, nullptr, GL_DYNAMIC_DRAW); // FIXME: 일단 버퍼의 크기를 정점 1000개정도로 잡음. 추후에 동적으로 성장하는 방식으로 바꿔야 함.

        vao.SetAttributePointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (const void*) offsetof(Vertex, pos));
        vao.EnableAttribute(0);

        vao.SetAttributePointer(1, 2, GL_FLOAT, false, sizeof(Vertex), (const void*) offsetof(Vertex, texCoord));
        vao.EnableAttribute(1);

        ibo.Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 250 * 6, nullptr, GL_DYNAMIC_DRAW); // quad가 최대 250개 생성될 수 있고, quad 1개 당 6개의 indices가 필요함
    }

    void RenderSystem::Render()
    {
        vao.Bind();
        ibo.Bind();

        unsigned int size = indexBufferOffset / sizeof(unsigned int);
        glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

        vertexBufferOffset = 0;
        indexBufferOffset = 0;
    }

    void RenderSystem::RequestDrawQuad(GLuint textureID, GLuint shaderID, glm::mat4 mvp)
    {
        Vertex vertices[]
        {
            // positions                                              // texture coords
            {{ glm::vec3(mvp * glm::vec4(0.5f,  0.5f, 0.0f, 1.0f)) }, { 1.0f, 1.0f }}, // top right
            {{ glm::vec3(mvp * glm::vec4(0.5f, -0.5f, 0.0f, 1.0f)) }, { 1.0f, 0.0f }}, // bottom right
            {{ glm::vec3(mvp * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f)) }, { 0.0f, 0.0f }}, // bottom left
            {{ glm::vec3(mvp * glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f)) }, { 0.0f, 1.0f }} // top left
        };

        // FIXME: 임시 코드
        glUseProgram(shaderID);

        unsigned int verticesSize = sizeof(Vertex) * 4;

        vbo.Bind();
        glBufferSubData(GL_ARRAY_BUFFER, vertexBufferOffset, verticesSize, vertices);
        vertexBufferOffset += verticesSize;

        unsigned int indexOrder = indexBufferOffset / sizeof(unsigned int);
        unsigned int indices[]
        {
            indexOrder, indexOrder + 1, indexOrder + 3,   // first triangle
            indexOrder + 1, indexOrder + 2, indexOrder + 3    // second triangle
        };
        unsigned int indicesSize = sizeof(unsigned int) * 6;

        ibo.Bind();
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, indexBufferOffset, indicesSize, indices);
        indexBufferOffset += indicesSize;
    }
}