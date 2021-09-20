//
// Created by isaac-linux on 19/9/21.
//

#ifndef TEC_BREAKOUT_SOCKETSERVER_H
#define TEC_BREAKOUT_SOCKETSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>

using namespace std;

struct dataSocket{
    int identifier;
    sockaddr_in info;
};

class SocketServer {
public:
    SocketServer();
    void run();
    void setMessage(const char* msn);

private:
    int identifier;
    sockaddr_in info;

    bool createConnection();
    bool linkKernel();
    vector<int> client;
    static void* clientManager(void* obj);

};


#endif //TEC_BREAKOUT_SOCKETSERVER_H
