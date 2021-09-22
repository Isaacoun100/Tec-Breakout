#include "SocketClient.h"


SocketClient::SocketClient() {}

void SocketClient::setIpAddress(string ipAddress){
    this->ipAddress=ipAddress;
    cout<<this->ipAddress;

}
void SocketClient::setServerSocket(int serverSocket) {
    this->serverSocket=serverSocket;
    cout<<this->serverSocket;
}

void SocketClient::connectServer() {
    identifier = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
    if(identifier<0) cout<<"Server was not found"<<endl;
    info.sin_family = AF_INET;

    info.sin_addr.s_addr = inet_addr(ipAddress.c_str());
    info.sin_port = ntohs((uint16_t)serverSocket);

    memset(&info.sin_zero , 0, sizeof(info.sin_zero));

    if ((connect(identifier, (sockaddr *) &info, (socklen_t) sizeof(info))) < 0){
       cout<<"Couldn't reach the server"<<endl;
    }
    cout<<"Connection was successfull"<<endl;

    pthread_t clientThread;
    pthread_create(&clientThread,0,SocketClient::listener, (void*)this);
    pthread_detach(clientThread);
}
void * SocketClient::listener(void *obj) {
    SocketClient* c = (SocketClient*)obj;

    while(true){
        string message;
        char buffer[1024] = {0};
        while(true){
            memset(buffer, 0, 1024);
            int bytes = recv(c->identifier, buffer, 1024, 0);
            message.append(buffer,bytes);
            if(bytes<=0){
                close(c->identifier);
                pthread_exit(nullptr);
            }
            if(bytes<1024) break;
        }
        cout<<message<<endl;
        if(message=="exit") break;
    }
    close(c->identifier);
    pthread_exit(nullptr);
}

void SocketClient::setMessage(const char *msn) {
    send(3, msn, strlen(msn), 0);
}

