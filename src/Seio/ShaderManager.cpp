#include "ShaderManager.h"

namespace Seio
{
    GLuint ShaderManager::GetOrCreate(const std::string& shaderName)
    {
        if (shaderMap.find(shaderName) == shaderMap.end())
            shaderMap.insert({shaderName, std::make_unique<Shader>(shaderName)});

        return shaderMap[shaderName].get()->GetID();
    }
}