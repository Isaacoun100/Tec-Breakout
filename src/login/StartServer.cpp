#include "StartServer.h"

SocketServer* serverConnection;
Game* breakout;

int socketPortServer;
string newMessage;

/**
 * This method initiates the communication client-server. It runs in a separated
 * thread from the main thread and the gameInit thread.
 * @return a null pointer to indicate that the process is over.
 */
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

/**
 * This method initiates the game interface. It runs in a separated
 * thread from the main thread and the serverInit thread.
 * @return a null pointer to indicate that the process is over.
 */
void * gameInit(void*){
    breakout->run();
    return nullptr;
}

/**
 * This method is the constructor for the Start Server class, this method
 * initiates the GUI, asks the user for the socket that will be used and
 * use this socket to initiate the communication.
 */
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

        //pthread_t declarations
        pthread_t serverThread, gameThread;

        //Constructors called for the *void method
        serverConnection = new SocketServer;
        breakout = new Game;

        //Thread for the server
        pthread_create(&serverThread, nullptr , serverInit, nullptr);
        pthread_detach(serverThread);

        //Tread for the game
        pthread_create(&gameThread, nullptr, gameInit, nullptr);
        pthread_detach(gameThread);

        while(true){
            this_thread::sleep_for(std::chrono::milliseconds(10));
            newMessage=ReadWrite().readFile();
            if(!newMessage.empty()){
                if(newMessage=="L"){
                    breakout->moveToLeftBar();
                    ReadWrite().clearFile();
                }
                else if(newMessage=="R"){
                    breakout->moveToRightBar();
                    ReadWrite().clearFile();
                }
                else if(newMessage=="E"){
                    breakout->stop();
                    break;
                }
            }
        }

        delete breakout;
        delete serverConnection;

    }
}
