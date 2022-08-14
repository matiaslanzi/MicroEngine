//
//  Application.cpp
//
//  Created by Matias Lanzi on 8/9/22.
//
// This is the application, this is where you write your game code.
// The constructor get called once, Update() and Draw() get called at 
// the defined frame rate in mlMicroEngine.h
//

#include "Application.h"

Application::Application(){
    // Initialize mVars here
    
    theRect = {100,100,100,100};
    floor = 370;
    gravity = .8f;
    dx = 0; 
    dy = 0;
    maxSpeed = 20;
}

void Application::Input(){
    // Fires only if an event is available
    switch (mEvent.type)
    {
    case SDLK_ESCAPE:
        Quit();
        break;
    
    default:
        break;
    }
}

void Application::Update(){

    // Add gravity
    dy += gravity;
    
    // Cap frame rate
    if(dx > maxSpeed) dx = maxSpeed;
    if(dy > maxSpeed) dy = maxSpeed;

    theRect.x += dx;
    theRect.y += dy;

    //Floor collision
    if(theRect.y > floor) dy = - dy;
    
}

void Application::Draw(){

    SDL_SetRenderDrawColor(mpRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(mpRenderer);
    
    SDL_SetRenderDrawColor(mpRenderer, 0x00, 0xff, 0x00, 0xff);
    SDL_RenderFillRect(mpRenderer, &theRect);
}

Application::~Application(){
    if(mpRenderer){
        SDL_DestroyRenderer(mpRenderer);
        mpRenderer = nullptr;
    }

    if(mpWindow){
        SDL_DestroyWindow(mpWindow);
        mpWindow = nullptr;
    }

    SDL_Quit();
}

int main(int argc, const char * argv[]) {
    
    Application* myApplication = new Application();

    myApplication->Runloop();
    
    delete myApplication;

    myApplication = nullptr;
    
    return 0;
}
