#define GLEW_STATIC

#include "..\src\Core\Type.h"
#include "..\src\Window\Win32\CreateWindow.h"
#include "..\src\Draw.h"

#include <CommCtrl.h>
#include <string>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK GLWindowProcedure(HWND, UINT, WPARAM, LPARAM);

MSG messages;

SGLW::CONSTWCHAR szClassName     = L"MainWim";
SGLW::CONSTWCHAR GLWinClassName  = L"GLWin";

SGLW::SGLWindowProc GLWinProc;

SGLW::SGLWindowHandler MainWindow, GLWindow, StatusWindow, ToolWindow;
SGLW::SGLWDeviceContext DC;
SGLW::SGLWRenderContext RC;

SGLW::SGLWindowRect MainWRect,ToolWRect,StatusWRect,GLWRect,Test;
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
    GLWIN DraWindow;
    DraWindow.CreateWindowClass(hThisInstance, L"GLDRAWINDOWIN32", WindowProcedure);

    //SGLW::SGLWindowClass   winclex = { 0 };
    //winclex.hInstance = hThisInstance;
    //winclex.lpszClassName = szClassName;
    //winclex.lpfnWndProc = WindowProcedure;
    //winclex.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    //winclex.cbSize = sizeof(WNDCLASSEX);
    //winclex.hIcon = LoadIcon(NULL, IDC_ICON);
    //winclex.hIconSm = LoadIcon(NULL, IDC_ICON);
    //winclex.hCursor = LoadCursor(NULL, IDC_ARROW);
    //winclex.lpszMenuName = NULL;
    //winclex.cbClsExtra = 0;
    //winclex.cbWndExtra = 0;
    //winclex.hbrBackground = (HBRUSH)COLOR_HIGHLIGHT;
    //if (!RegisterClassEx(&winclex)) return 0;

    //WNDCLASS   wincl = { 0 };
    //wincl.hInstance = hThisInstance;
    //wincl.lpszClassName = GLWinClassName;
    //wincl.lpfnWndProc = GLWindowProcedure;
    //wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    //  if (RegisterClass(&wincl) == 0)
    //      MessageBoxA(MainWindow, /*"GL Window Creation Error"*/"Class Creation Error", "Window Creation Error", 0);

    wchar_t buf[256];
    FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        buf, (sizeof(buf) / sizeof(wchar_t)), NULL);
    std::wstring ws = buf;
    std::string errmsg(ws.begin(), ws.end());


    MainWindow = CreateWindowEx(0, DraWindow.GetWindowClassName(), L"SGLWTestWindow", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0,0,900,900/*CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT*/, NULL, NULL, hThisInstance, NULL);
    if (!MainWindow)
        MessageBoxA(MainWindow, "Main Window Creation Error", "Window Creation Error", 0);
   
    //StatusWindow = CreateWindowEx(0, STATUSCLASSNAME, 0, SBARS_SIZEGRIP |WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, MainWindow, 0, hThisInstance, NULL);
    //if (!StatusWindow)
    //    MessageBoxA(MainWindow, "Status Window Creation Error", "Window Creation Error", 0);

    //ToolWindow= CreateWindowEx(0, TOOLBARCLASSNAME, 0, WS_CHILD | WS_THICKFRAME | WS_CLIPSIBLINGS /*Solve overlapping problem*/ |WS_VISIBLE | TBSTYLE_WRAPABLE | CCS_VERT | CCS_LEFT | CCS_ADJUSTABLE /* Enable draw drop button and customize toolbar component*/, 0, 0, 100, 100, MainWindow, NULL, hThisInstance, NULL);
    //if (!ToolWindow)
    //    MessageBoxA(MainWindow, "Tool Window Creation Error", "Window Creation Error", 0);
    //

    //GLWindow = CreateWindow(GLWinClassName, L"GLWin", WS_CAPTION |WS_SIZEBOX|WS_SYSMENU/*WS_OVERLAPPEDWINDOW*/| WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE, 20, 0, 320, 240, MainWindow, NULL, hThisInstance, NULL);
    //if (!GLWindow)
    //    MessageBoxA(MainWindow, /*"GL Window Creation Error"*/errmsg.c_str(), "Window Creation Error", 0);
    //GLWinProc = (WNDPROC)SetWindowLongPtrA(GLWindow, GWLP_WNDPROC, (LONG_PTR)GLWindowProcedure);


    
    while (GetMessage(&messages, NULL, 0, 0) > 0)
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    GetClientRect(MainWindow, &MainWRect);
    GetWindowRect(ToolWindow, &ToolWRect);
    GetWindowRect(StatusWindow, &StatusWRect);
    GetWindowRect(GLWindow, &GLWRect);

    switch (message)
    {
    case WM_DESTROY:
        ReleaseDC(hwnd, DC);
        wglDeleteContext(RC);
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case 0x46:
            ShowWindow(StatusWindow, SW_HIDE);
            break;
        case 0x47:
            ShowWindow(ToolWindow, SW_HIDE);
            break;
        case 0x48:
        {
            std::string Left = std::to_string(StatusWRect.left);
            MessageBoxA(MainWindow, (LPCSTR)Left.c_str(), "StatusLeft", 0);
            std::string Right = std::to_string(StatusWRect.right);
            MessageBoxA(MainWindow, (LPCSTR)Right.c_str(), "StatusRight", 0);
            std::string Top = std::to_string(StatusWRect.top);
            MessageBoxA(MainWindow, (LPCSTR)Top.c_str(), "StatusTop", 0);
            std::string Bottom = std::to_string(StatusWRect.bottom);
            MessageBoxA(MainWindow, (LPCSTR)Bottom.c_str(), "StatusBottom", 0);

            IntersectRect(&Test, &StatusWRect, &ToolWRect);

            std::string TLeft = std::to_string(Test.left);
            MessageBoxA(MainWindow, (LPCSTR)TLeft.c_str(), "TLeft", 0);
            std::string TRight = std::to_string(Test.right);
            MessageBoxA(MainWindow, (LPCSTR)TRight.c_str(), "TRight", 0);
            std::string TTop = std::to_string(Test.top);
            MessageBoxA(MainWindow, (LPCSTR)TTop.c_str(), "TTop", 0);
            std::string TBottom = std::to_string(Test.bottom);
            MessageBoxA(MainWindow, (LPCSTR)TBottom.c_str(), "TBottom", 0);
        }
            break;
        case 0x49:
            MessageBoxA(hwnd, (LPCSTR)glGetString(GL_VERSION), "Main", 0);
            break;
        default:
            break;
        }
    case WM_SIZE:
    {
        //std::string MLeft = std::to_string(MainWRect.left);
        //MessageBoxA(MainWindow, (LPCSTR)MLeft.c_str(), "MainLeft", 0);
        //std::string MRight = std::to_string(MainWRect.right);
        //MessageBoxA(MainWindow, (LPCSTR)MRight.c_str(), "MainRight", 0);
        //std::string MTop = std::to_string(MainWRect.top);
        //MessageBoxA(MainWindow, (LPCSTR)MTop.c_str(), "MainTop", 0);
        //std::string MBottom = std::to_string(MainWRect.bottom);
        //MessageBoxA(MainWindow, (LPCSTR)MBottom.c_str(), "MainBottom", 0);
        //
        //
        
        //MoveWindow(StatusWindow, 0, 0, 0, 0, TRUE);
        
        //GetWindowRect(StatusWindow, &StatusWRect);
        //std::string Left = std::to_string(StatusWRect.left);
        //MessageBoxA(MainWindow, (LPCSTR)Left.c_str(), "StatusLeft", 0);
        //std::string Right = std::to_string(StatusWRect.right);
        //MessageBoxA(MainWindow, (LPCSTR)Right.c_str(), "StatusRight", 0);
        //std::string Top = std::to_string(StatusWRect.top);
        //MessageBoxA(MainWindow, (LPCSTR)Top.c_str(), "StatusTop", 0);
        //std::string Bottom = std::to_string(StatusWRect.bottom);
        //MessageBoxA(MainWindow, (LPCSTR)Bottom.c_str(), "StatusBottom", 0);



        //MoveWindow(ToolWindow, 0, 0, 0, MainWRect.bottom - StatusWRect.top, TRUE);
        //GetWindowRect(ToolWindow, &ToolWRect);
        //
        ////SetWindowPos(GLWindow, HWND_TOPMOST, ToolWRect.right, 0, MainWRect.right - ToolWRect.right, MainWRect.bottom - StatusWRect.left, SWP_DRAWFRAME|SWP_SHOWWINDOW| SWP_FRAMECHANGED);
        //MoveWindow(GLWindow, ToolWRect.right, 0, MainWRect.right - ToolWRect.right, MainWRect.right - StatusWRect.top, TRUE);
        ////MoveWindow(GLWindow, ToolWRect.right, 0, MainWRect.right-ToolWRect.right,MainWRect.bottom-StatusWRect.left, TRUE);
        //GetWindowRect(GLWindow, &GLWRect);
        break;
    }
    //case WM_LBUTTONDOWN:
    //    SetFocus(MainWindow);
    //    break;
    case WM_CREATE:
    {
        SGLW::SGLWPixelFormat pfd = {
            sizeof(SGLW::SGLWPixelFormat),   //  size of this pfd  
            1,                     // version number  
            PFD_DRAW_TO_WINDOW |   // support window  
            PFD_SUPPORT_OPENGL |   // support OpenGL  
            PFD_DOUBLEBUFFER,      // double buffered  
            PFD_TYPE_RGBA,         // RGBA type  
            24,                    // 24-bit color depth  
            0, 0, 0, 0, 0, 0,      // color bits ignored  
            0,                     // no alpha buffer  
            0,                     // shift bit ignored  
            0,                     // no accumulation buffer  
            0, 0, 0, 0,            // accum bits ignored  
            24,                    // 32-bit z-buffer      
            8,                     // if number is 0 = no stencil buffer  
            0,                     // no auxiliary buffer  
            PFD_MAIN_PLANE,        // main layer  
            0,                     // reserved  
            0, 0, 0                // layer masks ignored  
        };
        DC = GetDC(hwnd);
        int pf = ChoosePixelFormat(DC, &pfd);
        SetPixelFormat(DC, pf, &pfd);
        RC = wglCreateContext(DC);
        wglMakeCurrent(DC, RC);
        glViewport(0, 0, 640, 480);
        //MessageBoxA(hwnd, (LPCSTR)glGetString(GL_VERSION), "GL VERSION", 0);
        break;
    }
    case WM_PAINT:
        Draw(DC);
    default:
        break;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
