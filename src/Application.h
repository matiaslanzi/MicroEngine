//
//  Application.hpp
//  SDLTest
//
//  Created by Matias Lanzi on 8/9/22.
//

#ifndef Application_h
#define Application_h

#include <stdio.h>
#include "mlMiniEngine.h"

class Application : public mlMiniEngine{
public:
    Application();
    ~Application();

    void Update();
    void Draw();
    
private:
    SDL_Rect theRect = {100,100,100,100};
    
    int floor = 370;
    float gravity = .8f;
    
    SDL_Rect    mBoxRect{320,40,100,100};
    float   dx, dy = 0;
    float   maxSpeed = 20;
    
};

#endif /* Application_h */
