#include "logic/example_logic.h"
#include "gui/example_gui.h"
#include "socket/SocketServer.h"

SocketServer* communication;
void * initiateCommunication(void *){
    try {communication->run();}
    catch (string ex) {cout<<ex<<endl;}
}

int main(int argc, char** argv){

    //printa();
    //firtsGUI();

    communication = new SocketServer;
    pthread_t newThread;
    pthread_create(&newThread, 0 , initiateCommunication, NULL);
    pthread_detach(newThread);

    string check = "Connected successfully";

    while(true){
        string msg;
        cin >> msg;
        if(msg == "salir") break;
        communication ->setMessage(msg.c_str());
    }

    delete communication;
    return 0;

}