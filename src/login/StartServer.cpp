#include "StartServer.h"
#include "../socket/SocketServer.h"
#include "Login.h"

SocketServer* serverConnection;
int socketPortServer;

void * serverInit(void *){
    try {
        serverConnection->setServerSocket(socketPortServer);
        serverConnection->run();
    }
    catch (exception& e) {
        cout<<"An exception was found with the error message\n"<<e.what()<<"\n In line 12 from StartServer.cpp";
    }
    return nullptr;
}

StartServer::StartServer() {

    string option;
    cout <<"*********************************************************\n"
           "***    Please enter the socket where you want the    ****\n"
           "***             server to be allocated in           *****\n"
           "***       or press ( 1 ) to return to the login     *****\n"
           "*********************************************************\n";
    cin >> option;

    stringstream parse(option);
    parse >> socketPortServer;

    if(socketPortServer==1){
        Login();
    }

    if(socketPortServer<=1024){
        cout<<"Sorry, your input doesn't match any open ports"<<endl;
        StartServer();
    }
    else{
        pthread_t serverThread;
        serverConnection = new SocketServer;
        pthread_create(&serverThread, nullptr , serverInit, nullptr);
        pthread_detach(serverThread);

        while(true){
            string msg;
            cin >> msg;
            if(msg == "exit") break;
            serverConnection->setMessage(msg.c_str());
        }
        delete serverConnection;

    }
}
