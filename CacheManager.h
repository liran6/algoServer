//
// Created by yuval on 1/9/19.
//
#ifndef UNTITLED6_CACHEMANAGER_H
#define UNTITLED6_CACHEMANAGER_H

#include <map>
#include <string>
#include <iostream>
//#include "Problem.h"
//#include "Solution.h"



using namespace std;
template<typename P, typename S >//typename F>


class CacheManager{
protected:
    map<P, S> probAndSol;
    //F probAndSolFile;

virtual bool isTheProblemExist(P &problem) {
    //if a solution to the problem has already cached.
    return this->probAndSol.find(problem) != (this->probAndSol).end();
}
virtual void addSolution(P &problem, S &solution){
    //if there is no such problem in the map, add it and it's solution.
    if(this->probAndSol.find(problem) == this->probAndSol.end()){
        this->probAndSol[problem] = solution;
    }
}
virtual S getSolution(P &problem){
    if(this->isTheProblemExist(problem)){
        return this->probAndSol[problem];
    }
    throw runtime_error("Cannot find solution in the map");
}

virtual void loadSolutions() = 0;
virtual void saveSolutions() = 0;
virtual ~CacheManager(){};

};
#endif //UNTITLED6_CACHEMANAGER_H
