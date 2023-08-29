
#ifndef _MODELSTATE_H_
#define _MODELSTATE_H_

#include <iostream>
#include <vector>
#include <unordered_map>

#include "RegexJson.h"


class ModelState;
class IState
{
public:
    int baseid;
public:
    virtual ~IState(){}
public:
    //virtual void OnEnter(){}
    //virtual void OnExit(){}
    //реализация перехода в собственное состояние
    virtual void UpdateState();
    virtual void UpdateStateMap();
    //реализация перехода в другое состояния
    virtual IState* UpdateState(ModelState *mState);
    //заполенение меню, принимает модель для выхода в предыдущее и выхода отовсюду
    virtual void CreateModelState(ModelState *mStateBack,ModelState *mStateBackAll);
    //
    virtual std::string GetName();
};



/////////////////////////////////////////////////////////
class ModelState 
{
public:
    std::string nameState;  
    std::string strData;
    int val;
    IState *state;          
public:
    ModelState(std::string namestate,std::string strdata,IState *istate) : 
    nameState(namestate),strData(strdata),state(istate){}
    ~ModelState(){delete state;}
    int UpdatDataFromFile(std::string nameFile,std::string nameState)
    {
        val = RegexJson::TakeNumberFromFile(nameFile,nameState);
        return val;
    }
};



#endif