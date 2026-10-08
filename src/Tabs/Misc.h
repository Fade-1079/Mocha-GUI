#pragma once
#include "TabControls.h"

namespace TabMisc
{
struct State
{
    bool FOV_Slider = false;
    bool Zoom_Toggle = false;
    bool Object_Orbit = false;
    bool Camera_TMZ_Mode = false;
    bool Clothing = false;
    bool Watch_Menu_Prototype = false;
    float FOV = 50.0f;
    float Zoom_FOV = 50.0f;
    float Object_Distance = 50.0f;
    float Object_Height = 50.0f;
    float Speed = 50.0f;
    float Size = 50.0f;
    bool Spawn_Orbit_Object = false;
    bool Send_GYATT = false;
    bool Broadcast_Announcement = false;
    bool Delete_All_Objects = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Misc");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("FOV Slider", state.FOV_Slider);
    MochaUI::Toggle("Zoom Toggle", state.Zoom_Toggle);
    MochaUI::Toggle("Object Orbit", state.Object_Orbit);
    MochaUI::Toggle("Camera TMZ Mode", state.Camera_TMZ_Mode);
    MochaUI::Toggle("Clothing", state.Clothing);
    MochaUI::Toggle("Watch Menu Prototype", state.Watch_Menu_Prototype);
    MochaUI::Section("Sliders");
    MochaUI::Slider("FOV", state.FOV);
    MochaUI::Slider("Zoom FOV", state.Zoom_FOV);
    MochaUI::Slider("Object Distance", state.Object_Distance);
    MochaUI::Slider("Object Height", state.Object_Height);
    MochaUI::Slider("Speed", state.Speed);
    MochaUI::Slider("Size", state.Size);
    MochaUI::Section("Buttons");
    MochaUI::Button("Spawn Orbit Object", state.Spawn_Orbit_Object);
    MochaUI::Status(state.Spawn_Orbit_Object);
    MochaUI::Button("Send GYATT", state.Send_GYATT);
    MochaUI::Status(state.Send_GYATT);
    MochaUI::Button("Broadcast Announcement", state.Broadcast_Announcement);
    MochaUI::Status(state.Broadcast_Announcement);
    MochaUI::Button("Delete All Objects", state.Delete_All_Objects);
    MochaUI::Status(state.Delete_All_Objects);
}
};
