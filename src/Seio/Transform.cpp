#include "Transform.h"

#include "imgui.h"

namespace Seio
{
    void Transform::OnDrawImGui()
    {
        if (ImGui::TreeNodeEx("Transform", ImGuiTreeNodeFlags_Framed))
        {
            // TODO: 만들긴 했는데 개복잡해서 table을 쓰는방식이 나을지도?
            ImGui::Text("position"); ImGui::SameLine(100);

            ImGui::Text("x"); ImGui::SameLine();
            ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat("##pos/x", &this->position.x);
            ImGui::SameLine();

            ImGui::Text("y"); ImGui::SameLine();
            ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat("##pos/y", &this->position.y);
            ImGui::SameLine();

            ImGui::Text("z"); ImGui::SameLine();
            ImGui::SetNextItemWidth(50.0f); ImGui::InputFloat("##pos/z", &this->position.z);

            ImGui::TreePop();
        }
    }
}