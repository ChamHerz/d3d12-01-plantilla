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

LRESULT CALLBACK
MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Reenviamos el hwnd, xq despues del CreateWindows el hwnd es valido
	return Engine::getEngine()->MsgProc(hwnd, msg, wParam, lParam);
}

LRESULT Engine::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		// WM_DESTROY se manda cuando comienza a destruirse
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

bool Engine::initMainWindow()
{
	// inciar la ventana principal
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MainWndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = engineInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"MainWnd";

	if (!RegisterClass(&wc))
	{
		MessageBox(0, L"El registro de la clase fallo", 0, 0);
		return false;
	}

	// Creamos un rectangulo en base a las dimensiones del cliente
	RECT R = { 0, 0, clientWidth, clientHeight };
	AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
	int width = R.right - R.left;
	int height = R.bottom - R.top;

	engineHwnd = CreateWindow(L"MainWnd", engineCaption.c_str(),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, 0, 0, engineInstance, 0);
	if (!engineHwnd)
	{
		MessageBox(0, L"Error al crear la ventana principal.", 0, 0);
		return false;
	}

	ShowWindow(engineHwnd, SW_SHOW);
	UpdateWindow(engineHwnd);

	return true;
}

bool Engine::initDirectX()
{
	// iniciamos el DirectX 12
	return true;
}

bool Engine::initialize()
{
	if (!initMainWindow())
		return false;

	if (!initDirectX())
		return false;

	return true;
}

int Engine::run()
{
	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}