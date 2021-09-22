#include "StartClient.h"
#include "../socket/SocketClient.h"
#include "Login.h"

SocketClient* clientConnection;

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
    int socketPortClient;
    string ipAddress;

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

    stringstream parse(option);
    parse >> socketPortClient;

    if(ipAddress=="0" || option=="0"){
        Login();
    }

    if(socketPortClient<=1024){
        cout<<"Sorry, your input doesn't match any open ports"<<endl;
        StartClient();
    }
    else{
        pthread_t clientThread;
        clientConnection = new SocketClient;
        clientConnection->setServerSocket(socketPortClient);
        clientConnection->setIpAddress(ipAddress);
        pthread_create(&clientThread, nullptr , clientInit, nullptr);
        pthread_detach(clientThread);
    }

    while(true){
        string msg;
        cin>>msg;
        if(msg=="exit"){
            break;
        }
        clientConnection->setMessage(msg.c_str());
    }

    delete clientConnection;

}