//LRESULT CALLBACK GLWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)
//    {
//    case WM_DESTROY:
//        ReleaseDC(hwnd, DC);
//        wglDeleteContext(RC);
//        DestroyWindow(GLWindow);
//        //PostQuitMessage(0);
//        break;
//    case WM_LBUTTONDOWN:
//        SetFocus(GLWindow);
//        break;
//    case WM_CREATE:
//    {
//        PixelFormat pfd = {
//            sizeof(PixelFormat),  //  size of this pfd  
//            1,                     // version number  
//            PFD_DRAW_TO_WINDOW |   // support window  
//            PFD_SUPPORT_OPENGL |   // support OpenGL  
//            PFD_DOUBLEBUFFER,      // double buffered  
//            PFD_TYPE_RGBA,         // RGBA type  
//            24,                    // 24-bit color depth  
//            0, 0, 0, 0, 0, 0,      // color bits ignored  
//            0,                     // no alpha buffer  
//            0,                     // shift bit ignored  
//            0,                     // no accumulation buffer  
//            0, 0, 0, 0,            // accum bits ignored  
//            24,                    // 32-bit z-buffer      
//            8,                     // if number is 0 = no stencil buffer  
//            0,                     // no auxiliary buffer  
//            PFD_MAIN_PLANE,        // main layer  
//            0,                     // reserved  
//            0, 0, 0                // layer masks ignored  
//        };
//        DC = GetDC(hwnd);
//        int pf = ChoosePixelFormat(DC, &pfd);
//        SetPixelFormat(DC, pf, &pfd);
//        RC = wglCreateContext(DC);
//        wglMakeCurrent(DC, RC);
//        glViewport(0, 0, 640, 480);
//        MessageBoxA(hwnd, (LPCSTR)glGetString(GL_VERSION), "GL VERSION", 0);
//    }
//    break;
//    case WM_KEYDOWN:
//        switch (wParam)
//        {
//        case 0x49:
//            MessageBoxA(hwnd, (LPCSTR)glGetString(GL_VERSION), "glwin", 0);
//            break;
//        default:
//            break;
//        }
//    case WM_PAINT:
//        Draw(DC);
//        break;
//    default:
//        break;
//    }
//    return DefWindowProc(hwnd, message, wParam,lParam);
//    //return CallWindowProcA(GLWinProc, hwnd, message, wParam, lParam);
//}