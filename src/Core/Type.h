#pragma once
#include <Windows.h>

namespace SGLW {
/*Core Types*/
#define SGLWTRUE						1;
#define SGLWFALSE						0;

/*Core Types Convert*/
typedef BOOL						SGLWBOOL;
typedef LPCWSTR						CONSTWCHAR;	/*16 bit unicode character*/
//typedef TRUE						SGLWTRUE;

#if defined _WIN32 || _WIN64		/*Win32 || Win64*/
	/*
	Window Handler
	Device Context
	GlHandler
	PixelFormat
	Rect for sizing
	windowclass for creation
	wndproc for listening window
	*/

	/*Window System Types Convert*/
	typedef HWND						SGLWindowHandler;
	typedef HDC							SGLWDeviceContext;
	typedef HGLRC						SGLWRenderContext;
	typedef PIXELFORMATDESCRIPTOR		SGLWPixelFormat;
	typedef RECT						SGLWindowRect;
	typedef WNDCLASSEX					SGLWindowClass;
	typedef WNDPROC						SGLWindowProc;

#elif _unix							/*UNIX*/
	/*
	Window Handler
	Device Context
	GlHandler
	PixelFormat
	*/

#elif __APPLE__						/*MAC&&APPLE*/
	/*
	Window Handler
	Device Context
	GlHandler
	PixelFormat
	*/

#endif
};