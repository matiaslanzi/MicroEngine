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
}

void Application::Update(){
    // Update code

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
    //Draw code

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
