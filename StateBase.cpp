
#include "Sha1.h"
#include "StateBase.h"
#include "ModelState.h"

//������ ����� � ����������� ������ ���������
std::string GetNameState(){return "namestate";}

void StateBase::UpdateDataFromFile(std::string nameFile,std::string nameState)
{
    //�������� ���� �� ���������
    //���� ��� ����� ����������, ������ ���������� �������
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
        //���� �� ����������� ������� ����� OnEnter()
        it->second->state->UpdateStateMap(); 
        return it->second->state;
    }

    //������� � ����� ���������
    return nullptr;
}
//������� � ���������
void StateBase::UpdateStateMap()
{
    UpdateHashFile(umapState.begin()->second->strData);
}
void StateBase::UpdateHashFile(std::string nameMenu)
{
    //�������� ��� ����� �� ���������
    //��������� ������� ������ ��������� ������� �� �����
    bufHash = sha1(ModelReadFile::GetReadFile("state.json"));
    if(strHash != bufHash)
    {
        strHash = bufHash; 
        UpdateDataFromFile("state.json",nameMenu);
    }
}
