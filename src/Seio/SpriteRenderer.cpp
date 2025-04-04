#include "SpriteRenderer.h"

#include <vector>

namespace Seio
{
    SpriteRenderer::SpriteRenderer(const std::string &texturePath)
        : mainTexture { texturePath }
        , shader { "sprite-default.vert", "sprite-default.frag" }
    {
        this->vao.Bind();

        std::vector<float> vertices
        {
            // positions          // texture coords
            0.5f,  0.5f, 0.0f,    1.0f, 1.0f,  // top right
            0.5f, -0.5f, 0.0f,    1.0f, 0.0f,  // bottom right
           -0.5f, -0.5f, 0.0f,    0.0f, 0.0f,  // bottom left
           -0.5f,  0.5f, 0.0f,    0.0f, 1.0f   // top left
        };
        this->vbo.Bind();
        this->vbo.Write(vertices);

        this->vao.SetAttributePointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        this->vao.EnableAttribute(0);

        this->vao.SetAttributePointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        this->vao.EnableAttribute(1);

        this->vbo.Unbind();

        std::vector<unsigned int> indices
        {
            0, 1, 3,   // first triangle
            1, 2, 3    // second triangle
        };
        this->ibo.Bind();
        this->ibo.Write(indices);
        this->ibo.UnBind();
    }

    void SpriteRenderer::Draw()
    {
        this->shader.Use();
        this->shader.SetInt("MainTex", 0);
        this->mainTexture.Bind(GL_TEXTURE0);

        this->vao.Bind();
        this->ibo.Bind();

        // FIXME: indices의 사이즈를 어디선가 받아오면 베스트일듯?
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}