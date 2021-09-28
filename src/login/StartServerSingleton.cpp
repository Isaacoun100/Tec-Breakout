#include "StartServerSingleton.h"

StartServerSingleton *StartServerSingleton::m_StartServerSingleton;

StartServerSingleton *StartServerSingleton::GetInstance() {
    if(m_StartServerSingleton==nullptr)
        m_StartServerSingleton = new (nothrow) StartServerSingleton;
    return m_StartServerSingleton;
}

void StartServerSingleton::deleteInstance() {
    if(m_StartServerSingleton){
        delete m_StartServerSingleton;
        m_StartServerSingleton= nullptr;
    }
}

void StartServerSingleton::Print() {
    cout<< "My instance memory address is:" << this << endl;
}

StartServerSingleton::StartServerSingleton() {
    cout<<"Constructor"<<endl;
}

StartServerSingleton::~StartServerSingleton() {
    cout<<"Destructive function"<<endl;
}
