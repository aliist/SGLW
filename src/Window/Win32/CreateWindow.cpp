#include "CreateWindow.h"

SGLW::SGLWBOOL GLWIN::CreateWindowClass(HINSTANCE hThisInstance, SGLW::CONSTWCHAR ClassName, SGLW::SGLWindowProc WinProc)
{
    this->DRWCLASS= { 0 };

    DRWCLASS.hInstance = hThisInstance;
    DRWCLASS.lpszClassName = ClassName;
    DRWCLASS.lpfnWndProc = WinProc;
    DRWCLASS.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    DRWCLASS.cbSize = sizeof(WNDCLASSEX);
    DRWCLASS.hIcon = LoadIcon(NULL, IDC_ICON);
    DRWCLASS.hIconSm = LoadIcon(NULL, IDC_ICON);
    DRWCLASS.hCursor = LoadCursor(NULL, IDC_ARROW);
    DRWCLASS.lpszMenuName = NULL;
    DRWCLASS.cbClsExtra = 0;
    DRWCLASS.cbWndExtra = 0;
    DRWCLASS.hbrBackground = (HBRUSH)COLOR_HIGHLIGHT;
    if (!RegisterClassEx(&DRWCLASS)) return 0;

    this->DRWNAME = ClassName;
    this->DRWPROCN = WinProc;

    return SGLW::SGLWBOOL();
}

SGLW::CONSTWCHAR GLWIN::GetWindowClassName()
{
    return SGLW::CONSTWCHAR(this->DRWNAME);
}

SGLW::SGLWBOOL GLWIN::GLWINMAIN()
{
    this->CreateWindowClass(this->hThisInstance,L"GLDRAWINDOWIN32", this->DRWPROCN);
    //this->DRWINCREATE();
    return SGLW::SGLWBOOL();
}
