

#include "ControllerState.h"
#include "StateIdle.h"


ControllerState::ControllerState(){state = new StateIdle();}
//��������� ������ � ������� ��� �������� � ������ ���������
void ControllerState::EventLoop(ModelState *mStateData)
{
    //���� ���� ��������� ����� ������� � ����
    bufState = state->UpdateState(mStateData);
    if(bufState != nullptr){state = bufState;}
    delete mStateData; //����� �� ������� � UpdateState(ModelState)
}
