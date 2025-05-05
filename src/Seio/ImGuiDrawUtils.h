#pragma once

#include "imgui.h"

#include <glm/glm.hpp>

namespace ImGuiDrawUtils
{
    void DrawFloatVec3(const char* name, glm::vec3& v)
    {
        ImGui::Text("%s", name); ImGui::SameLine(100);

        ImGui::Text("x"); ImGui::SameLine();
        ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat("##pos/x", &v.x);
        ImGui::SameLine();

        ImGui::Text("y"); ImGui::SameLine();
        ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat("##pos/y", &v.y);
        ImGui::SameLine();

        ImGui::Text("z"); ImGui::SameLine();
        ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat("##pos/z", &v.z);
    }
}