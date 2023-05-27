#pragma once

#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

class FileSystem
{
public:
    static fs::path getBasePath()
    {
        return fs::canonical(fs::path("../"));
    }

    static fs::path getResourcePath(const char* resourceName = "")
    {
        return getBasePath() / "resources/" / resourceName;
    }

    static fs::path getShaderPath(const char* shaderName = "")
    {
        return getBasePath() / "src/shaders" / shaderName;
    }
};