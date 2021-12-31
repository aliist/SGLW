#pragma once
#include <Windows.h>

#if defined _WIN32 || _WIN64		/*Win32 || Win64*/
/*
Window Handler
Device Context
GlHandler
PixelFormat
*/

/*Core Types*/
#define SGLTRUE						1;
#define SGLFALSE					0;

/*Core Types Convert*/
typedef BOOL						SGLBOOL;
typedef LPCWSTR						CONSTWCHAR;	/*16 biy unicode character*/

/*Window System Types Convert*/
typedef HWND						WindowHandler;
typedef HDC							DeviceContext;
typedef HGLRC						GlHandler;
typedef PIXELFORMATDESCRIPTOR		PixelFormat;
typedef RECT						SglRect;
typedef WNDCLASS					WindowClass;

#elif _unix							/*UNIX*/
/*
Window Handler
Device Context
GlHandler
PixelFormat
*/

#elif __APPLE__						/*MAC*/
/*
Window Handler
Device Context
GlHandler
PixelFormat
*/

#endif
