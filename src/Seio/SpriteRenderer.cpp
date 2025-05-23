#include "SpriteRenderer.h"

#include <vector>
#include <iostream>

#include "GameObject.h"
#include "Global.h"

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

    void SpriteRenderer::Draw(glm::mat4 mvp)
    {
        this->shader.Use();

        // Bind texture
        this->shader.SetInt("MainTex", 0);
        this->mainTexture.Bind(GL_TEXTURE0);

        this->shader.SetMatrix4f("mvp", mvp);

        this->vao.Bind();
        this->ibo.Bind();

        // FIXME: indices의 사이즈를 어디선가 받아오면 베스트일듯?
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void SpriteRenderer::Update(float dt)
    {
        // TODO: 현재 코드는 transform이 무조건 spriteRenderer보다 먼저 업데이트 된다는 전제하에 작성 되었다.
        // TODO: 추후에 필요하다면, 각 컴포넌트에 execution order같은 요소를 추가해서 항상 render관련 컴포넌트는 마지막에 업데이트된다는것을 보장하는게 좋을듯.
        auto mvp = mainCam->GetProjectionM() * mainCam->GetViewM() * owner->GetTransform()->GetMatrix();
        RenderSystem::Instance().RequestDrawQuad(mainTexture.GetID(), shader.GetID(), mvp);

        // std::cout << "!!" << std::endl;
    }
}