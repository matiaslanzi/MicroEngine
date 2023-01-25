//  Application.cpp
//
//  Created by Matias Lanzi on 8/9/22.
//
// This is the application, this is where you write your game code.
// The constructor get called once, Update() and Draw() get called at 
// the defined frame rate in mlMicroEngine.h

#include "Application.h"



/* ----- Constructor ----- */
Application::Application(){

    
}

/* ----- Input ----- */
void Application::Input(){
    // Fires only if an event is available
    switch (mEvent.key.keysym.sym){
        case SDLK_ESCAPE: Quit(); break;
        default: break;
    }
}

/* ----- Update ----- */
void Application::Update(){    
    
}

/* ----- Draw ----- */
void Application::Draw(){
    // Clear the cosole
    trace("\033[2J");
    // Move cursor to the top
    trace("\033[H");
    trace("MicroEngine\n");
    trace("Frame count: % d \n", miFrameCount);
    trace("deltaTime: %f\n",mfDeltaTime);
}


/* ----- Destructor ----- */
// This is the main destructor for the parent class
// since it's a virtual function.

Application::~Application(){

    MicroEngine::Quit();
    
}



/* ----- main ----- */
int main(int argc, const char * argv[]) {
    
    Application* myApplication = new Application();

    myApplication->RunLoop();
    
    delete myApplication;

    myApplication = nullptr;
    
    return 0;
}
