#include "StartClient.h"

SocketClient* clientConnection;
PlayerGUI* playerGui = new PlayerGUI();

/**
 *
 * @return
 */
void * ClientInit(void *){

    try {
        clientConnection->connectServer();
    }
    catch (exception& e) {
        cout<<"An exception was found with the error message\n"<<e.what()<<"\n In line 12 from StartServer.cpp";
    }

    return nullptr;
}

/**
 *
 * @return
 */
void * StartPlayerGUI(void *) {

    try {
        playerGui->run();
    }
    catch(exception& e){
        cout<<"An exception was found with the error message\n"<<e.what()<<"\n In line 24 from StartServer.cpp";
    }

}

/**
 *
 */
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
        pthread_t playerGUIThread;
        clientConnection = new SocketClient;
        clientConnection->setServerSocket(socketPortClient);
        clientConnection->setIpAddress(ipAddress);
        pthread_create(&clientThread, nullptr, ClientInit, nullptr);
        pthread_create(&playerGUIThread, nullptr, StartPlayerGUI, nullptr);
        pthread_detach(clientThread);
        pthread_detach(playerGUIThread);
    }

    while(true){
        string message;
        message = playerGui->txtInput;
        this_thread::sleep_for(std::chrono::milliseconds(10));
        if(!message.empty()){

            clientConnection->setMessage(message.c_str());

            if(message=="E"){
                playerGui->stop();
                break;
            }

            playerGui->txtInput.clear();
            message.clear();

        }
    }

    delete playerGui;
    delete clientConnection;

}
