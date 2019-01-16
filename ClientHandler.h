//
// Created by yuval on 1/9/19.
//

#ifndef UNTITLED6_CLIENTHANDLER_H
#define UNTITLED6_CLIENTHANDLER_H
namespace server_side {
    class ClientHandler {

    public:

        virtual void handleClient(int socket) = 0;

    };
}

#endif //UNTITLED6_CLIENTHANDLER_H
