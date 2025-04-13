#pragma once

#include "Renderer.h"

#include <string>

#include "GL/Texture2D.h"
#include "GL/VertexArrayObject.h"
#include "GL/VertexBufferObject.h"
#include "GL/IndexBufferObject.h"
#include "GL/Shader.h"

namespace Seio
{
    /// @brief sprite를 화면상에 그려주는 역할을 하는 클래스
    class SpriteRenderer : public Renderer
    {
    public:
        SpriteRenderer() = delete;

        SpriteRenderer(const std::string &texturePath);

        void Draw(glm::mat4 mvp) override;

    private:
        Texture2D mainTexture;
        Shader shader;

        VertexArrayObject vao;
        VertexBufferObject vbo;
        IndexBufferObject ibo;

    };
}