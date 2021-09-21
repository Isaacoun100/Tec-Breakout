#include "logic/example_logic.h"
#include "gui/example_gui.h"
#include "socket/SocketServer.h"
#include "socket/SocketClient.h"

SocketServer* serverConnection;
SocketClient* clientConnection;

void * serverInit(void *){
    try {serverConnection->run();}
    catch (exception& e) {cerr<<e.what()<<'\n';}
    return nullptr;
}

void * clientInit(void *){
    try {clientConnection->connectServer();}
    catch (exception& e) {cerr<<e.what()<<'\n';}
    return nullptr;
}

int main(int argc, char** argv){

    /*

    serverConnection = new SocketServer;
    pthread_t serverThread;
    pthread_create(&serverThread, 0 , serverInit, nullptr);
    pthread_detach(serverThread);

    while(true){
        string msg;
        cin >> msg;
        if(msg == "salir") break;
        serverConnection ->setMessage(msg.c_str());
    }
    delete serverConnection;

    */

    /*
    clientConnection = new SocketClient;
    pthread_t clientThread;
    pthread_create(&clientThread, 0, clientInit, nullptr);
    pthread_detach(clientThread);


    while(true){
        string msg;
        cin>>msg;
        if(msg == "salir") break;
        clientConnection->setMessage(msg.c_str());
    }

    delete clientConnection;
     */

    
    return 0;

}