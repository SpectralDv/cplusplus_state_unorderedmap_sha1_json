


#include "StateIdle.h"



void StateIdle::CreateModelState(ModelState *mStateBack,ModelState *mStateBackAll)
{
    ModelState *mThisStateBack = new ModelState("back","idle",this); 
    ModelState *mThisStateBackIdle = new ModelState("backidle","idle",this); 

    umapState.emplace("cars",new ModelState("cars","����������",new StateCars(mThisStateBack,mThisStateBackIdle)));
    umapState.emplace("aircrafts",new ModelState("aircrafts","��������",nullptr));
    umapState.emplace("ships",new ModelState("ships","�������",nullptr));
}
//����� �� ������ ���������
void StateIdle::UpdateStateMap()
{
    
}

