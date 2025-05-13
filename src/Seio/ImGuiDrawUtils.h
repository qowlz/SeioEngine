#pragma once

#include <string>

#include "imgui.h"

#include <glm/glm.hpp>

namespace ImGuiDrawUtils
{
    void DrawFloatVec3(std::string name, glm::vec3& v)
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
}