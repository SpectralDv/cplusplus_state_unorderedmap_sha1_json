
#include "ControllerState.h"


int main()
{
    ControllerState cState;

    cState.EventLoop(new ModelState("idle","",nullptr));

    return 0;
}



