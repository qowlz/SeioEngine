#include "IO.h"

#include <iostream>

namespace fs = std::filesystem;

namespace Seio::IO
{
    std::vector<fs::path> GetFilesWithExtensions(const fs::path& directory, const std::vector<std::string>& extensions)
    {
        std::vector<fs::path> result;

        if (!fs::exists(directory) || !fs::is_directory(directory)) {
            std::cerr << "Invalid directory: " << directory << std::endl;
            return result;
        }

        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                std::string ext = entry.path().extension().string();

                // 소문자로 변환하여 확장자 비교 (대소문자 구분 없이)
                std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

                for (const auto& targetExt : extensions) {
                    std::string loweredTarget = targetExt;
                    std::transform(loweredTarget.begin(), loweredTarget.end(), loweredTarget.begin(), ::tolower);

                    if (ext == loweredTarget) {
                        result.push_back(entry.path());
                        break;
                    }
                }
            }
        }

        return result;
    }
}