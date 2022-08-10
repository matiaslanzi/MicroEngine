//
//  mlMiniEngine.hpp
//  SDLTest
//
//  Created by Matias Lanzi on 8/9/22.
//

#ifndef mlMiniEngine_h
#define mlMiniEngine_h

#include <stdio.h>
#include <SDL2/SDL.h>

class mlMiniEngine{

public:
    SDL_Window*     mpWindow = nullptr;
    SDL_Renderer*   mpRenderer = nullptr;
    SDL_Event       mEvent;
    
    float   mfSkipTicks = 1000/30;      // Frame rate
    Uint32  miDeltaTime = 0;            // Time between frames
    Uint32  miFrameFinish = 0;          // Last frame finish time
    Uint32  miFrameCount = 0;           // Accumulative counter
    
    mlMiniEngine();
    virtual ~mlMiniEngine(){};
    
    virtual void Update() = 0;
    virtual void Draw() = 0;
    
    void    Runloop();
    
private:
    bool    mRunning = false;
};

#endif /* mlMiniEngine_h */
