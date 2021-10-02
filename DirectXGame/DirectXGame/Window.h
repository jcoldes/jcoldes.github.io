#pragma once
#include <windows.h>

class Window
{
public:
	Window();
	bool init();		// initialize window
	bool release();		// destroy window
	~Window();
protected:
	HWND m_hwnd;		// window handler
};

