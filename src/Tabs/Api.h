#pragma once
#include "TabControls.h"

namespace TabApi
{
struct State
{
    bool Toggle_Chai = false;
    bool Toggle_Swaps = false;
    bool Debug_Swapped = false;
    bool Debug_All = false;
    bool Request_Signature = false;
    bool Refresh_Config = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Api");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("Toggle Chai", state.Toggle_Chai);
    MochaUI::Toggle("Toggle Swaps", state.Toggle_Swaps);
    MochaUI::Toggle("Debug Swapped", state.Debug_Swapped);
    MochaUI::Toggle("Debug All", state.Debug_All);
    MochaUI::Toggle("Request Signature", state.Request_Signature);
    MochaUI::Section("Buttons");
    MochaUI::Button("Refresh Config", state.Refresh_Config);
    MochaUI::Status(state.Refresh_Config);
}
};
