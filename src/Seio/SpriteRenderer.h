#pragma once

#include "Renderer.h"

#include <string>

#include "Material.h"
#include "GL/Texture2D.h"
#include "GL/Shader.h"
#include "RenderSystem.h"


namespace Seio
{
    /// @brief sprite를 화면상에 그려주는 역할을 하는 클래스
    class SpriteRenderer : public Component
    {
    public:
        SpriteRenderer() = delete;

        SpriteRenderer(const std::string& textureName);

        void Update(float dt) override;

        void OnDrawImGui() override;

    private:
        Material material;

    };
}