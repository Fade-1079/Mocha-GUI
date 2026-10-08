#include "Hook.h"
#include "Gui.h"
#include "Textures.h"
#include "../Dependencies/Kiero/kiero.h"
#include <d3d11.h>
#include <dxgi.h>
#include <atomic>
#include <thread>
#include <mutex>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"dxgi.lib")

namespace {
using PresentFn=HRESULT(__stdcall*)(IDXGISwapChain*,UINT,UINT);
PresentFn g_originalPresent=nullptr;
void** g_vtableEntry=nullptr;
void* g_originalEntry=nullptr;
ID3D11Device* g_device=nullptr; ID3D11DeviceContext* g_context=nullptr; ID3D11RenderTargetView* g_rtv=nullptr;
HWND g_window=nullptr; WNDPROC g_oldWndProc=nullptr; CTextures* g_textures=nullptr; CGui* g_gui=nullptr;
std::atomic_bool g_running{true}; std::atomic_bool g_ready{false};
std::once_flag g_initOnce;
HRESULT __stdcall PresentHook(IDXGISwapChain* swap,UINT sync,UINT flags);

LRESULT CALLBACK WindowProc(HWND h,UINT m,WPARAM w,LPARAM l){
    if(g_gui && g_gui->MsgProc(h,m,w,l)) return 1;
    return g_oldWndProc?CallWindowProcW(g_oldWndProc,h,m,w,l):DefWindowProcW(h,m,w,l);
}

bool PatchVTable(IDXGISwapChain* swap){
    if(!swap) return false;
    auto table=*reinterpret_cast<void***>(swap);
    if(!table || !table[8]) return false;
    DWORD oldProtect=0;
    if(!VirtualProtect(&table[8],sizeof(void*),PAGE_EXECUTE_READWRITE,&oldProtect)) return false;
    g_vtableEntry=&table[8]; g_originalEntry=table[8]; g_originalPresent=reinterpret_cast<PresentFn>(table[8]); table[8]=reinterpret_cast<void*>(&PresentHook); 
    DWORD tmp; VirtualProtect(&table[8],sizeof(void*),oldProtect,&tmp); FlushInstructionCache(GetCurrentProcess(),&table[8],sizeof(void*));
    return true;
}

void Cleanup(){
    if(g_vtableEntry && g_originalEntry){ DWORD old; if(VirtualProtect(g_vtableEntry,sizeof(void*),PAGE_EXECUTE_READWRITE,&old)){*g_vtableEntry=g_originalEntry;DWORD tmp;VirtualProtect(g_vtableEntry,sizeof(void*),old,&tmp);} g_vtableEntry=nullptr; }
    if(g_gui){g_gui->Shutdown();delete g_gui;g_gui=nullptr;} if(g_textures){g_textures->Shutdown();delete g_textures;g_textures=nullptr;}
    if(g_rtv){g_rtv->Release();g_rtv=nullptr;} if(g_context){g_context->Release();g_context=nullptr;} if(g_device){g_device->Release();g_device=nullptr;}
    if(g_oldWndProc&&g_window){SetWindowLongPtrW(g_window,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(g_oldWndProc));g_oldWndProc=nullptr;}
    if(g_window){DestroyWindow(g_window);g_window=nullptr;}
    kiero::shutdown(); g_ready=false;
}


void Watermark()
{
    static const char* watermarkText = "Mocha | Extracted GUI | Extracted by @Fade1079 | v2.1.1  |";
    static ImVec2 watermarkSize{};

    if (watermarkSize.x == 0.0f)
        watermarkSize = ImGui::CalcTextSize(watermarkText);

    ImGui::SetNextWindowSize(watermarkSize);
    ImGui::SetNextWindowBgAlpha(0.75f);
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));

    ImGui::Begin(
        "##mocha_watermark",
        nullptr,
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoInputs |
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoBringToFrontOnFocus
    );

    ImVec4 light = ImVec4(0.953f, 0.337f, 0.337f, 1.0f);
    ImVec4 dark = ImVec4(0.498f, 0.035f, 0.035f, 1.0f);

    ImDrawList* draw = ImGui::GetWindowDrawList();
    ImVec2 pos = ImGui::GetCursorScreenPos();

    float width = ImGui::CalcTextSize(watermarkText).x;
    float x = pos.x;

    for (int i = 0; watermarkText[i] != '\0'; ++i)
    {
        char character[2] = { watermarkText[i], '\0' };
        float characterWidth = ImGui::CalcTextSize(character).x;
        float t = width > 0.0f ? (x - pos.x) / width : 0.0f;

        ImVec4 color(
            light.x + (dark.x - light.x) * t,
            light.y + (dark.y - light.y) * t,
            light.z + (dark.z - light.z) * t,
            1.0f
        );

        draw->AddText(
            ImVec2(x, pos.y),
            ImGui::ColorConvertFloat4ToU32(color),
            character
        );

        x += characterWidth;
    }

    ImGui::End();
}


