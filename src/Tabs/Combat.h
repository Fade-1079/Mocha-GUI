#pragma once
#include "TabControls.h"

namespace TabCombat
{
struct State
{
    bool Aimbot = false;
    bool Auto_Weapon_Mods = false;
    bool Fire_Rate = false;
    bool Hitbox_Expander = false;
    bool Health_Override = false;
    bool Rapid_Fire = false;
    bool FOV_Slider = false;
    bool Zoom_Toggle = false;
    float Fov = 50.0f;
    float Aim_Speed = 50.0f;
    float Steps = 50.0f;
    float Zoom_FOV = 50.0f;
    bool Select_Weapon = false;
    bool Clear_Rapid_Fire_Selection = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Combat");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("Aimbot", state.Aimbot);
    MochaUI::Toggle("Auto Weapon Mods", state.Auto_Weapon_Mods);
    MochaUI::Toggle("Fire Rate", state.Fire_Rate);
    MochaUI::Toggle("Hitbox Expander", state.Hitbox_Expander);
    MochaUI::Toggle("Health Override", state.Health_Override);
    MochaUI::Toggle("Rapid Fire", state.Rapid_Fire);
    MochaUI::Toggle("FOV Slider", state.FOV_Slider);
    MochaUI::Toggle("Zoom Toggle", state.Zoom_Toggle);
    MochaUI::Section("Sliders");
    MochaUI::Slider("Fov", state.Fov);
    MochaUI::Slider("Aim Speed", state.Aim_Speed);
    MochaUI::Slider("Steps", state.Steps);
    MochaUI::Slider("Zoom FOV", state.Zoom_FOV);
    MochaUI::Section("Buttons");
    MochaUI::Button("Select Weapon", state.Select_Weapon);
    MochaUI::Status(state.Select_Weapon);
    MochaUI::Button("Clear Rapid Fire Selection", state.Clear_Rapid_Fire_Selection);
    MochaUI::Status(state.Clear_Rapid_Fire_Selection);
}
};
