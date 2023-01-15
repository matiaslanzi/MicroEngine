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
    mPlayer.jumpVel = 20;
    mPlayer.coll = 1;   // Collides with all


    mGround.rect.x = 0;
    mGround.rect.y = 400;
    mGround.rect.w = 8*80;
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
        case SDLK_SPACE:
        case SDLK_w:
            mPlayer.JUMP = true;
            break;
        case SDLK_a:
        case SDLK_LEFT:
            mDir = mlME::LEFT;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            mDir = mlME::RIGHT;
            break;
        default:
            break;
    }
}

void Application::Update(){

    // Check collisions
    if(checkCollisions(mPlayer.rect, mGround.rect)){
        mPlayer.dy = -mPlayer.dy;
        mPlayer.FALLING = false;
        mPlayer.GROUNDED = true;
        mPlayer.dy = 0;
        mPlayer.rect.y = mGround.rect.y - mPlayer.rect.h;
    }

    // Jump
    if(mPlayer.JUMP){
        mPlayer.dy = -mPlayer.jumpVel;
        mPlayer.FALLING = true;
        mPlayer.GROUNDED = false;

        mPlayer.JUMP = false;
    }

    // Move
    if(mDir == mlME::LEFT){
        mPlayer.dx += -mPlayer.latVel;
        mDir = mlME::NONE;
    }

    if(mDir == mlME::RIGHT){
        mPlayer.dx += mPlayer.latVel;
        mDir = mlME::NONE;
    }

    // Gravity
    if(mPlayer.FALLING) mPlayer.dy += cGravity;
    
    // Friction
    if(mPlayer.dx != 0) mPlayer.dx *= 0.95f;
    
    // Limit speed
    if(mPlayer.dx > mPlayer.dxMax) mPlayer.dx = mPlayer.dxMax;
    if(mPlayer.dy > mPlayer.dyMax) mPlayer.dy = mPlayer.dyMax;

    // Stay in bounds
    if(mPlayer.rect.x + mPlayer.rect.w >= 640){
        mPlayer.rect.x += -1;
        mPlayer.dx = -mPlayer.dx;
    }

    if(mPlayer.rect.x <= 0){
         mPlayer.rect.x += 1;  
         mPlayer.dx = -mPlayer.dx;
    }

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




/* ----- Destructor ----- */
// This is the main destructor for the parent class
// since it's a virtual function.

Application::~Application(){
    
    if(mpRenderer != nullptr){
        SDL_DestroyRenderer(mpRenderer);
        mpRenderer = nullptr;
    }

    if(mpWindow != nullptr){
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
