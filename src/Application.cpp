//
//  Application.cpp
//  SDLTest
//
//  Created by Matias Lanzi on 8/9/22.
//

#include "Application.h"

Application::Application(){
    
}

Application::~Application(){
    
}

void Application::Update(){
    
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
    SDL_SetRenderDrawColor(mpRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(mpRenderer);
    
    SDL_SetRenderDrawColor(mpRenderer, 0x00, 0xff, 0xff, 0xff);
    //SDL_RenderDrawRect(mpRenderer, &theRect);
    SDL_RenderFillRect(mpRenderer, &theRect);
}

