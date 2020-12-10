#include <cassert>
#include "Engine.h"

Engine* Engine::engine = nullptr;
Engine* Engine::getEngine()
{
	return engine;
}

Engine::Engine(HINSTANCE hInstance) : engineInstance(hInstance)
{
	assert(engine == nullptr);
	engine = this;
}

Engine::~Engine()
{
	// @TODO
	/*if (device != nullptr)
		flushCommandQueue();*/
}