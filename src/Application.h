//
//  Application.hpp
//
//  Created by Matias Lanzi on 8/9/22.
//


#ifndef Application_h
#define Application_h

#include <stdio.h>
#include "mlMicroEngine.h"

class Application : public mlMicroEngine{
public:
    Application();
    ~Application();

    void Update();
    void Draw();
    
private:
    // TODO: @matiaslanzi Initializing here might be bad
    SDL_Rect theRect = {100,100,100,100};
    
    int floor = 370;
    float gravity = .8f;
    
    float   dx, dy = 0;
    float   maxSpeed = 20;
    
};

#endif /* Application_h */
