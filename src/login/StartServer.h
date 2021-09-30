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
 * This class will initiate the server GUI as well as the logic for the sockets
 * and threads
 */
class StartServer {
public:
    string newMessage;

    /**
     * This method is the constructor for the StartServer class, this method
     * initiates the GUI, asks the user for the socket that will be used and
     * use this socket to initiate the communication.
     */
    StartServer();
};

#endif
