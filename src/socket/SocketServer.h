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

struct dataSocket{
    int identifier;
    sockaddr_in info;
};

class SocketServer {
public:
    int serverSocket;
    SocketServer();
    void setServerSocket(int serverSocket);
    void run();
    void setMessage(const char* msn);
    bool linkKernel();
    bool createConnection();
private:

    int identifier;
    sockaddr_in info;
    vector<int> client;
    static void* clientManager(void* obj);

};


#endif //TEC_BREAKOUT_SOCKETSERVER_H
