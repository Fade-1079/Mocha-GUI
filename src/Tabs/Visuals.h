#pragma once
#include "TabControls.h"

namespace TabVisuals
{
struct State
{
    bool ESP = false;
    bool Skeleton_Enabled = false;
    bool Render_Self = false;
    bool Gradient_Color = false;
    bool Rainbow_Color = false;
    bool Distance_Color = false;
    bool Fade = false;
    bool Tracer_Enabled = false;
    bool Box_Enabled = false;
    bool Box_Outline = false;
    bool Name_Tags = false;
    bool Chams = false;
    bool Watermark = false;
    bool Particles = false;
    float Line_Thickness = 50.0f;
    float Gradient_Speed = 50.0f;
    float Min_Distance = 50.0f;
    float Max_Distance = 50.0f;
    float Fade_Distance = 50.0f;
    float Rounding = 50.0f;
    float Padding_X = 50.0f;
    float Padding_Y = 50.0f;
};

inline State state{};

inline void Render()
{
    MochaUI::Header("Visuals");
    MochaUI::Section("Toggles");
    MochaUI::Toggle("ESP", state.ESP);
    MochaUI::Toggle("Skeleton Enabled", state.Skeleton_Enabled);
    MochaUI::Toggle("Render Self", state.Render_Self);
    MochaUI::Toggle("Gradient Color", state.Gradient_Color);
    MochaUI::Toggle("Rainbow Color", state.Rainbow_Color);
    MochaUI::Toggle("Distance Color", state.Distance_Color);
    MochaUI::Toggle("Fade", state.Fade);
    MochaUI::Toggle("Tracer Enabled", state.Tracer_Enabled);
    MochaUI::Toggle("Box Enabled", state.Box_Enabled);
    MochaUI::Toggle("Box Outline", state.Box_Outline);
    MochaUI::Toggle("Name Tags", state.Name_Tags);
    MochaUI::Toggle("Chams", state.Chams);
    MochaUI::Toggle("Watermark", state.Watermark);
    MochaUI::Toggle("Particles", state.Particles);
    MochaUI::Section("Sliders");
    MochaUI::Slider("Line Thickness", state.Line_Thickness);
    MochaUI::Slider("Gradient Speed", state.Gradient_Speed);
    MochaUI::Slider("Min Distance", state.Min_Distance);
    MochaUI::Slider("Max Distance", state.Max_Distance);
    MochaUI::Slider("Fade Distance", state.Fade_Distance);
    MochaUI::Slider("Rounding", state.Rounding);
    MochaUI::Slider("Padding X", state.Padding_X);
    MochaUI::Slider("Padding Y", state.Padding_Y);
}
};
