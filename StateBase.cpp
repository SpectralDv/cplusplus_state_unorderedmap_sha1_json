
#include "Sha1.h"
#include "StateBase.h"
#include "ModelState.h"

//хранит класс с реализацией поиска состояний
std::string GetNameState(){return "namestate";}

void StateBase::UpdateDataFromFile(std::string nameFile,std::string nameState)
{
    //проверят файл на изменения
    //если хеш файла отличается, делаем обновление моделей
    for (auto it = umapState.begin(); it != umapState.end(); it++)
    {
        it->second->UpdatDataFromFile(nameFile,nameState);
    }
}
IState* StateBase::FindMenuInMap(ModelState *mState)
{
    if(umapState.empty()){return nullptr;}

    auto it = umapState.find(GetNameState());

    if(it != umapState.end())
    {
        //надо бы переделаеть переход через OnEnter()
        it->second->state->UpdateStateMap(); 
        return it->second->state;
    }

    //остался в своем состоянии
    return nullptr;
}
//переход в состояние
void StateBase::UpdateStateMap()
{
    UpdateHashFile(umapState.begin()->second->strData);
}
void StateBase::UpdateHashFile(std::string nameMenu)
{
    //проверят хеш файла на изменения
    //обновляет текущую модель состояния данными из файла
    bufHash = sha1(ModelReadFile::GetReadFile("state.json"));
    if(strHash != bufHash)
    {
        strHash = bufHash; 
        UpdateDataFromFile("state.json",nameMenu);
    }
}
