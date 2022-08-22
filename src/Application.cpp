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
    mPlayer.rect.y = 80;
    mPlayer.rect.h = 8*2;
    mPlayer.coll = 1;   // Collides with all


    mGround.rect.x = 0;
    mGround.rect.y = 400;
    mGround.rect.w = 8*64;
    mPlayer.coll = 1;

    if(!checkCollisions(mPlayer.rect, mGround.rect)) mPlayer.FALLING = true;
    
}

void Application::Input(){
    // Fires only if an event is available

    // Handle events
    switch (mEvent.key.keysym.sym){
        case SDLK_ESCAPE:
            Quit();
            break;
        
        default:
            break;
    }
}

void Application::Update(){

    // Check collisions
    if(checkCollisions(mPlayer.rect, mGround.rect)){
        
        mPlayer.dy = -mPlayer.dy;
        
    }

    // Add gravity
    if(mPlayer.FALLING) mPlayer.dy += cGravity;

    // Limit speed
    if(mPlayer.dx > mPlayer.dxMax) mPlayer.dx = mPlayer.dxMax;
    if(mPlayer.dy > mPlayer.dyMax) mPlayer.dy = mPlayer.dyMax;

    // Update position
    mPlayer.rect.x += mPlayer.dx * miDeltaTime * 0.01f;
    mPlayer.rect.y += mPlayer.dy * miDeltaTime * 0.01f;
    
    
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
