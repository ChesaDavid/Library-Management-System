#pragma once
#include <windows.h>

class Window{
public:
    Window();
    //Initialize the Window
    bool init();
    bool broadcast();
    bool isRun();
    //Release the Window
    bool release();
    ~Window();
    virtual void onCreate()=0;
    virtual void onUpdate()=0;
    virtual void onDestroy()=0;


protected:
    HWND m_hwnd;
    bool m_is_run;
};