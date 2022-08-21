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
    float const cGravity = 1.98f;

    struct MEEntity{

        SDL_Rect rect = {0,0,8,8};  // The object's rect
        float   dx = 0.0f;  // delta x is the rate of change for x
        float   dy = 0.0f;  // delta y is the rate of change for y

        SDL_Color color = {0xff, 0xff, 0xff, 0xff};     // The draw color

        // Collisions 0 = no collisions, 1 = collides, > 1 collision groups.
        int    coll = true;

        // Here I define some flags, feel free to use any other method or add
        // any needed flags.
        bool    TOUCHGROUND = false;
        bool    GROUNDED = false;
        bool    JUMPING = false;
        bool    FIRING = false;
        bool    FALLING = false;
    };

    struct MEEntity mPlayer;
    struct MEEntity mGround;
};

#endif /* Application_h */
