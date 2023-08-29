

#include "StateCars.h"


void StateCars::CreateModelState(ModelState *mStateBack,ModelState *mStateBackAll)
{
    ModelState *mThisState = new ModelState("this","cars",this);
    ModelState *mThisStateBack = new ModelState("back","cars",this);

    umapState.emplace("this",mThisState);
    umapState.emplace("bmw",new ModelState("bmw","BMV",nullptr));
    umapState.emplace("back",mStateBack);
}