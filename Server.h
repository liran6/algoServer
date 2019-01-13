//
// Created by yuval on 1/9/19.
//

#ifndef UNTITLED6_NAMESPACE_H
#define UNTITLED6_NAMESPACE_H


#include "ClientHandler.h"

namespace ‫‪server_side{
class Server {
/**
 * open
 * @param port port number for openning the server.
 */
void open(int port, ClientHandler c);
/**
 * stop
 * this function close the server.
 */
void stop();

};


#endif //UNTITLED6_NAMESPACE_H
