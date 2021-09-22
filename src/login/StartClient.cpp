#include "StartClient.h"
#include "../socket/SocketClient.h"
#include "Login.h"

SocketClient* clientConnection;

int socketPortClient;
string ipAddress;

void * clientInit(void *){


    try {
        clientConnection->connectServer();
    }
    catch (exception& e) {
        cout<<"An exception was found with the error message\n"<<e.what()<<"\n In line 12 from StartServer.cpp";
    }

    return nullptr;
}

StartClient::StartClient() {
    string option;
    cout <<"*********************************************************\n"
           "***    Please enter the ip where the server is in    ****\n"
           "* if the server is local you can use the word localhost *\n"
           "*    or enter the value ( 0 ) to return to the login    *\n"
           "*********************************************************\n";
    cin >> ipAddress;

    cout <<"*********************************************************\n"
           "***    Please enter the socket where the server is   ****\n"
           "***                     is allocated in              ****\n"
           "*    or enter the value ( 0 ) to return to the login    *\n"
           "*********************************************************\n";
    cin >> option;

    if(ipAddress=="0" || option=="0"){
        Login();
    }

    stringstream parse(option);
    parse >> socketPortClient;

    if(socketPortClient<=1024){
        cout<<"Sorry, your input doesn't match any open ports"<<endl;
        StartClient();
    }
    else{
        pthread_t serverThread;
        clientConnection = new SocketClient;
        clientConnection->setServerSocket(socketPortClient);
        clientConnection->setIpAddress(ipAddress);
        pthread_create(&serverThread, nullptr , clientInit, nullptr);
    }

    delete clientConnection;

}
