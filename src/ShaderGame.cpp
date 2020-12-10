//***************************************************************************************
// d3d12-01-plantilla by ChamHerz (C) 2020
//***************************************************************************************

#include <Windows.h>	//WinMain
#include "Engine.h"

class ShaderGame : public Engine
{
public:
	ShaderGame(HINSTANCE hInstanc);
	~ShaderGame();

};

int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ PSTR szCmdLine, _In_ int iCmdShow) {

	// Activa los features para adiministrar la memoria en Debug
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	return 0;
};

ShaderGame::ShaderGame(HINSTANCE hInstance): Engine(hInstance)
{

}

ShaderGame::~ShaderGame()
{

}