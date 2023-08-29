


#include "StateIdle.h"



void StateIdle::CreateModelState(ModelState *mStateBack,ModelState *mStateBackAll)
{
    ModelState *mThisStateBack = new ModelState("back","idle",this); 
    ModelState *mThisStateBackIdle = new ModelState("backidle","idle",this); 

    umapState.emplace("cars",new ModelState("cars","αχτονοβιμι",new StateCars(mThisStateBack,mThisStateBackIdle)));
    umapState.emplace("aircrafts",new ModelState("aircrafts","σανομετω",nullptr));
    umapState.emplace("ships",new ModelState("ships","λοςαβμι",nullptr));
}
//ΧΩΘΟΔ ΙΪ ΜΐΒΟΗΟ ΣΟΣΤΟΡΞΙΡ
void StateIdle::UpdateStateMap()
{
    
}

