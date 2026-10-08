#pragma once
#include <Windows.h>
#include <d3d11.h>
#include "../Dependencies/ImGui/imgui.h"
#include "../Dependencies/ImGui/imgui_impl_dx11.h"
#include "../Dependencies/ImGui/imgui_impl_win32.h"
#include "../Dependencies/ImGui/freetype/imgui_freetype.h"
#include "../Dependencies/ImGui/addons/imgui_addons.h"
#include "Textures.h"

class CGui
{
public:
    explicit CGui(CTextures* textures);
    bool Initialize(HWND hwnd, ID3D11Device* device, ID3D11DeviceContext* context);
    void Shutdown();
    void PreRender();
    bool MsgProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

private:
    void ApplyTheme();
    void RenderPage();
    const char* TabName(int id) const;
    const char* TabDescription(int id) const;
    ImTextureID TabIcon(int id, bool filled) const;

    CTextures* m_textures{};
    HWND m_hwnd{};
    ImFont* m_mainFont{};
    ImFont* m_bigFont{};
    int m_selectedPage{};
    int m_theme{3};
    bool m_open{true};
};
