#include "AppWindow.h"

#include "Window.h"
Window* window = nullptr;
Window::Window(){

}
LRESULT CALLBACK WindProc(HWND hwnd,UINT msg, WPARAM wparam,LPARAM lparam){

switch (msg){
    case WM_CREATE:
    {   window->onCreate();
        break;
    }
    case WM_DESTROY:
    {   window->onDestroy();
        ::PostQuitMessage(0);
        break;
    }
    default:
    {
        return ::DefWindowProc(hwnd,msg,wparam,lparam);
    }

}
return NULL;


}
bool Window::init(){

    WNDCLASSEX wd;
    wd.cbClsExtra = NULL;
    wd.cbSize = sizeof(WNDCLASSEX);
    wd.cbWndExtra = NULL;
    wd.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wd.hCursor = LoadCursor(NULL,IDC_ARROW);
    wd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wd.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
    wd.hInstance = NULL;
    wd.lpszClassName = "LibraryWindowClass";   
    wd.lpszMenuName = "";
    wd.style = NULL;
    wd.lpfnWndProc = WindProc;

    if(!::RegisterClassEx(&wd)){
        return false;
    }   
    if(!window){
        window = this;
    }
    
    m_hwnd- ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,"LibraryWindowClass","Library Management System",WS_EX_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,1024,768,
        NULL,NULL,NULL,NULL);   

    if(!m_hwnd){
        return false;
    }
    return  true;
    ::ShowWindow(m_hwnd,SW_SHOW);
    ::UpdateWindow(m_hwnd);

    
    m_is_run =true;

    return true;
}

bool Window::broadcast(){
    MSG msg;
    
    while(::PeekMessage(&msg,NULL,0,0,PM_REMOVE)>0){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    window->onUpdate();
    
    Sleep(0);

    return true;

}

bool Window::release(){
    if(!::DestroyWindow(m_hwnd)){
        return false;
    }

    return true;
}
bool Window::isRun(){
    return m_is_run;
}
void Window::onDestroy(){
    m_is_run = false;
}
Window::~Window()
{

}

AppWindow::AppWindow(){

}
AppWindow::~AppWindow(){

}
void AppWindow::onCreate(){

 }
void AppWindow::onUpdate(){

}
void AppWindow::onDestroy(){
    Window::onDestroy();
}

int main(){
    AppWindow app;
    if(app.init()){
        while(app.isRun()){
            app.broadcast();
        }
    }
    return 0;
}