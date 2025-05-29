#include "RenderSystem.h"

#include "Vertex.h"
#include "ShaderManager.h"

#include <iostream>

void PrintVBO(GLuint vbo, int count) {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // 데이터 받을 공간 할당
    std::vector<Seio::Vertex> vertices(count);

    // GPU → CPU로 데이터 복사
    glGetBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Seio::Vertex), vertices.data());

    // 출력
    std::cout << "VBO Contents: " << std::endl;
    for (int i = 0; i < count / 4; i++)
    {
        std::cout << "\tquad " << i + 1 << ": " << std::endl;

        for (int j = 0; j < 4; j++)
        {
            std::cout << "\t\tvertex " << i + 1 << ": ";
            int idx = 4 * i + j;
            std::cout << vertices[idx].pos.x << ' ' << vertices[idx].pos.y << ' ' << vertices[idx].pos.z << std::endl;
        }
    }

    std::cout << std::endl;
}

void PrintIBO(GLuint ibo, int count) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    // 데이터 받을 공간 할당
    std::vector<unsigned int> indices(count);

    // GPU → CPU로 데이터 복사
    glGetBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices.size() * sizeof(unsigned int), indices.data());

    // 출력
    std::cout << "IBO Contents: ";
    for (GLuint index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
}

namespace Seio
{
    void RenderSystem::Render()
    {
        for (auto& [mat, batch] : batchMap)
        {
            glUseProgram(mat.shaderID);

            glUniform1i(glGetUniformLocation(mat.shaderID, "MainTex"), 0);

            auto it = textureMap.find(mat.textureName);
            if (it != textureMap.end())
                it->second.Bind(GL_TEXTURE0);

            glBindVertexArray(batch.GetVAO());
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, batch.GetIBO());

            // PrintVBO(batch.GetVBO(), 8);
            // PrintIBO(batch.GetIBO(), batch.GetElementCount());

            glDrawElements(GL_TRIANGLES, batch.GetElementCount(), GL_UNSIGNED_INT, 0);

            batch.Clear();
        }
    }

    void RenderSystem::RequestDrawQuad(const Material& mat, glm::mat4 mvp)
    {
        GetOrCreateTexture(mat.textureName);

        unsigned int indexOffset = batchMap[mat].GetVertexCount();
        unsigned int indices[]
        {
            0 + indexOffset, 1 + indexOffset, 3 + indexOffset,   // first triangle
            1 + indexOffset, 2 + indexOffset, 3 + indexOffset   // second triangle
        };
        batchMap[mat].AppendIndices(indices, 6);

        Vertex vertices[]
        {
            // positions                                              // texture coords
            {{ glm::vec3(mvp * glm::vec4(0.5f,  0.5f, 0.0f, 1.0f)) }, { 1.0f, 1.0f }}, // top right
            {{ glm::vec3(mvp * glm::vec4(0.5f, -0.5f, 0.0f, 1.0f)) }, { 1.0f, 0.0f }}, // bottom right
            {{ glm::vec3(mvp * glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f)) }, { 0.0f, 0.0f }}, // bottom left
            {{ glm::vec3(mvp * glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f)) }, { 0.0f, 1.0f }} // top left
        };
        batchMap[mat].AppendVertices(vertices, 4);
    }

    GLuint RenderSystem::GetOrCreateTexture(const std::string& textureName)
    {
        auto [it, inserted] = textureMap.try_emplace(textureName, textureName);

        return it->second.GetID();
    }
}