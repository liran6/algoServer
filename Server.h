//
// Created by yuval on 1/9/19.
//

#ifndef UNTITLED6_NAMESPACE_H
#define UNTITLED6_NAMESPACE_H


#include "ClientHandler.h"
#include <string>
#define THREAD_POOL_SIZE 5

using namespace std;

namespace server_side {
    class Server {
    public:
/**
 * open
 * @param port port number for openning the server.
 */
        virtual void open(int port, ClientHandler *c)=0;

/**
 * stop
 * this function close the server.
 */
        virtual void stop(int socket_s)=0;

    };
};


#endif //UNTITLED6_NAMESPACE_H
