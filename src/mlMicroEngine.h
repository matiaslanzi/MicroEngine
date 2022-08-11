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
    
    float       mfSkipTicks = 1000/30;      // Frame rate
    Uint32      miDeltaTime = 0;            // Time between frames, use this to compensate for timing.
    Uint32      miFrameFinish = 0;          // Last time a frame finished rendering
    Uint32      miFrameCount = 0;           // Accumulative counter
    // TODO: @matiaslanzi Initializing here might be bad, I will research that later (initialization list).
    // I'm just not to happy about the convoluted way to initialize, but I guess mostly the .h
    // files should only contain headers and not initialization or data.
    
    mlMicroEngine();
    virtual ~mlMicroEngine(){};
    
    virtual void Update() = 0;
    virtual void Draw() = 0;
    
    void    Runloop();
    
private:
    bool    mRunning = false;
};

#endif /* mlMicroEngine_h */
