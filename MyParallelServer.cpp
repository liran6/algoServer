//
// Created by yuval on 1/13/19.
//

#include "MyParallelServer.h"

void server_side::MyParallelServer::open(int port, ClientHandler *c) {
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
    ClientArgs *clientArgs = new ClientArgs;
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
        if (vector_of_threads.size() >= THREAD_POOL_SIZE) {
            cerr << "There is no available thread." << endl;
            close(new_clientSocket);
            exit(2);
        }

        //add a new socket to list.
        pthread_mutex_lock(&mutex_sockets_list);
        vector_of_sockets.push_back(new_clientSocket);
        pthread_mutex_unlock(&mutex_sockets_list);

        //update the struct of arguments with new client info.
        clientArgs->MyCH = dynamic_cast<MyClientHandler *>(c);
        clientArgs->clientSockNum = new_clientSocket;

        //initialize new thread with execute who communicates with MyClientHandler.
        thread = new pthread_t;
        pthread_create(thread, nullptr, execute, clientArgs);

        //add a new thread to the list of thread.
        pthread_mutex_lock(&mutex_threads_vector);
        vector_of_threads.push_back(thread);
        pthread_mutex_unlock(&mutex_threads_vector);


        sleep(1);
    }

    stop(s);
}

void server_side::MyParallelServer::stop(int socket_s) {
    for (int i = 0; i < vector_of_sockets.size(); i++) {
        close(vector_of_sockets[i]);
    }

    for (int i = 0; i < vector_of_sockets.size(); i++) {
        close(vector_of_sockets[i]);
    }

    pthread_mutex_destroy(&mutex_sockets_list);
    pthread_mutex_destroy(&mutex_threads_vector);

    //closing server socket and exiting program
    close(socket_s);
    exit(0);
}

void *server_side::MyParallelServer::execute(void *arg) {
    auto *clientArgsToHandle = (struct ClientArgs *) arg;
    MyClientHandler *ch = clientArgsToHandle->MyCH;
    int sockForHandler = clientArgsToHandle->clientSockNum;

    ch->handleClient(sockForHandler);

}
