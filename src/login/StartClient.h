#ifndef TEC_BREAKOUT_STARTCLIENT_H
#define TEC_BREAKOUT_STARTCLIENT_H

#include <iostream>
#include <sstream>

#include "../socket/SocketClient.h"
#include "Login.h"
#include "../gui/player_gui.h"

using namespace std;

/**
 * This class will initiate the client GUI as well as the logic for the sockets
 * and threads
 */
class StartClient {
public:
    /**
     * This method is the constructor for the StartClient class, this method
     * initiates the GUI, asks the user for the socket that will be used and
     * use this socket to initiate the communication.
     */
    StartClient();
};

#endif
