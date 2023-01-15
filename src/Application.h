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
    float const cGravity = 0.98f;

    struct MEEntity{

        SDL_Rect    rect = {0,0,8,8};   // The object's rect
        float       dx = 0.0f;          // delta x is the rate of change for x
        float       dy = 0.0f;          // delta y is the rate of change for y
        float       dxMax = 50;         // Maximum x velocity
        float       dyMax = 50;         // Maximum y velocity
        float       jumpVel = 50;       // Jump velocity
        float       latVel  = 10;       // Lateral velocity
        float       gravity = 1;        // Gravity multiplier

        SDL_Color color = {0xff, 0xff, 0xff, 0xff};     // The draw color

        // Collisions 0 = no collisions, 1 = collides, > 1 collision groups.
        int    coll = true;
        bool    FALLING = false;
        bool    JUMP = false;
        bool    GROUNDED = false;
    };

    struct MECamera{
        SDL_Rect rect = {0,0,0,0};
    };


    struct MEEntity mPlayer;
    struct MEEntity mGround;
};

#endif /* Application_h */
