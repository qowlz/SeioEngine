#include "Transform.h"

#include "imgui.h"
#include "ImGuiDrawUtils.h"

namespace Seio
{
    void Transform::OnDrawImGui()
    {
        if (ImGui::TreeNodeEx("Transform", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGuiDrawUtils::DrawFloatVec3("position", this->position);

            ImGuiDrawUtils::DrawFloatVec3("rotation", this->rotation);

            ImGuiDrawUtils::DrawFloatVec3("scale", this->scale);

            ImGui::TreePop();
        }
    }
}