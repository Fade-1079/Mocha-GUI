#pragma once
#include "TabControls.h"

namespace TabPlayerList
{
struct State
{
    bool Player_selection = false;
    bool Player_information = false;
    bool Display_details = false;
    float Player_scale = 50.0f;
    bool Refresh_Players = false;
    bool Clear_Selection = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Player List");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("Player selection", state.Player_selection);
    MochaUI::Toggle("Player information", state.Player_information);
    MochaUI::Toggle("Display details", state.Display_details);
    MochaUI::Section("Sliders");
    MochaUI::Slider("Player scale", state.Player_scale);
    MochaUI::Section("Buttons");
    MochaUI::Button("Refresh Players", state.Refresh_Players);
    MochaUI::Status(state.Refresh_Players);
    MochaUI::Button("Clear Selection", state.Clear_Selection);
    MochaUI::Status(state.Clear_Selection);
}
};
