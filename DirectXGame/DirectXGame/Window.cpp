#include "Window.h"

Window* window = nullptr;

Window::Window()
{
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:		// Event fired when window is created
		break;	
	case WM_DESTROY:	// Event fired when window is destroyed	
		::PostQuitMessage(0);
		break;
	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return NULL;
}

bool Window::init()
{
	// Defining properties of the window
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"MyWindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	// Registering window class and passing defined properties
	if (!::RegisterClassEx(&wc))	// if fails to create return false
		return false;

	// Creates the window
	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX Application", 
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);


	if (!m_hwnd) // if the creating window function fails result will be 0
		return false;

	// show window
	::ShowWindow(m_hwnd, SW_SHOW);

	// update window
	::UpdateWindow(m_hwnd);

	if (!window)
		window = this;

	return true;
}

bool Window::release()
{
	// Destroy the window
	if (!::DestroyWindow(m_hwnd))	// if unable to destroy, function returns 0
		return false;

	return true;
}

Window::~Window()
{
}
