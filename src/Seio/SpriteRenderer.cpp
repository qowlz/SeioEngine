#include "SpriteRenderer.h"

#include <vector>
#include <iostream>

#include "GameObject.h"
#include "Global.h"
#include "ShaderManager.h"

namespace Seio
{
    SpriteRenderer::SpriteRenderer(const std::string& textureName)
        : material { ShaderManager::Instance().GetOrCreate("sprite-default"), textureName}
    {
        std::cout << "SPRITE RENDERER::";
        std::cout << "mat shader id: " << material.shaderID << ", " << "texture Name: " << material.textureName << std::endl;
    }

    void SpriteRenderer::Update(float dt)
    {
        // TODO: 현재 코드는 transform이 무조건 spriteRenderer보다 먼저 업데이트 된다는 전제하에 작성 되었다.
        // TODO: 추후에 필요하다면, 각 컴포넌트에 execution order같은 요소를 추가해서 항상 render관련 컴포넌트는 마지막에 업데이트된다는것을 보장하는게 좋을듯.
        auto mvp = mainCam->GetProjectionM() * mainCam->GetViewM() * owner->GetTransform()->GetMatrix();
        RenderSystem::Instance().RequestDrawQuad(material, mvp);
    }
}