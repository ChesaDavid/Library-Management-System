#include "C:\Users\David\OneDrive\Documents\GitHub\Library-Management-System\App\Source Files\Header Files\Window.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch ((uMsg)){
        case WM_CLOSE:
            DestroyWindow(hWnd);
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

Window::Window()
    : m_hInstance(GetModuleHandle(nullptr))
{
    const wchar_t* CLASS_NAME = L"Library Management System Class";
    WNDCLASS wndClass = {};
    wndClass.lpszClassName = "Library Management System Class";
    wndClass.hInstance = m_hInstance;
    wndClass.hIcon = LoadIcon(NULL , IDI_WINLOGO);
    wndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
    wndClass.lpfnWndProc = WindowProc;

    RegisterClass(&wndClass);
    
    DWORD style = WS_CAPTION | WS_MINIMIZE | WS_SYSMENU;

    int width = 640;
    int hight = 480;

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + hight;

    AdjustWindowRect(&rect ,style, false);

    m_hWnd = CreateWindowEx(
        0,
        wndClass.lpszClassName,
        "Library Management System",
        style,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        m_hInstance,
        NULL
    );

    ShowWindow(m_hWnd, SW_SHOW);
}

bool Window::ProcessMasseges()
{
    MSG msg ={};
    while(PeekMessage(&msg,nullptr,0u,0u,PM_REMOVE)){
        if(msg.message == WM_QUIT){
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}

Window::~Window()
{
    const wchar_t* CLASS_NAME = L"Library Management System Class";
    UnregisterClass("Library Management System Class", m_hInstance);
}
