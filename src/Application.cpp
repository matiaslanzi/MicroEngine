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

    mPlayer.rect.x = 100;
    mPlayer.coll = 1;   // Collides with all


    mGround.rect.x = 0;
    mGround.rect.y = 400;
    mGround.rect.w = 8*64;
    mPlayer.coll = 1;
}

void Application::Input(){
    // Fires only if an event is available

    // Handle events
    switch (mEvent.type){
        case SDLK_ESCAPE:
            Quit();
            break;
        
        default:
            break;
    }
}

void Application::Update(){

    // Add gravity
    mPlayer.dy += cGravity;

    // Check collisions

    // Update position
    mPlayer.rect.x += mPlayer.dx;
    mPlayer.rect.y += mPlayer.dy;
}




void Application::Draw(){

    // Render object
    SDL_SetRenderDrawColor(mpRenderer, mGround.color.r, mGround.color.g, mGround.color.b, mGround.color.a);
    SDL_RenderDrawRect(mpRenderer, &mGround.rect);


    //Render Player
    SDL_SetRenderDrawColor(mpRenderer, mPlayer.color.r, mPlayer.color.g,mPlayer.color.b, mPlayer.color.a);
    SDL_RenderDrawRect(mpRenderer, &mPlayer.rect);
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
