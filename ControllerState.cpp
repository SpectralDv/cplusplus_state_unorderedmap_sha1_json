

#include "ControllerState.h"
#include "StateIdle.h"


ControllerState::ControllerState(){state = new StateIdle();}
//принимает объект с данными для перехода в другое состояние
void ControllerState::EventLoop(ModelState *mStateData)
{
    //ищет меню состояния чтобы перейти в него
    bufState = state->UpdateState(mStateData);
    if(bufState != nullptr){state = bufState;}
    delete mStateData; //чтобы не удалять в UpdateState(ModelState)
}
