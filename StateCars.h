
#ifndef _STATECARS_H_
#define _STATECARS_H_


#include "ModelState.h"
#include "StateBase.h"


class StateCars : public StateBase, public IState
{
public:
    //создает модель для возврата из других состояний в себя
    StateCars(ModelState *mStateBack,ModelState *mStateBackAll){name="StateIdle";CreateModelState(mStateBack,mStateBackAll);}
    ~StateCars(){}
public:
    void CreateModelState(ModelState *mStateBack,ModelState *mStateBackAll) override;
    void UpdateState() override{}
    void UpdateStateMap() override;
    IState* UpdateMap();
    IState* UpdateState(ModelState* mState) override {return StateBase::FindMenuInMap(mState);}
    std::string GetName() override {return name;}
};

#endif