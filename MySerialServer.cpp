//
// Created by yuval on 1/13/19.
//

#include <bits/socket_type.h>
#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "MySerialServer.h"

using namespace std;

MySerialServer::MySerialServer(int port, int sockfd, int newsockfd, ClientHandler *c) {
    socket_info->port = port;
    socket_info->clientHandler = c;
    socket_info->sockfd = sockfd;
    socket_info->newsockfd = newsockfd;
}


void MySerialServer ::open(int port, ClientHandler *c) {

    this->socket_info->port = port;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(this->socket_info->port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *)&serv, sizeof(serv)) < 0)	{
        cerr << "Bad!" << endl;
    }

    int new_sock;
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    new_sock = accept(s, (struct sockaddr*)&client, &clilen);
    if (new_sock < 0)	{
        if (errno == EWOULDBLOCK)	{
            cout << "timeout!" << endl;
            exit(2);
        }	else	{
            perror("other error");
            exit(3);
        }
    }
    cout << new_sock << endl;
    cout << s << endl;
    cout << "succeed to connect" << endl;
    //close(new_sock);
    //close(s);
    //return 0;

}
void MySerialServer ::stop() {

};