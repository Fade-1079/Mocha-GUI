#pragma once
#include "TabControls.h"

namespace TabTestMenu
{
struct State
{
    bool Watch_Menu_Test = false;
    bool Object_Explorer = false;
    bool Hook_test_controls = false;
    float Time_scale = 50.0f;
    bool Notification_Test = false;
    bool Refresh_Objects = false;
    bool Clear_Objects = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Test Menu");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("Watch Menu Test", state.Watch_Menu_Test);
    MochaUI::Toggle("Object Explorer", state.Object_Explorer);
    MochaUI::Toggle("Hook test controls", state.Hook_test_controls);
    MochaUI::Section("Sliders");
    MochaUI::Slider("Time scale", state.Time_scale);
    MochaUI::Section("Buttons");
    MochaUI::Button("Notification Test", state.Notification_Test);
    MochaUI::Status(state.Notification_Test);
    MochaUI::Button("Refresh Objects", state.Refresh_Objects);
    MochaUI::Status(state.Refresh_Objects);
    MochaUI::Button("Clear Objects", state.Clear_Objects);
    MochaUI::Status(state.Clear_Objects);
}
};
