#include "SocketServer.h"

 /**
 * This is the constructor for the SocketServer class, this clas will executed when the
 * class is called.
 */
SocketServer::SocketServer() {}

 /**
 *  This method is a setter for the integer variable called serverSocket
 * @param serverSocket is the ip in which the server will be allocated in
 */
void SocketServer::setServerSocket(int serverSocket) { this->serverSocket=serverSocket; }

 /**
 * CreateConnection will test that the server information is correct, and will try to
 * open a port
 * @return a boolean value based on whether or not the connection was succesfull.
 */
bool SocketServer::createConnection(){
    identifier = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
    if(identifier<0) return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(serverSocket);

    memset(&info.sin_zero , 0, sizeof(info.sin_zero));

    return true;
}

 /**
 * This method will test that the information brinded by the client is correct, if it is
 * correct then the method will return true, if not, is going to return false.
 * @return a boolean value based on whether or not the link can be made.
 */
bool SocketServer::linkKernel(){
    if((bind(identifier, (sockaddr*)&info, (socklen_t)sizeof(info)))<0)
        return false;
    listen(identifier, 1);
    return true;
}

 /**
 * This is the method that will open the server and receive the messages, this method
 * should be executed when is clear that the socket is available.
 */
void SocketServer::run() {
    if(!createConnection())
        throw string("An error was found while trying to creating the socket");
    if(!linkKernel())
        throw string("An error was found while trying to link to the kernel");

    while(true){
        dataSocket data;
        socklen_t t = sizeof(data.info);
        cout<<"Waiting for client to connectServer"<<endl;
        data.identifier = accept(identifier, (sockaddr *)&data.info, &t);
        if(data.identifier<0){
            cout << "There was an error while trying to accept the client" << endl;
            break;
        }
        else{
            client.push_back(data.identifier);
            cout <<"Connection with "+ to_string(identifier)  +" successful"<<endl;
            pthread_t thread;
            pthread_create(&thread, nullptr, SocketServer::clientManager,(void*)&data);
        }
    }
    close(identifier);
}

 /**
 * This method converts the messages sent through the socket into a string that can later
 * be displayed or used by the server.
 * @param obj This obj protects the server from any incoming messages
 */
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
                pthread_exit(nullptr);
            }
            if(bytes<1024) break;
        }

        ReadWrite().writeFile(message);
        cout<<message<<endl;
        if(message=="exit") break;
    }

    close(data->identifier);
    pthread_exit(nullptr);

}

 /**
 * SetMessage is a method that sends the incoming constant char to the fisrt client in
 * the clients vector
 * @param msn is the variable that contains the message that is going to be sended to the
 * client.
 */
void SocketServer::setMessage(const char *msn) {
    send(4,msn, strlen(msn),0);
}
