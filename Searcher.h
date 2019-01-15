//
// Created by liran-baruch on 1/13/19.
//

#ifndef UNTITLED6_SEARCHER_H
#define UNTITLED6_SEARCHER_H
#include "ISearchable.h"
using namespace std;
template <typename S, typename  P>
class Searcher {
public:
    virtual S search (ISearchable<P> searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;

};
#endif //UNTITLED6_SEARCHER_H
