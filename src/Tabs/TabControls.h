#pragma once
#include "../../Dependencies/ImGui/imgui.h"
#include "../../Dependencies/ImGui/addons/imgui_addons.h"

namespace MochaUI
{
inline void Header(const char* title)
{
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts.size() > 1 ? ImGui::GetIO().Fonts->Fonts[1] : ImGui::GetFont());
    ImGui::TextDisabled("%s", title);
    ImGui::PopFont();
    ImGui::Separator();
}

inline void Toggle(const char* label, bool& value)
{
    ImAdd::ToggleButtonClassic(label, &value);
}

inline void Slider(const char* label, float& value, float min = 0.0f, float max = 100.0f)
{
    ImAdd::SliderFloat(label, &value, min, max, -0.1f);
}

inline void Button(const char* label, bool& value)
{
    if (ImAdd::Button(label, ImVec2(-0.1f, 0.0f)))
        value = !value;
}

inline void Status(bool value)
{
    ImGui::SameLine();
    ImGui::TextDisabled(value ? "On" : "Off");
}

inline void Section(const char* title)
{
    ImGui::Spacing();
    ImGui::TextDisabled("%s", title);
    ImGui::Spacing();
}
}
