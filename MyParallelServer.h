//
// Created by yuval on 1/13/19.
//

#ifndef UNTITLED6_MYPARALLELSERVER_H
#define UNTITLED6_MYPARALLELSERVER_H

#include <pthread.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
#include <memory.h>
#include "Server.h"
#include "MyClientHandler.h"


namespace server_side {
    class MyParallelServer : public Server {

        pthread_t *thread;
        pthread_mutex_t mutex_sockets_list;
        pthread_mutex_t mutex_threads_vector;

        vector<pthread_t *> vector_of_threads;
        //the next vector contains all the sockets which currently open and holds the threads .
        vector<int> vector_of_sockets;

    public:
        struct ClientArgs {
            MyClientHandler *MyCH;
            int clientSockNum;
        };

        /**
     * open
     * @param port port number for openning the server.
     */
void open(int port, ClientHandler *c) override;

static void* execute(void *arg);

/**
 * stop
 * this function close the server.
 */
void stop(int socket_s) override;
    };
}

#endif //UNTITLED6_MYPARALLELSERVER_H
