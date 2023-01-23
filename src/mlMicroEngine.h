#ifndef MLMICROENGINE_H
#define MLMICROENGINE_H

#pragma region license_and_help
/*  
    mlMicroEngine.h

 Created by Matias Lanzi on 8/9/22.

This is a first pass at attempting to make a basic mini game engine
with SDL that can get me going quicly without much fuzz.
You should be able to compile this in any platform with make.
Read the docs for details.

https://github.com/matiaslanzi/MicroEngine
*/
#pragma endregion




#pragma region version_history
/*
 * 230115 @TODO: we might want to move this section to a separate file
 * 230115 @TODO: implement DearIamGui for gui elements and debuging
 * 230115 @TODO: implement openGL
 */
#pragma endregion





#pragma region includes
/* ------------------------------------------------------------------------- */
/*                                  Includes                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <SDL2/SDL.h>

#pragma endregion





#pragma region defines
/* ------------------------------------------------------------------------- */
/*                                  Defines                                  */
/* ------------------------------------------------------------------------- */
/* Settings here                                                             */

#define DEBUG
#define ME_FPS 24
#define ME_WIN_WIDTH 640
#define ME_WIN_HEIGHT 480
#define ME_WIN_TITLE "Untitled"

#ifdef DEBUG
#define trace(...) printf( __VA_ARGS__ )
#else
#define trace(...)
#endif

#pragma endregion


/* ------------------------------------------------------------------------- */
/*                             Interface declaration                         */
/* ------------------------------------------------------------------------- */

namespace mlME{

    class mlMicroEngine{
    public:
        SDL_Window*     mpWindow = nullptr;
        SDL_Renderer*   mpRenderer = nullptr;   
        SDL_Event       mEvent;                     // The event
        
        Uint32      mfSkipTicks = 1000.f/ME_FPS;    // Frame duration in ms acording to frame rate
        float       mfDeltaTime = 0;                // Time between frames, in seconds.
        Uint32      miFrameFinish = 0;              // Last time a frame finished rendering
        Uint32      miFrameCount = 0;               // Accumulative counter
    
        mlMicroEngine();
        virtual ~mlMicroEngine(){};
        
        virtual void Input() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;

        bool    checkCollisions(SDL_Rect& a, SDL_Rect& b);  // Move this to physics class
        void    Runloop();
        void    Quit();
      
    private:
        bool    mRunning = false;
    };

}










/* ------------------------------------------------------------------------- */
/*                             Implementation                                */
/* ------------------------------------------------------------------------- */

namespace mlME{

    /* ----- Constructor ----- */
    mlMicroEngine::mlMicroEngine(){
        // TODO: @matiaslanzi Overload the constructor to take parameters x, y, framerate and title.

        // Init SDL
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
            printf("mlMicroEngine: Can't initialize SDL.\n%s", SDL_GetError());
            exit(-1);
        }
        
        // Make window
        mpWindow = SDL_CreateWindow(ME_WIN_TITLE,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    ME_WIN_WIDTH,
                                    ME_WIN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
        if(!mpWindow){
            printf("mlMicroEngine: Can't create SDL window.\n%s", SDL_GetError());
            exit(-1);
        }
        
        // Make renderer
        mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        
        if(!mpWindow){
            printf("mlMicroEngine: Can't create SDL renderer.\n%s", SDL_GetError());
            exit(-1);
        }
        
        
        SDL_SetRenderDrawColor(mpRenderer, 0xff, 0x00, 0x00, 0xff);

        // Initialize the last frame time.
        miFrameFinish = SDL_GetTicks();

        mRunning = true;
    }

    /* ----- CheckCollisions ----- */
    // @TODO:Move this to utilities or physics class

    bool mlMicroEngine::checkCollisions(SDL_Rect& a, SDL_Rect& b){
        if(((a.x + a.w) >= b.x && a.x <= (b.x + b.w)) && ((a.y + a.h) >= b.y && a.y <= (b.y + b.h)))
            return true;

        return false;
    }


    /* ----- Run loop ----- */
    void mlMicroEngine::Runloop(){
        
        // Run the loop
        while (mRunning) {

            if(SDL_GetTicks() > miFrameFinish + mfSkipTicks){ // Cap the frame rate

                if(SDL_PollEvent(&mEvent)){
                    if(mEvent.type == SDL_QUIT) mRunning = false;

                    Input();    // Only fire if an event was received
                }
                
                Update();

                SDL_SetRenderDrawColor(mpRenderer, 0x00, 0x00, 0x00, 0x00);
                SDL_RenderClear(mpRenderer);
                Draw();
                SDL_RenderPresent(mpRenderer);
                
                miFrameCount++;
                mfDeltaTime = (SDL_GetTicks() - miFrameFinish) / 1000.f;  // Calculate deltaTime in seconds
                miFrameFinish = SDL_GetTicks();
            }
            
            SDL_Delay(1);
        }
    }

    /* ----- Quit ----- */
    void mlMicroEngine::Quit(){
        trace("mlMicroEngine::Quit\n");

        mRunning = false;

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
}

#endif /* mlMicroEngine_h */
