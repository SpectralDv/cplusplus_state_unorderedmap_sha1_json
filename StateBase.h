

#ifndef _STATEBASE_H_
#define _STATEBASE_H_

#include "ModelState.h"



class StateBase
{
protected:
    std::string bufHash;
    std::string strHash;
    std::string name;
    std::unordered_map<std::string,ModelState*> umapState;
public:
    StateBase(){}
    ~StateBase(){}
public:
    void UpdateDataFromFile(std::string nameFile,std::string nameState);
    //поиск состояния в списке следующих и предыдущих состояний
    IState* FindMenuInMap(ModelState *mState);
    void UpdateStateMap();
    void UpdateHashFile(std::string nameFile);
    void OnEnter(){};
    void OnExit(){};
};

#endif