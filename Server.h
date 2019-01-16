/*
//
// Created by yuval on 1/9/19.
//

#ifndef UNTITLED6_NAMESPACE_H
#define UNTITLED6_NAMESPACE_H


#include "ClientHandler.h"
#include "string"
#include "Task.h"
#include "ThreadsPool.h"




using namespace std;

class Server {
    int port;
    int serverSocket;

    ThreadsPool *threadsPool;
public:

    vector<Task *> listOfTasks;
    vector<int> listOfSockets;

//constructor
    Server(int port);
*/
/**
 * open
 * @param port port number for openning the server.
 *//*

    void open(int port, ClientHandler *c);
*/
/**
 * start
 * this function managed the threads.
 *//*

    void start();
*/
/**
 * stop
 * this function close the server.
 *//*

    void stop(int new_sock, int socket_s);

};


#endif //UNTITLED6_NAMESPACE_H
*/
