//
// Created by yuval on 1/9/19.
//

#ifndef UNTITLED6_NAMESPACE_H
#define UNTITLED6_NAMESPACE_H


#include "ClientHandler.h"
#include "string"
#include "MyClientHandler.h"
#define THREAD_POOL_SIZE 5

using namespace std;

class Server {
    int port;
    int serverSocket;

public:
    //vector<Task *> listOfTasks;
    //vector<int> listOfSockets;
    //static void *execute(void *arg);


/**
 * open
 * @param port port number for openning the server.
 */
    virtual void open(int port, MyClientHandler *c);

/**
 * stop
 * this function close the server.
 */
    void stop(int socket_s);

};


#endif //UNTITLED6_NAMESPACE_H
