#include "Textures.h"

#include "../Resources/Textures/image_api_filled.h"
#include "../Resources/Textures/image_api_outlines.h"
#include "../Resources/Textures/image_gear_filled.h"
#include "../Resources/Textures/image_gear_outlines.h"
#include "../Resources/Textures/image_items_outlines.h"
#include "../Resources/Textures/image_items_filled.h"
#include "../Resources/Textures/image_list.h"
#include "../Resources/Textures/image_medkit_filled.h"
#include "../Resources/Textures/image_medkit_outlines.h"
#include "../Resources/Textures/image_modules_filled.h"
#include "../Resources/Textures/image_modules_outlines.h"
#include "../Resources/Textures/image_tools_filled.h"
#include "../Resources/Textures/image_tools_outlines.h"
#include "../Resources/Textures/image_ui_filled.h"
#include "../Resources/Textures/image_ui_outlines.h"
#include "../Resources/Textures/image_users_filled.h"
#include "../Resources/Textures/image_users_outlines.h"
#include "../Resources/Textures/image_warn_filled.h"
#include "../Resources/Textures/image_warn_outlines.h"
#include "../Resources/Textures/image_coffee.h"
#include "../Resources/Textures/image_crown.h"
#include "../Resources/Textures/image_explosion.h"
#include "../Resources/Textures/image_loading.h"
#include "../Resources/Textures/image_star.h"

#include "../Resources/Textures/image_cube.h"
#include "../Resources/Textures/image_cube_filled.h"
#include "../Resources/Textures/image_gun.h"
#include "../Resources/Textures/image_gun_filled.h"
#include "../Resources/Textures/image_pencil.h"
#include "../Resources/Textures/image_pencil_filled.h"
#include "../Resources/Textures/image_test.h"
#include "../Resources/Textures/image_test_filled.h"
#include "../Resources/Textures/image_wing.h"
#include "../Resources/Textures/image_wing_filled.h"

bool CTextures::Initialize(ID3D11Device* pDevice)
{
    
    bool result = true;

    
	D3DX11CreateShaderResourceViewFromMemory(pDevice, api_filled_bytes, sizeof(api_filled_bytes), &info0, pump0, &tApiFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, api_outlines_bytes, sizeof(api_outlines_bytes), &info0, pump0, &tApiOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, gear_filled_bytes, sizeof(gear_filled_bytes), &info0, pump0, &tGearFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, gear_outlines_bytes, sizeof(gear_outlines_bytes), &info0, pump0, &tGearOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, items_outlines_bytes, sizeof(items_outlines_bytes), &info0, pump0, &tItemsOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, items_filled_bytes, sizeof(items_filled_bytes), &info0, pump0, &tItemsFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, list_bytes, sizeof(list_bytes), &info0, pump0, &tList, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, medkit_filled_bytes, sizeof(medkit_filled_bytes), &info0, pump0, &tMedkitFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, medkit_outlines_bytes, sizeof(medkit_outlines_bytes), &info0, pump0, &tMedkitOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, modules_filled_bytes, sizeof(modules_filled_bytes), &info0, pump0, &tModulesFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, modules_outlines_bytes, sizeof(modules_outlines_bytes), &info0, pump0, &tModulesOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, tools_filled_bytes, sizeof(tools_filled_bytes), &info0, pump0, &tToolsFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, tools_outlines_bytes, sizeof(tools_outlines_bytes), &info0, pump0, &tToolsOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, ui_filled_bytes, sizeof(ui_filled_bytes), &info0, pump0, &tUiFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, ui_outlines_bytes, sizeof(ui_outlines_bytes), &info0, pump0, &tUiOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, users_filled_bytes, sizeof(users_filled_bytes), &info0, pump0, &tUsersFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, users_outlines_bytes, sizeof(users_outlines_bytes), &info0, pump0, &tUsersOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, warn_filled_bytes, sizeof(warn_filled_bytes), &info0, pump0, &tWarnFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, warn_outlines_bytes, sizeof(warn_outlines_bytes), &info0, pump0, &tWarnOutlines, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, coffee_bytes, sizeof(coffee_bytes), &info0, pump0, &tCoffee, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, crown_bytes, sizeof(crown_bytes), &info0, pump0, &tCrown, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, explosion_bytes, sizeof(explosion_bytes), &info0, pump0, &tExplosion, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, loading_bytes, sizeof(loading_bytes), &info0, pump0, &tLoading, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, star_bytes, sizeof(star_bytes), &info0, pump0, &tStar, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, cube_bytes, sizeof(cube_bytes), &info0, pump0, &tCube, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, cube_filled_bytes, sizeof(cube_filled_bytes), &info0, pump0, &tCubeFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, gun_bytes, sizeof(gun_bytes), &info0, pump0, &tGun, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, gun_filled_bytes, sizeof(gun_filled_bytes), &info0, pump0, &tGunFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, pencil_bytes, sizeof(pencil_bytes), &info0, pump0, &tPencil, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, pencil_filled_bytes, sizeof(pencil_filled_bytes), &info0, pump0, &tPencilFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, test_bytes, sizeof(test_bytes), &info0, pump0, &tTest, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, test_filled_bytes, sizeof(test_filled_bytes), &info0, pump0, &tTestFilled, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, wing_bytes, sizeof(wing_bytes), &info0, pump0, &tWing, 0);
	D3DX11CreateShaderResourceViewFromMemory(pDevice, wing_filled_bytes, sizeof(wing_filled_bytes), &info0, pump0, &tWingFilled, 0);

    return result;
}

void CTextures::Shutdown()
{
    auto release=[](ID3D11ShaderResourceView*& p){ if(p){p->Release();p=nullptr;} };
    release(tApiFilled); release(tApiOutlines); release(tGearFilled); release(tGearOutlines);
    release(tItemsOutlines); release(tItemsFilled); release(tList); release(tMedkitFilled); release(tMedkitOutlines);
    release(tModulesFilled); release(tModulesOutlines); release(tToolsFilled); release(tToolsOutlines); release(tUiFilled); release(tUiOutlines);
    release(tUsersFilled); release(tUsersOutlines); release(tWarnFilled); release(tWarnOutlines); release(tCoffee); release(tCrown);
    release(tExplosion); release(tLoading); release(tStar); release(tCube); release(tCubeFilled); release(tGun); release(tGunFilled);
    release(tPencil); release(tPencilFilled); release(tTest); release(tTestFilled); release(tWing); release(tWingFilled);
}
