//
//  mlMiniEngine.cpp
//  SDLTest
//
//  Created by Matias Lanzi on 8/9/22.
//
// This is a first pass at attempting to make a simple mini engine
// than can get me going quicly without much fuzz.
// Read the docs for details.

#include "mlMiniEngine.h"

/* ----- Constructor ----- */
mlMiniEngine::mlMiniEngine(){
    
    printf("mlMiniEngine: Started");
    
    // Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("mlMiniEngine: Can't initialize SDL.\n%s", SDL_GetError());
        exit(-1);
    }
    
    // Make window
    mpWindow = SDL_CreateWindow("Untitled",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                640,
                                480,
                                SDL_WINDOW_SHOWN);
    if(!mpWindow){
        printf("mlMiniEngine: Can't create SDL window.\n%s", SDL_GetError());
        exit(-1);
    }
    
    // Make renderer
    mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if(!mpWindow){
        printf("mlMiniEngine: Can't create SDL renderer.\n%s", SDL_GetError());
        exit(-1);
    }
    
    
    SDL_SetRenderDrawColor(mpRenderer, 0xff, 0x00, 0x00, 0xff);

    // Initialize the last frame time.
    miFrameFinish = SDL_GetTicks();
    
    mRunning = true;
}







/* ----- Run loop ----- */
void mlMiniEngine::Runloop(){
    
    // Run the loop
    while (mRunning) {
        
        // Cap the fps
        if(SDL_GetTicks() > miFrameFinish + mfSkipTicks){

            if(SDL_PollEvent(&mEvent)){
                if(mEvent.type == SDL_QUIT) mRunning = false;
            }
            
            // Examine mEvent.type to handle events in child class.
            
            Update();

            Draw();
            SDL_RenderPresent(mpRenderer);
            
            miFrameCount++;
            miDeltaTime = SDL_GetTicks() - miFrameFinish;
            miFrameFinish = SDL_GetTicks();
        }
        
        SDL_Delay(1);
    }
}
