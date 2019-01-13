//
// Created by yuval on 1/9/19.
//
#include <map>
#include <string>
#include <iostream>
#include "Problem.h"
#include "Solution.h"


#ifndef UNTITLED6_CACHEMANAGER_H
#define UNTITLED6_CACHEMANAGER_H

template<class Problem, class Solution>;

using namespace std;
class CacheManager{
map<Problem p, Solution s> probAndSol;

bool isTheProblemExist(map<Problem,Solution> probAndSol, Problem p) {
    if (probAndSol.find(p) != 0) {

    }

}
};
#endif //UNTITLED6_CACHEMANAGER_H
