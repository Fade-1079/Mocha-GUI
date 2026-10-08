#pragma once
#include "TabControls.h"

namespace TabConfigs
{
struct State
{
    bool Auto_load_config = false;
    bool Save_on_exit = false;
    bool Save_Config = false;
    bool Load_Config = false;
    bool Refresh_Config = false;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Configs");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("Auto-load config", state.Auto_load_config);
    MochaUI::Toggle("Save on exit", state.Save_on_exit);
    MochaUI::Section("Buttons");
    MochaUI::Button("Save Config", state.Save_Config);
    MochaUI::Status(state.Save_Config);
    MochaUI::Button("Load Config", state.Load_Config);
    MochaUI::Status(state.Load_Config);
    MochaUI::Button("Refresh Config", state.Refresh_Config);
    MochaUI::Status(state.Refresh_Config);
}
};
