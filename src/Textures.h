#pragma once
#include <d3d11.h>
#include <D3DX11tex.h>

class CTextures {
public:
    bool Initialize(ID3D11Device* device);
    void Shutdown();
    D3DX11_IMAGE_LOAD_INFO info0{}; ID3DX11ThreadPump* pump0{};
    ID3D11ShaderResourceView *tApiFilled{},*tApiOutlines{},*tGearFilled{},*tGearOutlines{},*tItemsOutlines{},*tItemsFilled{},*tList{},*tMedkitFilled{},*tMedkitOutlines{},*tModulesFilled{},*tModulesOutlines{},*tToolsFilled{},*tToolsOutlines{},*tUiFilled{},*tUiOutlines{},*tUsersFilled{},*tUsersOutlines{},*tWarnFilled{},*tWarnOutlines{},*tCoffee{},*tCrown{},*tExplosion{},*tLoading{},*tStar{},*tCube{},*tCubeFilled{},*tGun{},*tGunFilled{},*tPencil{},*tPencilFilled{},*tTest{},*tTestFilled{},*tWing{},*tWingFilled{};
};
