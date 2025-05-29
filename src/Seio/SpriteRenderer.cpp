#include "SpriteRenderer.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>

#include "GameObject.h"
#include "Global.h"
#include "ShaderManager.h"
#include "imgui.h"

namespace fs = std::filesystem;

std::vector<fs::path> GetFilesWithExtensions(const fs::path& directory, const std::vector<std::string>& extensions) {
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

    void SpriteRenderer::OnDrawImGui()
    {
        // TODO: 나중에 Component에서 자동으로 클래스명 받아와서 TreeNode를 만들어주는 방식으로 수정해야함
        if (ImGui::TreeNodeEx("Sprite Renderer", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_DefaultOpen))
        {
            auto texID = RenderSystem::Instance().GetOrCreateTexture(material.textureName);
            ImGui::Image(texID, {250, 200}, ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f));

            ImGui::Text("Texture Name: %s", material.textureName.c_str());
            ImGui::SameLine();

            if (ImGui::Button("Select"))
                ImGui::OpenPopup("Texture Select Popup");

            auto center = ImGui::GetMainViewport()->GetCenter();
            ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

            if (ImGui::BeginPopup("Texture Select Popup"))
            {
                ImGui::SeparatorText("Select File");

                auto texturePath = std::filesystem::path(__FILE__).parent_path() / ".." / ".." / "resources" / "textures";
                auto paths = GetFilesWithExtensions(texturePath, { ".png", ".jpg", ".jpeg" });
                sort(paths.begin(), paths.end());

                for (auto path : paths)
                {
                    if (ImGui::Selectable(path.filename().c_str()))
                        material.textureName = path.filename();
                }

                ImGui::EndPopup();
            }

            ImGui::TreePop();
        }
    }
}