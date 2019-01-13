//
// Created by yuval on 1/13/19.
//

#ifndef UNTITLED6_MYSERIALSERVER_H
#define UNTITLED6_MYSERIALSERVER_H

#include "Server.h"



class MySerialServer : public Server{

//this struct is holds the data for communication;
public:
    struct serverData {
        int port;
        int sockfd;
        int newsockfd;
        ClientHandler *clientHandler;
        //struct sockaddr_in address;
    };
    serverData *socket_info = new serverData;

    //this constructor is generates the struct.
    MySerialServer(int port, int sockfd, int newsockfd, ClientHandler* c);

    /**
 * open
 * @param port port number for openning the server.
 */
    void open(int port, ClientHandler* c);


/**
 * stop
 * this function close the server.
 */
    void stop();
};


#endif //UNTITLED6_MYSERIALSERVER_H
