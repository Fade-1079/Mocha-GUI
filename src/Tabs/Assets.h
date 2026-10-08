#pragma once
#include "TabControls.h"

namespace TabAssets
{
struct State
{
    bool Asset_browser = false;
    bool Favorites = false;
    bool Preview = false;
    float Position_X = 50.0f;
    float Position_Y = 50.0f;
    float Position_Z = 50.0f;
    bool Spawn_Asset = false;
    bool Refresh_Assets = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Assets");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("Asset browser", state.Asset_browser);
    MochaUI::Toggle("Favorites", state.Favorites);
    MochaUI::Toggle("Preview", state.Preview);
    MochaUI::Section("Sliders");
    MochaUI::Slider("Position X", state.Position_X);
    MochaUI::Slider("Position Y", state.Position_Y);
    MochaUI::Slider("Position Z", state.Position_Z);
    MochaUI::Section("Buttons");
    MochaUI::Button("Spawn Asset", state.Spawn_Asset);
    MochaUI::Status(state.Spawn_Asset);
    MochaUI::Button("Refresh Assets", state.Refresh_Assets);
    MochaUI::Status(state.Refresh_Assets);
}
};
