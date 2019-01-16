/*
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
#include "ThreadsPool.h"

using namespace std;

class MyParallelServer : public Server{
    pthread_mutex_t mutex_sockets_list;
    //the next vector contains all the threads which solving the problems with the cacheManager.
    vector<pthread_t*> vector_of_threads;
    //the next vector contains all the sockets which currently open and holds the threads .
    vector<sockaddr> vector_of_sockets;


public:

    */
/**
 * open
 * @param port port number for openning the server.
 *//*

    void open(int port, ClientHandler* c) {
        int sockPort = port;
        int s = socket(AF_INET, SOCK_STREAM, 0);
        if (s < -1) {
            cerr << "Problem in openning socket!" << endl;
        }
        struct sockaddr_in serv;
        bzero((void *) &serv, sizeof(serv));
        serv.sin_addr.s_addr = INADDR_ANY;
        serv.sin_port = htons(sockPort);
        serv.sin_family = AF_INET;

        if (bind(s, (sockaddr *) &serv, sizeof(serv)) < 0) {
            cerr << "Problem in binding!" << endl;
        }

        int new_clientSocket;
        listen(s, 5);
        struct sockaddr_in clientAddres;
        socklen_t clilen = sizeof(clientAddres);

        cout << "Waiting for a Client connection." << endl;

        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;



        while (true) {

            if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout)) < 0) {
                char buffer[256];
                strerror_r(errno, buffer, 256); // get string message from errno.
                printf("Error %s", buffer);
                close(s);
                exit(2);
            };

            new_clientSocket = accept(s, (struct sockaddr *) &clientAddres, &clilen);

            if (new_clientSocket < 0) {
                cerr << "Unfortunately, the client could not connect." << endl;
            }
            pthread_mutex_lock(&mutex_sockets_list);
            listOfSockets.push_back(s);
            pthread_mutex_unlock(&mutex_sockets_list);

            Task *tsk = new Task(handleClient1, (void*) new_clientSocket);
            listOfTasks.push_back(tsk);
            ->addTask(tsk);

            sleep(1);
        }
    }

    */
/**
 * start
 * this function starts the thread role.
 *//*

    void start(){

    }


*/
/**
 * stop
 * this function close the server.
 *//*

    void stop(int new_sock, int socket_s){
        close(new_sock);
        close(socket_s);
    }
};



#endif //UNTITLED6_MYPARALLELSERVER_H
*/
