#include <iostream>
#include "C:\Users\David\OneDrive\Documents\GitHub\Library-Management-System\App\Source Files\Header Files\Window.h"

int main(){
    std::cout<<" Creating Window\n";
    Window* pWindow = new Window();
    bool running =true;
    while (running){
        if(!pWindow->ProcessMasseges()){
            std::cout<<"Closing Window\n";
            running =false;
        }
        Sleep(10);
    }
    delete pWindow;
    return 0;
}