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
    mJump = mLeft = mRight = 0;
}

/* ----- Input ----- */
void Application::Input(){
    // Fires only if an event is available

    if (mEvent.type == SDL_KEYDOWN)
    {
        switch (mEvent.key.keysym.sym){
            case SDLK_ESCAPE: Quit(); break;
            case SDLK_UP: mJump = true; break;
            case SDLK_LEFT: mLeft = true; break;
            case SDLK_RIGHT: mRight = true; break;
            case SDLK_SPACE: mJump = true;break;
            default: break;
        }
       
    }
    
    if(mEvent.type == SDL_KEYUP){
        switch (mEvent.key.keysym.sym){
            case SDLK_ESCAPE: Quit(); break;
            case SDLK_UP: mJump = false; break;
            case SDLK_LEFT: mLeft = false; break;
            case SDLK_RIGHT: mRight = false; break;
            case SDLK_SPACE: mJump = false; break;
            default: break;
        }
    }
}

/* ----- Update ----- */
void Application::Update(){    

}

/* ----- Draw ----- */
void Application::Draw(){

    // Clear the console
    trace("\033[2J");
    // Move cursor to the top
    trace("\033[H");

    trace("MicroEngine\n");
    trace("Frame count: % d\n", miFrameCount);
    trace("deltaTime: %f\n",mfDeltaTime);
    trace("Input: \n");
    if (mJump) trace("jump \n");
    if (mLeft) trace("left \n");
    if (mRight) trace("right \n");
}

/* ----- Destructor ----- */
// This is the main destructor for the parent class
// since it's a virtual function.

Application::~Application(){

    MicroEngine::Quit();
    
}







/* ------------------------------------------------------------------------- */
/*                                  main                                     */
/* ------------------------------------------------------------------------- */

int main(int argc, const char * argv[]) {
    
    Application* myApplication = new Application();

    myApplication->RunLoop();
    
    delete myApplication;

    myApplication = nullptr;
    
    return 0;
}
