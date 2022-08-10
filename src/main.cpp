//
//  main.cpp
//  SDLTest
//
//  Created by Matias Lanzi on 8/9/22.
//
#include "Application.h"
#include <thread>

int main(int argc, const char * argv[]) {
    
    Application* myApplication = new Application();

    myApplication->Runloop();
    
    delete myApplication;

    myApplication = nullptr;
    
    return 0;
}
