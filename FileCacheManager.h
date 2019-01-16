//
// Created by yuval on 1/9/19.
//
/**
#ifndef UNTITLED6_FILECACHEMANAGER_H
#define UNTITLED6_FILECACHEMANAGER_H
#include "CacheManager.h"
using namespace std;

class FileCacheManager : public CacheManager<string, string, string>{

public:
    FileCacheManager(string &path);
    virtual void loadSolutions();
    virtual void saveSolutions();
    virtual ~FileCacheManager(){};

};


#endif //UNTITLED6_FILECACHEMANAGER_H
**/