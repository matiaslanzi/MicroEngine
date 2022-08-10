//
//  mlMicroEngine.h
//
//  Created by Matias Lanzi on 8/9/22.
//

#ifndef mlMicroEngine_h
#define mlMicroEngine_h

#include <stdio.h>
#include <SDL2/SDL.h>

class mlMicroEngine{

public:
    SDL_Window*     mpWindow = nullptr;
    SDL_Renderer*   mpRenderer = nullptr;
    SDL_Event       mEvent;
    
    float   mfSkipTicks = 1000/30;      // Frame rate
    Uint32  miDeltaTime = 0;            // Time between frames
    Uint32  miFrameFinish = 0;          // Last frame finish time
    Uint32  miFrameCount = 0;           // Accumulative counter
    
    mlMicroEngine();
    virtual ~mlMicroEngine(){};
    
    virtual void Update() = 0;
    virtual void Draw() = 0;
    
    void    Runloop();
    
private:
    bool    mRunning = false;
};

#endif /* mlMicroEngine_h */
