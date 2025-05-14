#include "RenderSystem.h"

#include "Vertex.h"

namespace Seio
{
    void RenderSystem::Render()
    {
        for (const auto& [shaderID, batch] : batchMap)
        {
            glUseProgram(shaderID);

            glBindVertexArray(batch.GetVAO());
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, batch.GetIBO());

            glDrawElements(GL_TRIANGLES, batch.GetElementsSize(), GL_UNSIGNED_INT, 0);
        }

        batchMap.clear();
    }

    void RenderSystem::RequestDrawQuad(GLuint textureID, GLuint shaderID, glm::mat4 mvp)
    {
        if (batchMap.find(shaderID) == batchMap.end())
            batchMap[shaderID] = std::move(Batch());

        Vertex vertices[]
        {
            // positions                                              // texture coords
            {{ glm::vec3(mvp * glm::vec4(0.5f,  0.5f, 0.0f, 1.0f)) }, { 1.0f, 1.0f }}, // top right
            {{ glm::vec3(mvp * glm::vec4(0.5f, -0.5f, 0.0f, 1.0f)) }, { 1.0f, 0.0f }}, // bottom right
            {{ glm::vec3(mvp * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f)) }, { 0.0f, 0.0f }}, // bottom left
            {{ glm::vec3(mvp * glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f)) }, { 0.0f, 1.0f }} // top left
        };
        batchMap[shaderID].AppendVertices(vertices, 4);

        unsigned int indices[]
        {
            0, 1, 3,   // first triangle
            1, 2, 3    // second triangle
        };
        batchMap[shaderID].AppendIndices(indices, 6);
    }
}