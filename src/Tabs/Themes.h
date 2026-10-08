#pragma once
#include "TabControls.h"

namespace TabThemes
{
inline int selected = 3;

inline void Render()
{
    MochaUI::Header("Themes");
    const char* names[] = { "Dark Blue", "Dark Purple", "Dark", "Mocha", "Red" };
    for (int i = 0; i < 5; ++i)
    {
        if (i)
            ImGui::SameLine();
        ImAdd::RadioFrameColor(names[i], &selected, i, ImAdd::HexToColorVec4(i == 4 ? 0x362323 : i == 3 ? 0x1F1F1F : 0x272727, 1.0f), ImVec2(90, 70));
    }
    ImGui::Spacing();
    ImGui::TextDisabled("Selected: %s", names[selected]);
}
}
