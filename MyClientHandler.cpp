//
// Created by liran-baruch on 1/15/19.
//

#include "MyClientHandler.h"

MyClientHandler::MyClientHandler(CacheManager<string, string> *cacheManager) : cacheManager(cacheManager) {}

CacheManager<string, string> *MyClientHandler::getCacheManager() const {
    return cacheManager;
}

void MyClientHandler::handleClient(int sock) {

}

string MyClientHandler::problemSolve(string &problem) {
    return std::__cxx11::string();
}
