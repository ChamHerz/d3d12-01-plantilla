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
	HINSTANCE engineInstance = nullptr;

public:
	static Engine* getEngine();
};

