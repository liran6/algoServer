#include <iostream>
#include "Server.h"
#include "MySerialServer.h"
int main() {
    int port = 5400;
    ClientHandler* c = new ClientHandler;
    MySerialServer* mls;
    mls->open(port, c);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}