
#ifndef TEC_BREAKOUT_SOCKETCLIENT_H
#define TEC_BREAKOUT_SOCKETCLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

/**
 * This class will be used to connect to a server from the client, it will also check open
 * ports and sent message through the socket
 */
class SocketClient {
public:
    int serverSocket;
    string ipAddress;

    /**
     *This is the constructor for the SocketClient class
     */
    SocketClient();

    /**
     * This method is a setter for the serverSocket variable that contains the socket server
     * where the connection is going to take place.
     * @param serverSocket is the socket
     */
    void setServerSocket(int serverSocket);

    /**
     * The setIpAddress method is a setter for the ipAddress variable that contains the ip in
     * which the connection is going to take place
     * @param ipAddress is the ip
     */
    void setIpAddress(string ipAddress);

    /**
     * SetMessage is a method that receives a constant char* that contains the message that
     * we will sent to the server through the socket and the ip.
     * @param msn is the message that is going to be sent
     */
    void setMessage(const char* msn);

    /**
     * This method initialices the connection between the server and the client.
     */
    void connectServer();

private:

    int identifier;
    sockaddr_in info;

    /**
     * This method listens the messages comming through the server socket to the client.
     * @param obj
     * @return
     */
    static void* listener(void* obj);

};


#endif
