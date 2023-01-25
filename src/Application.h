//
//  Application.hpp
//
//  Created by Matias Lanzi on 8/9/22.
//


#ifndef Application_h
#define Application_h

#include <stdio.h>
#include "mlMicroEngine.h"

class Application : public ml::MicroEngine{
    // The application subclasses the engine.
    // Provide Input, Update and Draw methods.

public:
    Application();
    ~Application();

    void Input();
    void Update();
    void Draw();

private:
};

#endif /* Application_h */
