#ifndef MLMICROENGINE_H
#define MLMICROENGINE_H

#pragma region license_and_help
/* mlMicroEngine.h
Created by Matias Lanzi on 8/9/22.
This is a first pass at attempting to make a basic mini game engine
with SDL that can get me going quicly without much fuzz.
You should be able to compile this in any platform with make.
Read the docs for details.
https://github.com/matiaslanzi/MicroEngine
*/
#pragma endregion




#pragma region version_history
/* 230115 @TODO: implement DearIamGui for gui elements and debuging
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

namespace ml{

    struct vector2D{ float x, y; };
    struct vector3D{ float x, y, z; };

    bool CheckCollisions(SDL_Rect& a, SDL_Rect& b);

    /* ----- MicroEngine---------------------------------------------------- */
    class MicroEngine{
    public:
        // Move this to Graphics class
        SDL_Window*     mpWindow = nullptr;
        SDL_Renderer*   mpRenderer = nullptr;   

        // Move this to Input class
        SDL_Event       mEvent;                     // The event
        
        // Move this to Time class
        Uint32      mfSkipTicks = 1000.f/ME_FPS;    // Frame duration in ms acording to frame rate
        float       mfDeltaTime = 0;                // Time between frames, in seconds.
        Uint32      miFrameFinish = 0;              // Last time a frame finished rendering
        Uint32      miFrameCount = 0;               // Accumulative counter
    
        MicroEngine();
        virtual ~MicroEngine(){};
        
        virtual void Input() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;

        void    Runloop();
        void    Quit();
      
    private:
        bool    mRunning = false;
    };

    /* ----- Graphics ------------------------------------------------------ */
    class Graphics{
        public:
            SDL_Window*     mpWindow = nullptr;
            SDL_Renderer*   mpRenderer = nullptr;   
        private:
    };

    /* ----- Input --------------------------------------------------------- */
    class Input{
        public:
            SDL_Event   mEvent;
        private:
    };

    /* ----- Time ---------------------------------------------------------- */
    class Time{
        public:
            Uint32      mfSkipTicks = 1000.f/ME_FPS;    // Frame duration in ms acording to frame rate
            float       mfDeltaTime = 0;                // Time between frames, in seconds.
            Uint32      miFrameFinish = 0;              // Last time a frame finished rendering
            Uint32      miFrameCount = 0;               // Accumulative counter
        private:
    };

    /* ----- Texture ------------------------------------------------------- */
    class Texture{
        public:
            SDL_Texture* mpTexture;
        private:
    };

    /* ----- Entity ---------------------------------------------------------*/
    class Entity{
        SDL_Rect    mRect = {0,0,0,0};
        SDL_Rect    mClipRect = {0,0,0,0};
        float       mXVel, mYVel = 0;
        
    };
}


/* ------------------------------------------------------------------------- */
/*                             Implementation                                */
/* ------------------------------------------------------------------------- */

namespace ml{

    /* ----- Constructor ----- */
    MicroEngine::MicroEngine(){

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

        // Initialize the last frame time and delta time.
        miFrameFinish = SDL_GetTicks();
        mfDeltaTime = mfSkipTicks;

        mRunning = true;
    }



    /* ----- Run loop ----- */
    void MicroEngine::Runloop(){
        
        // Run the loop as fast as possible!
        while (mRunning) {

            if(SDL_GetTicks() > miFrameFinish + mfSkipTicks){ // Cap the frame rate 

                // Handle input
                if(SDL_PollEvent(&mEvent)){     // Only fire if an event was received
                    if(mEvent.type == SDL_QUIT){ 
                        mRunning = false;
                        return;
                    }
                    
                    Input();    // Delegate to the application, inspect mEvent it's an SDL_Event.
                }
                
                // Handle Update
                Update();       // Delegate to the application.

                // Handle Render
                SDL_SetRenderDrawColor(mpRenderer, 0x00, 0x00, 0x00, 0x00);
                SDL_RenderClear(mpRenderer);
                Draw();         // Delegate to the application.
                SDL_RenderPresent(mpRenderer);
                
                // Increment frame, calculate delta time and stamp frame finish.
                miFrameCount++;
                mfDeltaTime = (SDL_GetTicks() - miFrameFinish) / 1000.f;  // Calculate deltaTime in seconds
                miFrameFinish = SDL_GetTicks();
            }
            
            SDL_Delay(1);   // Let the processor breathe
        }
    }

    /* ----- Quit ----- */
    void MicroEngine::Quit(){

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

    /* ----- CheckCollisions ----- */
    bool CheckCollisions(SDL_Rect& a, SDL_Rect& b){
        if(((a.x + a.w) >= b.x && a.x <= (b.x + b.w)) && ((a.y + a.h) >= b.y && a.y <= (b.y + b.h)))
            return true;
        return false;
    }
}

#endif /* mlMicroEngine_h */
