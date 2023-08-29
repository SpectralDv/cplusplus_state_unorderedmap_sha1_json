
#ifndef _STATEIDLE_H_
#define _STATEIDLE_H_


#include "ModelState.h"
#include "StateBase.h"
#include "StateCars.h"


class StateIdle : public StateBase, public IState
{
public:
    //создает модель для возврата из других состояний в себя
    StateIdle(){name="StateIdle";CreateModelState(nullptr,nullptr);}
    ~StateIdle(){}
public:
    void CreateModelState(ModelState *mStateBack,ModelState *mStateBackAll) override;
    void UpdateState() override{}
    void UpdateStateMap() override;
    IState* UpdateMap();
    IState* UpdateState(ModelState* mState) override {return StateBase::FindMenuInMap(mState);}
    std::string GetName() override {return name;}
};

#endif