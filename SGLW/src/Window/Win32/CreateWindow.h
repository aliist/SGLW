#pragma once
#include <Windows.h>
#include "..\..\Core\Type.h"

#define WIN
#define WINN
#define WINNN

#define MAINW	0
#define SUBW	1

class GLWIN
{
private:
	WNDCLASS DRWCLASS;
	WNDPROC  DRWPROCN;
	HWND	 DRWHWND;
	LPCWSTR  DRWNAME;
	HGLRC	 DRWGLC;
public:
	/*About Pixel Format*/
	BOOL SetPixelFormat();
	PIXELFORMATDESCRIPTOR GetPixelFormat();
	
	/*About GL Context Pixel*/
	//BOOL SetPixelFormat();
	//PIXELFORMATDESCRIPTOR GetPixelFormat();
	BOOL DRWCGLPIXELFORMAT();
	BOOL DRWSETFORDRAWING();
	BOOL DRWDESTROYGLC();

	/*About Window*/
	HWND DRWINCREATE();
	BOOL DRWINDESTROY();
	
	/*About Sizing And Other Thing*/
	RECT GetDraWindowRect();

	/*Complete Creating*/
	BOOL GLWINMAIN();
};