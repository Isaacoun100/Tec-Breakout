#ifndef TEC_BREAKOUT_STARTSERVER_H
#define TEC_BREAKOUT_STARTSERVER_H

#include <sstream>
#include <chrono>
#include <thread>

#include "../socket/SocketServer.h"
#include "../gui/game.h"
#include "../temp/ReadWrite.h"
#include "Login.h"

using namespace std;

/**
 *
 */
class StartServer {
public:
    string newMessage;

    /**
     *
     * @param userInput
     */
    void setNewMessage(string userInput);

    /**
     *
     */
    StartServer();
};

#endif
