#pragma once

#include <vector>
#include <filesystem>

namespace Seio::IO
{
    std::vector<std::filesystem::path> GetFilesWithExtensions(const std::filesystem::path& directory, const std::vector<std::string>& extensions);
}
