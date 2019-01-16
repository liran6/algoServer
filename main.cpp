#include <iostream>

#include "Server.h"
#include "MyParallelServer.h"

int main() {
    int port = 5400;
    server_side::Server * server1 = new server_side::MyParallelServer();
    server_side::ClientHandler* c = new MyClientHandler();
    server1->open(port,c);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}