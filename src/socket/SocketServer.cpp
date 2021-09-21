//
// Created by isaac-linux on 19/9/21.
//

#include "SocketServer.h"


SocketServer::SocketServer() {}

bool SocketServer::createConnection(){
    identifier = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
    if(identifier<0) return false;

    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(6969);
    memset(&info.sin_zero , 0, sizeof(info.sin_zero));
    return true;
}

bool SocketServer::linkKernel(){
    if((bind(identifier, (sockaddr*)&info, (socklen_t)sizeof(info)))<0)
        return false;
    listen(identifier, 1);
    return true;
}

void SocketServer::run() {
    if(!createConnection())
        throw string("An error was found while trying to creating the socket");
    if(!linkKernel())
        throw string("An error was found while trying to link to the kernel");

    while(true){
        dataSocket data;
        socklen_t t = sizeof(data.info);
        cout<<"Waiting for client to connect"<<endl;
        data.identifier = accept(identifier, (sockaddr *)&data.info, &t);
        if(data.identifier<0){
            cout << "There was an error while trying to accept the client" << endl;
            break;
        }
        else{
            client.push_back(data.identifier);
            cout <<"Connection with "+ to_string(identifier)  +" successful"<<endl;
            pthread_t thread;
            pthread_create(&thread, 0, SocketServer::clientManager,(void*)&data);
        }
    }
    close(identifier);
}

void * SocketServer::clientManager(void *obj) {
    dataSocket* data = (dataSocket *)obj;
    while(true){
        string message;
        char buffer[1024] = {0};
        while(true){
            memset(buffer, 0, 1024);
            int bytes = recv(data->identifier, buffer, 1024, 0);
            message.append(buffer,bytes);
            if(bytes<=0){
                close(data->identifier);
                pthread_exit(0);
            }
            if(bytes<1024) break;
        }
        cout<<message<<endl;
    }
}

void SocketServer::setMessage(const char *msn) {
    send(4,msn, strlen(msn),0);
}