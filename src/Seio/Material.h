#pragma once

#include <string>

#include "glad/glad.h"

struct Material
{
    GLuint shaderID;
    std::string textureName;

    bool operator==(const Material& other) const
    {
        return shaderID == other.shaderID && textureName == other.textureName;
    }
};

inline void hash_combine(std::size_t& seed, std::size_t value)
{
    seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct MaterialHash
{
    std::size_t operator()(const Material& m) const
    {
        std::size_t seed = 0;
        hash_combine(seed, std::hash<GLuint>{}(m.shaderID));
        hash_combine(seed, std::hash<std::string>{}(m.textureName));

        return seed;
    }
};



