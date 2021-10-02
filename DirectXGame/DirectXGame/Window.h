#pragma once
#include <windows.h>

class Window
{
public:
	Window();
	bool init();		// initialize window
	bool broadcast();
	bool release();		// destroy window
	~Window();
// Virtual Methods
public:
	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroy() = 0;
protected:
	HWND m_hwnd;		// window handler
};

