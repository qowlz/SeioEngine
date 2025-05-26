#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "glad/glad.h"

#include "Singleton.h"
#include "GL/Shader.h"

namespace Seio
{
    class ShaderManager : public Singleton<ShaderManager>
    {
        public:
            /// @brief Get or create shader program
            /// @param shaderName
            /// @return Shader program id
            GLuint GetOrCreate(const std::string& shaderName);

        private:
            std::unordered_map<std::string, std::unique_ptr<Shader>> shaderMap;
    };
}