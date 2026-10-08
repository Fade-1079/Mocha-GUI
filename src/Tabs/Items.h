#pragma once
#include "TabControls.h"

namespace TabItems
{
struct State
{
    bool Item_browser = false;
    bool Favorites = false;
    bool Preview = false;
    float Position_X = 50.0f;
    float Position_Y = 50.0f;
    float Position_Z = 50.0f;
    bool Spawn_Item = false;
    bool Refresh_Items = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Items");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("Item browser", state.Item_browser);
    MochaUI::Toggle("Favorites", state.Favorites);
    MochaUI::Toggle("Preview", state.Preview);
    MochaUI::Section("Sliders");
    MochaUI::Slider("Position X", state.Position_X);
    MochaUI::Slider("Position Y", state.Position_Y);
    MochaUI::Slider("Position Z", state.Position_Z);
    MochaUI::Section("Buttons");
    MochaUI::Button("Spawn Item", state.Spawn_Item);
    MochaUI::Status(state.Spawn_Item);
    MochaUI::Button("Refresh Items", state.Refresh_Items);
    MochaUI::Status(state.Refresh_Items);
}
};
