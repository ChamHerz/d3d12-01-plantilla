//***************************************************************************************
// Engine.h by ChamHerz (C) 2020
//***************************************************************************************

#pragma once

// Activa los features para adiministrar la memoria en Debug
#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <windows.h>
#include <xstring>

class Engine
{
public:

protected:
	// constructor protegido SINGLETON
	Engine(HINSTANCE hInstance);
	Engine(const Engine& rhs) = delete;
	Engine& operator=(const Engine& rhs) = delete;
	virtual ~Engine();

	static Engine* engine;
	HINSTANCE engineInstance = nullptr;			// instancia de la aplicacion
	HWND      engineHwnd = nullptr;				// handle de la ventana principal

	bool initMainWindow();
	bool initDirectX();
	int clientWidth = 800;
	int clientHeight = 600;
	std::wstring engineCaption = L"Shader Game";

public:
	static Engine* getEngine();

	virtual bool initialize();

	int run();
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};