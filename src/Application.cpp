//
//  Application.cpp
//  SDLTest
//
//  Created by Matias Lanzi on 8/9/22.
//
// Write your game here.

#include "Application.h"

Application::Application(){
    // Initialize mVars here
}

Application::~Application(){
    // Clean up
}

void Application::Update(){
    // Update code
    dy += gravity;
    
    theRect.x += dx;
    theRect.y += dy;
    
    if(dy > maxSpeed){
        dy = maxSpeed;
    }

    if(theRect.y > floor){
        dy = - dy;
    }
}

void Application::Draw(){
    //Draw code

    SDL_SetRenderDrawColor(mpRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(mpRenderer);
    
    SDL_SetRenderDrawColor(mpRenderer, 0x00, 0xff, 0xff, 0xff);
    SDL_RenderFillRect(mpRenderer, &theRect);
}

