//
// Created by liran-baruch on 1/15/19.
//

#ifndef UNTITLED6_MYCLIENTHANDLER_H
#define UNTITLED6_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "ISearchable.h"
#include "Solver.h"
#include "CacheManager.h"


#define THREAD_POOL_SIZE 5

class MyClientHandler : public ClientHandler{

    Solver<ISearchable<pair<int, int>>*, vector<State<pair<int, int>*>>> *solver;
    CacheManager<string, string> *cacheManager;

public:

  //  MyClientHandler(CacheManager<string, string> *cacheManager);

  MyClientHandler();

    CacheManager<string, string> *getCacheManager() const;

    string problemSolve(string &problem);
    virtual void handleClient(int sock);

};
#endif //UNTITLED6_MYCLIENTHANDLER_H
