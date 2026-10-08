#include "Gui.h"
#include <initializer_list>
#include "Tabs/Combat.h"
#include "Tabs/Movement.h"
#include "Tabs/Misc.h"
#include "Tabs/Visuals.h"
#include "Tabs/Exploits.h"
#include "Tabs/PlayerList.h"
#include "Tabs/Assets.h"
#include "Tabs/Items.h"
#include "Tabs/Configs.h"
#include "Tabs/Themes.h"
#include "Tabs/TestMenu.h"
#include "Tabs/AntiExploits.h"
#include "Tabs/Api.h"
#include "../Resources/Fonts/IconsFontAwesome6.h"
#include "../Resources/Fonts/IconsFontAwesome6Brands.h"
#include "../Resources/Fonts/Poppins_Medium.h"
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace
{
enum Theme { DarkBlue, DarkPurple, Dark, Mocha, Red };

void SetPalette(ImGuiStyle& style, unsigned int window, unsigned int popup, unsigned int child, unsigned int accent, unsigned int border, unsigned int textDisabled)
{
    style.Colors[ImGuiCol_WindowBg] = ImAdd::HexToColorVec4(window, 1.0f);
    style.Colors[ImGuiCol_PopupBg] = ImAdd::HexToColorVec4(popup, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImAdd::HexToColorVec4(child, 1.0f);
    style.Colors[ImGuiCol_Text] = ImAdd::HexToColorVec4(0xFFFFFF, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImAdd::HexToColorVec4(textDisabled, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = style.Colors[ImGuiCol_Text];
    style.Colors[ImGuiCol_SliderGrab] = ImAdd::HexToColorVec4(accent, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImAdd::HexToColorVec4(accent, 0.82f);
    style.Colors[ImGuiCol_TextSelectedBg] = style.Colors[ImGuiCol_SliderGrab];
    style.Colors[ImGuiCol_Border] = ImAdd::HexToColorVec4(border, 1.0f);
    style.Colors[ImGuiCol_Separator] = style.Colors[ImGuiCol_Border];
    style.Colors[ImGuiCol_Button] = ImAdd::HexToColorVec4(window, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImAdd::HexToColorVec4(window, 0.75f);
    style.Colors[ImGuiCol_ButtonActive] = ImAdd::HexToColorVec4(window, 0.55f);
    style.Colors[ImGuiCol_FrameBg] = ImAdd::HexToColorVec4(window, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImAdd::HexToColorVec4(window, 0.75f);
    style.Colors[ImGuiCol_FrameBgActive] = ImAdd::HexToColorVec4(window, 0.55f);
    style.Colors[ImGuiCol_Header] = ImAdd::HexToColorVec4(child, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImAdd::HexToColorVec4(child, 0.75f);
    style.Colors[ImGuiCol_HeaderActive] = ImAdd::HexToColorVec4(child, 0.55f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImAdd::HexToColorVec4(child, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImAdd::HexToColorVec4(child, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImAdd::HexToColorVec4(child, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0, 0, 0, 0);
}
}

CGui::CGui(CTextures* textures) : m_textures(textures) {}

bool CGui::Initialize(HWND hwnd, ID3D11Device* device, ID3D11DeviceContext* context)
{
    if (!hwnd || !device || !context)
        return false;

    m_hwnd = hwnd;
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    ImGuiStyle& style = ImGui::GetStyle();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad | ImGuiConfigFlags_NoMouseCursorChange;
    io.IniFilename = nullptr;
    io.LogFilename = nullptr;

    style.TabRounding = 4.0f;
    style.ScrollbarRounding = 9.0f;
    style.WindowRounding = 7.0f;
    style.GrabRounding = 3.0f;
    style.FrameRounding = 3.0f;
    style.PopupRounding = 4.0f;
    style.ChildRounding = 4.0f;

    ImFontConfig fontConfig{};
    fontConfig.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_ForceAutoHint;
    m_mainFont = io.Fonts->AddFontFromMemoryCompressedTTF(Poppins_Medium_compressed_data, Poppins_Medium_compressed_size, 16.0f, &fontConfig, io.Fonts->GetGlyphRangesDefault());
    m_bigFont = io.Fonts->AddFontFromMemoryCompressedTTF(Poppins_Medium_compressed_data, Poppins_Medium_compressed_size, 18.0f, &fontConfig, io.Fonts->GetGlyphRangesDefault());

    static const ImWchar iconsRanges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
    static const ImWchar brandsRanges[] = { ICON_MIN_FAB, ICON_MAX_16_FAB, 0 };
    ImFontConfig iconConfig{};
    iconConfig.MergeMode = true;
    iconConfig.PixelSnapH = true;
    iconConfig.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_ForceAutoHint;
    io.Fonts->AddFontFromMemoryCompressedTTF(fa6_solid_compressed_data, fa6_solid_compressed_size, 16.0f, &iconConfig, iconsRanges);
    io.Fonts->AddFontFromMemoryCompressedTTF(fa_brands_400_compressed_data, fa_brands_400_compressed_size, 16.0f, &iconConfig, brandsRanges);

    ApplyTheme();

    if (!ImGui_ImplWin32_Init(hwnd))
        return false;
    if (!ImGui_ImplDX11_Init(device, context))
    {
        ImGui_ImplWin32_Shutdown();
        return false;
    }

    return true;
}

void CGui::ApplyTheme()
{
    ImGuiStyle& style = ImGui::GetStyle();

    switch (m_theme)
    {
    case DarkBlue:
        SetPalette(style, 0x1D2125, 0x24292E, 0x2B3137, 0x99C8FF, 0x24292E, 0x959DA5);
        break;
    case DarkPurple:
        SetPalette(style, 0x231D2B, 0x2C2336, 0x342B40, 0xB199FF, 0x2C2336, 0xA491AF);
        break;
    case Dark:
        SetPalette(style, 0x1F1F1F, 0x272727, 0x2F2F2F, 0x99C8FF, 0x272727, 0xA2A2A2);
        break;
    case Mocha:
        SetPalette(style, 0x1F1F1F, 0x272727, 0x2F2F2F, 0xD8A1FC, 0x272727, 0xA2A2A2);
        break;
    case Red:
        SetPalette(style, 0x2B1D1D, 0x362323, 0x402B2B, 0xFF9999, 0x362323, 0xAF9191);
        break;
    }
}

void CGui::Shutdown()
{
    if (ImGui::GetCurrentContext())
    {
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();
    }
}

const char* CGui::TabName(int id) const
{
    static const char* names[] = { "Combat", "Movement", "Misc", "Visuals", "Exploits", "Player List", "Assets Spawn", "Items Spawn", "Configs", "Themes", "Test Menu", "Anti-Exploits", "Api" };
    return id >= 0 && id < 13 ? names[id] : "Unknown";
}

const char* CGui::TabDescription(int id) const
{
    static const char* descriptions[] = {
        "\"Ion trust no man without no blicky\" - Latto",
        "Billions must fly!",
        "Collection of various uncategorizable modules.",
        "Shooting at red boxes since 1999.",
        "Supremium watching his bonus fly away.",
        "List of victims, I mean, players. :)",
        "Spawn various prefabs.",
        "Spawn various prefabs. Royalty Required!",
        "Save or load configs. Located in /Mocha folder.",
        "Choose your client theme.",
        "\"Skliggas OnTop\" - Advait 2020",
        "Doing Supremium's job right here.",
        "Chai rewrite when? 10 years."
    };
    return id >= 0 && id < 13 ? descriptions[id] : "";
}

ImTextureID CGui::TabIcon(int id, bool filled) const
{
    if (!m_textures)
        return nullptr;

    switch (id)
    {
    case 0: return filled ? m_textures->tGunFilled : m_textures->tGun;
    case 1: return filled ? m_textures->tWingFilled : m_textures->tWing;
    case 2: return filled ? m_textures->tCubeFilled : m_textures->tCube;
    case 3: return filled ? m_textures->tPencilFilled : m_textures->tPencil;
    case 4: return filled ? m_textures->tWarnFilled : m_textures->tWarnOutlines;
    case 5: return filled ? m_textures->tUsersFilled : m_textures->tUsersOutlines;
    case 6: return filled ? m_textures->tMedkitFilled : m_textures->tMedkitOutlines;
    case 7: return filled ? m_textures->tItemsFilled : m_textures->tItemsOutlines;
    case 8: return filled ? m_textures->tGearFilled : m_textures->tGearOutlines;
    case 9: return filled ? m_textures->tUiFilled : m_textures->tUiOutlines;
    case 10: return filled ? m_textures->tTestFilled : m_textures->tTest;
    case 11: return filled ? m_textures->tToolsFilled : m_textures->tToolsOutlines;
    case 12: return filled ? m_textures->tApiFilled : m_textures->tApiOutlines;
    default: return m_textures->tList;
    }
}

void CGui::RenderPage()
{
    switch (m_selectedPage)
    {
    case 0: TabCombat::Render(); break;
    case 1: TabMovement::Render(); break;
    case 2: TabMisc::Render(); break;
    case 3: TabVisuals::Render(); break;
    case 4: TabExploits::Render(); break;
    case 5: TabPlayerList::Render(); break;
    case 6: TabAssets::Render(); break;
    case 7: TabItems::Render(); break;
    case 8: TabConfigs::Render(); break;
    case 9: TabThemes::Render(); m_theme = TabThemes::selected; break;
    case 10: TabTestMenu::Render(); break;
    case 11: TabAntiExploits::Render(); break;
    case 12: TabApi::Render(); break;
    }
}


void CGui::PreRender()
{
    if (!m_open)
        return;

    ApplyTheme();
    ImGuiStyle& style = ImGui::GetStyle();
    const float sideBarWidth = 144.0f;
    static const ImVec2 menuSize(570.0f, 726.0f);

    ImGui::SetNextWindowSize(menuSize, ImGuiCond_Once);
    ImGui::SetNextWindowPos(ImGui::GetIO().DisplaySize / 2.0f - menuSize / 2.0f, ImGuiCond_Once);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    ImGui::SetNextWindowSizeConstraints(menuSize, ImVec2(9999, 9999));
    ImGui::Begin("menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
    ImGui::PopStyleVar(2);

    const ImVec2 pos = ImGui::GetWindowPos();
    const ImVec2 size = ImGui::GetWindowSize();
    ImDrawList* draw = ImGui::GetWindowDrawList();
    draw->AddRectFilled(pos, pos + ImVec2(sideBarWidth, size.y), ImGui::GetColorU32(ImGuiCol_WindowBg), style.WindowRounding, ImDrawFlags_RoundCornersLeft);
    draw->AddRectFilled(pos + ImVec2(sideBarWidth, 0), pos + size, ImGui::GetColorU32(ImGuiCol_PopupBg), style.WindowRounding, ImDrawFlags_RoundCornersRight);

    ImGui::BeginChild("SideBar", ImVec2(sideBarWidth, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_NoBackground);
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4());
    ImGui::BeginChild("LogoRect", ImVec2(0, ImGui::GetFontSize() + style.WindowPadding.y * 2), ImGuiChildFlags_Border);
    ImGui::PopStyleColor();
    ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("Mocha UI").x / 2.0f);
    ImGui::Text("Mocha");
    ImGui::SameLine();
    ImGui::TextDisabled("GUI");
    ImGui::EndChild();

    ImVec2 radioSize(ImGui::GetWindowWidth() - style.WindowPadding.x * 2.0f, 0);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, style.ChildRounding);
    ImGui::PushStyleColor(ImGuiCol_FrameBg, style.Colors[ImGuiCol_PopupBg]);

    auto nav = [&](const char* group, std::initializer_list<int> ids)
    {
        ImAdd::SeparatorText(group);
        for (int id : ids)
            ImAdd::RadioFrameIcon(TabName(id), TabIcon(id, m_selectedPage == id), &m_selectedPage, id, radioSize);
    };

    nav("PLAYER", { 0, 1, 2, 3 });
    nav("NETWORK", { 11, 4, 5, 6, 7 });
    nav("SETTINGS", { 8, 9 });
    nav("DEVELOPER", { 10, 12 });

    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
    ImGui::EndChild();

    ImGui::SameLine(sideBarWidth);
    ImGui::BeginChild("Content", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_NoBackground);
    ImGui::BeginChild("PageIcon", ImVec2(ImGui::GetFontSize() + m_bigFont->FontSize + style.ItemInnerSpacing.y * 3.0f, ImGui::GetFontSize() + m_bigFont->FontSize + style.ItemInnerSpacing.y * 3.0f));
    ImGui::SetCursorPos(ImGui::GetWindowSize() / 2.0f - ImVec2(ImGui::GetFontSize(), ImGui::GetFontSize()) / 2.0f);
    ImGui::Image(TabIcon(m_selectedPage, true), ImVec2(ImGui::GetFontSize(), ImGui::GetFontSize()), ImVec2(0, 0), ImVec2(1, 1), style.Colors[ImGuiCol_SliderGrab]);
    ImGui::EndChild();

    ImGui::SameLine();
    ImGui::BeginGroup();
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, style.ItemInnerSpacing);
    ImGui::Spacing();
    ImGui::PushFont(m_bigFont);
    ImGui::Text("%s", TabName(m_selectedPage));
    ImGui::PopFont();
    ImGui::TextDisabled("%s", TabDescription(m_selectedPage));
    ImGui::PopStyleVar();
    ImGui::EndGroup();

    ImGui::Spacing();
    RenderPage();
    ImGui::EndChild();
    ImGui::End();
}

bool CGui::MsgProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    if (msg == WM_KEYUP && wp == VK_DELETE)
    {
        m_open = !m_open;
        return true;
    }
    return m_open && ImGui_ImplWin32_WndProcHandler(hwnd, msg, wp, lp) != 0;
}
