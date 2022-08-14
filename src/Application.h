//
//  Application.hpp
//
//  Created by Matias Lanzi on 8/9/22.
//


#ifndef Application_h
#define Application_h

#include <stdio.h>
#include "mlMicroEngine.h"

class Application : public mlME::mlMicroEngine{
public:
    Application();
    ~Application();

    void Input();
    void Update();
    void Draw();
    
private:
    // TODO: @matiaslanzi Initializing here might be bad
    SDL_Rect theRect;
    
    int     floor;
    float   gravity;
    
    float   dx, dy;
    float   maxSpeed;
    
};

#endif /* Application_h */
