#pragma once

#include <string>
#include <filesystem>

#include "imgui.h"
#include <glm/glm.hpp>

#include "IO.h"

namespace ImGuiDrawUtils
{
    inline void DrawFloatVec3(std::string name, glm::vec3& v)
    {
        ImGui::Text("%s", name.c_str()); ImGui::SameLine(100);

        ImGui::Text("x"); ImGui::SameLine();

        std::string xLabel = "##" + name + "/x";
        ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat(xLabel.c_str(), &v.x); ImGui::SameLine();

        ImGui::Text("y"); ImGui::SameLine();

        std::string yLabel = "##" + name + "/y";
        ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat(yLabel.c_str(), &v.y); ImGui::SameLine();

        ImGui::Text("z"); ImGui::SameLine();

        std::string zLabel = "##" + name + "/z";
        ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat(zLabel.c_str(), &v.z);
    }

    inline void DrawFileSelectPopup(const std::string& name, const std::filesystem::path& path, const std::function<void(const std::string&)>& onSelect) // callback을 넣어줘야한다.
    {
        auto center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

        if (ImGui::BeginPopup(name.c_str()))
        {
            ImGui::SeparatorText("Select File");

            auto paths = Seio::IO::GetFilesWithExtensions(path, { ".png", ".jpg", ".jpeg" });
            sort(paths.begin(), paths.end());

            for (auto path : paths)
            {
                if (ImGui::Selectable(path.filename().c_str()))
                    onSelect(path.filename());
            }

            ImGui::EndPopup();
        }
    }
}