#include <iostream>

#include "Server.h"
#include "MyParallelServer.h"

int main() {
    int port = 5400;
    server_side::Server * server1 = new server_side::MyParallelServer();
    server_side::ClientHandler* c = new MyClientHandler();
    server1->open(port,c);
    delete[](server1);
    delete[](c);
    return 0;
}