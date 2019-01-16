//
// Created by liran-baruch on 1/15/19.
//

#ifndef UNTITLED6_MYCLIENTHANDLER_H
#define UNTITLED6_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "ISearchable.h"
#include "Solver.h"
#include "CacheManager.h"
template <typename P, typename S>
class MyClientHandler : public ClientHandler{
    Solver<P, S> *solver;
    CacheManager<P, S> *cacheManager;
public:
    MyClientHandler(Solver<P, S> *solver, CacheManager<P, S> *cacheManager){
        this->solver = solver;
        this->cacheManager = cacheManager;
    };
    virtual void handleClient(int sock);
};
#endif //UNTITLED6_MYCLIENTHANDLER_H
