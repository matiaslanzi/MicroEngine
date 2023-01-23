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
};

#endif /* Application_h */
