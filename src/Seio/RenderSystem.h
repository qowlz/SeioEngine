#pragma once

#include <unordered_map>
#include <string>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

#include "Singleton.h"
#include "GL/VertexArrayObject.h"
#include "GL/VertexBufferObject.h"
#include "GL/IndexBufferObject.h"
#include "Batch.h"
#include "GL/Texture2D.h"
#include "Material.h"

namespace Seio
{
    class RenderSystem : public Singleton<RenderSystem>
    {
        public:
            RenderSystem() = default;

            void Render();

            void RequestDrawQuad(const Material& mat, glm::mat4 mvp);

        private:
            std::unordered_map<Material, Batch, MaterialHash> batchMap;

            std::unordered_map<std::string, Texture2D> textureMap;
    };
}