    

#ifndef _CONTROLLERSTATE_H_
#define _CONTROLLERSTATE_H_
    
#include "ModelState.h"

class ControllerState
{
public:
    //буфер состояния
    IState *bufState;
    //текущее состояние
    IState *state;
public:
    ControllerState();
    ~ControllerState(){}
    //принимает объект с данными для перехода в другое состояние
    void EventLoop(ModelState *mState);
};


#endif