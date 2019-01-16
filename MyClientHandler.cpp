//
// Created by liran-baruch on 1/15/19.
//

#include <sys/socket.h>
#include <sstream>
#include <unistd.h>
#include <strings.h>
#include "MyClientHandler.h"

/*MyClientHandler::MyClientHandler(CacheManager<string, string> *cacheManager){

}*/

CacheManager<string, string> *MyClientHandler::getCacheManager() const {
    return cacheManager;
}


void MyClientHandler::handleClient(int sock) {

    int n;
    bool isClientActive = true;
    char* buffer = "";
    string str = "";

    while (isClientActive) {
        do {
            n = read(sock, buffer, 2000);
            if(n == -1) {
                cerr << "Reading appeal from Client has been failed." << endl;
                isClientActive = false;
            }
            str += atoi(buffer);

        } while (!str.find("end"));

        str = str.substr(0, str.find("end"));
        bzero(buffer, 2000);
        isClientActive = false;
    }
    string answerToClient = problemSolve(str);


}

string MyClientHandler::problemSolve(string &problem) {
    return std::__cxx11::string();
}
