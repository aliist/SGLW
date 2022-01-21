#pragma once
#include "..\..\Core\Type.h"

#define MAINW	0
#define SUBW	1

class GLWIN
{
private:
	SGLW::SGLWindowClass	DRWCLASS;
	SGLW::SGLWindowProc		DRWPROCN;
	SGLW::SGLWindowHandler	DRWHWND;
	SGLW::CONSTWCHAR		DRWNAME;
	SGLW::SGLWindowRect		DRWGLC;
	HINSTANCE hThisInstance;
public:
	/*About Window Class*/
	SGLW::SGLWBOOL CreateWindowClass(HINSTANCE hThisInstance, SGLW::CONSTWCHAR ClassName, SGLW::SGLWindowProc WinProc);
	SGLW::CONSTWCHAR GetWindowClassName();
	/*About Pixel Format*/
	SGLW::SGLWBOOL SetPixelFormat();
	SGLW::SGLWPixelFormat GetPixelFormat();
	
	/*About GL Context Pixel*/
	//BOOL SetPixelFormat();
	//PIXELFORMATDESCRIPTOR GetPixelFormat();
	SGLW::SGLWBOOL DRWCGLPIXELFORMAT();
	SGLW::SGLWBOOL DRWSETFORDRAWING();
	SGLW::SGLWBOOL DRWDESTROYGLC();

	/*About Window*/
	SGLW::SGLWindowHandler DRWINCREATE();
	SGLW::SGLWBOOL DRWINDESTROY();
	
	/*About Sizing And Other Thing*/
	SGLW::SGLWindowRect GetDraWindowRect();

	/*Complete Creating*/
	SGLW::SGLWBOOL GLWINMAIN();
};