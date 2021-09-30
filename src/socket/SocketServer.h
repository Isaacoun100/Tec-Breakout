#ifndef TEC_BREAKOUT_SOCKETSERVER_H
#define TEC_BREAKOUT_SOCKETSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <vector>

#include "../temp/ReadWrite.h"

using namespace std;

/**
 * This structure will be used to contain the information of the client that connected to the
 * socket with its identifier.
 */
struct dataSocket{
    int identifier;
    sockaddr_in info;
};

/**
 * This class creates the server so that the client can connect and send the information
 * through the socket to the server instance.
 */
class SocketServer {
public:
    int serverSocket;

    /**
     * This is the constructor for the SocketServer class, this clas will executed when the
     * class is called.
     */
    SocketServer();

    /**
     *  This method is a setter for the integer variable called serverSocket
     * @param serverSocket is the ip in which the server will be allocated in
     */
    void setServerSocket(int serverSocket);

    /**
     * This is the method that will open the server and receive the messages, this method
     * should be executed when is clear that the socket is available.
     */
    void run();

    /**
     * SetMessage is a method that sends the incoming constant char to the fisrt client in
     * the clients vector
     * @param msn is the variable that contains the message that is going to be sended to the
     * client.
     */
    void setMessage(const char* msn);

    /**
     * This method will test that the information brinded by the client is correct, if it is
     * correct then the method will return true, if not, is going to return false.
     * @return a boolean value based on whether or not the link can be made.
     */
    bool linkKernel();

    /**
     * CreateConnection will test that the server information is correct, and will try to
     * open a port
     * @return a boolean value based on whether or not the connection was succesfull.
     */
    bool createConnection();

private:

    int identifier;
    sockaddr_in info;
    vector<int> client;

    /**
     * This method converts the messages sent through the socket into a string that can later
     * be displayed or used by the server.
     * @param obj This obj protects the server from any incoming messages
     */
    static void* clientManager(void* obj);

};


#endif
