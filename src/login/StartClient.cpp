#include "StartClient.h"

SocketClient* clientConnection;
PlayerGUI* playerGui = new PlayerGUI();

/**
 * This method initiates the communication client-server. It runs in a separated
 * thread from the main thread and the StartPlayerGUI thread.
 * @return a null pointer to indicate that the process is over.
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
 * This method initiates GUI for the user to input and control the bar in the game
 * @return a null pointer to indicate that the process is over.
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
 * This method is the constructor for the StartClient class, this method
 * initiates the GUI, asks the user for the socket that will be used and
 * use this socket to initiate the communication.
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

            if(message=="E"){
                clientConnection->setMessage("E");
                break;
            }

            clientConnection->setMessage(message.c_str());

            playerGui->txtInput.clear();
            message.clear();

        }
    }

    delete playerGui;
    delete clientConnection;

}
