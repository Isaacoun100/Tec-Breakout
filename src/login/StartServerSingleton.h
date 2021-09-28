#ifndef TEC_BREAKOUT_STARTSERVERSINGLETON_H
#define TEC_BREAKOUT_STARTSERVERSINGLETON_H

#include <sstream>
#include <chrono>
#include <thread>
#include <mutex>

#include "../socket/SocketServer.h"
#include "../gui/game.h"
#include "Login.h"


class StartServerSingleton {
public:
    //Getting singleton objects
    static StartServerSingleton *GetInstance();

    //Release the singleton and call it when the process exits
    static void deleteInstance();

    //Return singleton address
    void Print();

private:
    //Construct and analyze it as private, prohibit external structure
    //and Deconstruction

    StartServerSingleton();
    ~StartServerSingleton();

    //Construct its only copy construction and assignment into private
    //functions, forbid external copy and assignment.

    StartServerSingleton(const StartServerSingleton &signal);
    const StartServerSingleton &operator=(const StartServerSingleton &signal);

private:

    //Unique singleton object pointer
    static StartServerSingleton *m_StartServerSingleton;

};

#endif //TEC_BREAKOUT_STARTSERVERSINGLETON_H