void BouncingColoredText()
{
    static ImVec2 position(100.0f, 100.0f);
    static ImVec2 velocity(1.5f, 1.5f);
    static ImVec4 color(1.0f, 1.0f, 1.0f, 1.0f);

    ImGuiIO& io = ImGui::GetIO();
    ImDrawList* draw = ImGui::GetForegroundDrawList();

    const char* text = "Mochaaaaaaaaaaaaa";
    ImVec2 textSize = ImGui::CalcTextSize(text);

    position.x += velocity.x;
    position.y += velocity.y;

    bool bounced = false;

    if (position.x <= 0.0f)
    {
        position.x = 0.0f;
        velocity.x = std::abs(velocity.x);
        bounced = true;
    }
    else if (position.x + textSize.x >= io.DisplaySize.x)
    {
        position.x = io.DisplaySize.x - textSize.x;
        velocity.x = -std::abs(velocity.x);
        bounced = true;
    }

    if (position.y <= 0.0f)
    {
        position.y = 0.0f;
        velocity.y = std::abs(velocity.y);
        bounced = true;
    }
    else if (position.y + textSize.y >= io.DisplaySize.y)
    {
        position.y = io.DisplaySize.y - textSize.y;
        velocity.y = -std::abs(velocity.y);
        bounced = true;
    }

    if (bounced)
    {
        color = ImVec4(
            static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
            static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
            static_cast<float>(rand()) / static_cast<float>(RAND_MAX),
            1.0f
        );
    }

    draw->AddText(
        position,
        ImGui::ColorConvertFloat4ToU32(color),
        text
    );
}

HRESULT __stdcall PresentHook(IDXGISwapChain* swap,UINT sync,UINT flags){
    std::call_once(g_initOnce,[&]{
        DXGI_SWAP_CHAIN_DESC sd{}; if(FAILED(swap->GetDesc(&sd))) return; g_window=sd.OutputWindow;
        if(FAILED(swap->GetDevice(__uuidof(ID3D11Device),reinterpret_cast<void**>(&g_device)))) return; g_device->GetImmediateContext(&g_context);
        ID3D11Texture2D* bb=nullptr; if(FAILED(swap->GetBuffer(0,__uuidof(ID3D11Texture2D),reinterpret_cast<void**>(&bb)))) return;
        if(FAILED(g_device->CreateRenderTargetView(bb,nullptr,&g_rtv))){bb->Release();return;} bb->Release();
        g_textures=new CTextures(); if(!g_textures->Initialize(g_device)){delete g_textures;g_textures=nullptr;return;}
        g_gui=new CGui(g_textures); if(!g_gui->Initialize(g_window,g_device,g_context)){g_gui->Shutdown();delete g_gui;g_gui=nullptr;return;}
        g_oldWndProc=reinterpret_cast<WNDPROC>(SetWindowLongPtrW(g_window,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(WindowProc)));
        g_ready=true;
    });
    if(g_ready&&g_gui){ImGui_ImplDX11_NewFrame();ImGui_ImplWin32_NewFrame();ImGui::NewFrame(); Watermark(); BouncingColoredText(); ImGui::GetIO().MouseDrawCursor=true;g_gui->PreRender();ImGui::Render();g_context->OMSetRenderTargets(1,&g_rtv,nullptr);ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());}
    return g_originalPresent?g_originalPresent(swap,sync,flags):S_OK;
}

DWORD WINAPI Worker(LPVOID p){
    HMODULE mod=reinterpret_cast<HMODULE>(p);
    while(g_running && kiero::init(kiero::RenderType::D3D11)!=kiero::Status::Success) Sleep(250);
    if(!g_running) return 0;
    
    
    WNDCLASSW wc{}; wc.lpfnWndProc=DefWindowProcW; wc.hInstance=mod; wc.lpszClassName=L"MochaUIDummy"; RegisterClassW(&wc);
    HWND hwnd=CreateWindowExW(0,wc.lpszClassName,L"Mocha UI",WS_OVERLAPPEDWINDOW,0,0,64,64,nullptr,nullptr,mod,nullptr);
    DXGI_SWAP_CHAIN_DESC sd{}; sd.BufferCount=1; sd.BufferDesc.Format=DXGI_FORMAT_R8G8B8A8_UNORM; sd.BufferUsage=DXGI_USAGE_RENDER_TARGET_OUTPUT; sd.OutputWindow=hwnd; sd.SampleDesc.Count=1; sd.Windowed=TRUE; sd.SwapEffect=DXGI_SWAP_EFFECT_DISCARD;
    IDXGISwapChain* dummy=nullptr; ID3D11Device* dev=nullptr; ID3D11DeviceContext* ctx=nullptr;
    D3D_FEATURE_LEVEL featureLevel{};
    if(SUCCEEDED(D3D11CreateDeviceAndSwapChain(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,0,nullptr,0,D3D11_SDK_VERSION,&sd,&dummy,&dev,&featureLevel,&ctx))){
        PatchVTable(dummy); if(ctx)ctx->Release(); if(dev)dev->Release(); if(dummy)dummy->Release();
    }
    DestroyWindow(hwnd); UnregisterClassW(wc.lpszClassName,mod);
    while(g_running) Sleep(100);
    Cleanup(); return 0;
}
}

namespace Hook { void Start(HMODULE module){g_running=true;HANDLE h=CreateThread(nullptr,0,Worker,module,0,nullptr);if(h)CloseHandle(h);} }
