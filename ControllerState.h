    

#ifndef _CONTROLLERSTATE_H_
#define _CONTROLLERSTATE_H_
    
#include "ModelState.h"

class ControllerState
{
public:
    //����� ���������
    IState *bufState;
    //������� ���������
    IState *state;
public:
    ControllerState();
    ~ControllerState(){}
    //��������� ������ � ������� ��� �������� � ������ ���������
    void EventLoop(ModelState *mState);
};


#endif