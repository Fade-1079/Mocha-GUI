#pragma once
#include "TabControls.h"

namespace TabMovement
{
struct State
{
    bool Static_Fly = false;
    bool Dynamic_Fly = false;
    bool Force_Static_Fly = false;
    bool Packet_Fly = false;
    bool Horizontal = false;
    bool Vertical = false;
    bool Lock_Y_Axis = false;
    float Vertical_Speed = 50.0f;
    float Horizontal_Speed = 50.0f;
    float Gravity_X = 50.0f;
    float Gravity_Y = 50.0f;
    float Gravity_Z = 50.0f;
    bool Set_gravity = false;
    bool Get_Gravity = false;
    bool Restore_Gravity = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Movement");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("Static Fly", state.Static_Fly);
    MochaUI::Toggle("Dynamic Fly", state.Dynamic_Fly);
    MochaUI::Toggle("Force Static Fly", state.Force_Static_Fly);
    MochaUI::Toggle("Packet Fly", state.Packet_Fly);
    MochaUI::Toggle("Horizontal", state.Horizontal);
    MochaUI::Toggle("Vertical", state.Vertical);
    MochaUI::Toggle("Lock Y-Axis", state.Lock_Y_Axis);
    MochaUI::Section("Sliders");
    MochaUI::Slider("Vertical Speed", state.Vertical_Speed);
    MochaUI::Slider("Horizontal Speed", state.Horizontal_Speed);
    MochaUI::Slider("Gravity X", state.Gravity_X);
    MochaUI::Slider("Gravity Y", state.Gravity_Y);
    MochaUI::Slider("Gravity Z", state.Gravity_Z);
    MochaUI::Section("Buttons");
    MochaUI::Button("Set gravity", state.Set_gravity);
    MochaUI::Status(state.Set_gravity);
    MochaUI::Button("Get Gravity", state.Get_Gravity);
    MochaUI::Status(state.Get_Gravity);
    MochaUI::Button("Restore Gravity", state.Restore_Gravity);
    MochaUI::Status(state.Restore_Gravity);
}
};
