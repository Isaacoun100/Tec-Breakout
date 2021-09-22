
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

class SocketClient {
public:
    SocketClient();

    int serverSocket;
    string ipAddress;
    void setServerSocket(int serverSocket);
    void setIpAddress(string ipAddress);
    void setMessage(const char* msn);
    void connectServer();

private:

    int identifier;
    sockaddr_in info;

    static void* listener(void* obj);

};


#endif //TEC_BREAKOUT_SOCKETCLIENT_H
