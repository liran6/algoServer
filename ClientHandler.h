//
// Created by yuval on 1/9/19.
//
#include <iostream>
#include <vector>
#include "CacheManager.h"


#ifndef UNTITLED6_CLIENTHANDLER_H
#define UNTITLED6_CLIENTHANDLER_H
using namespace std;

class ClientHandler {

public:

    virtual void handleClient(int socket) = 0;

};


#endif //UNTITLED6_CLIENTHANDLER_H
