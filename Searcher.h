//
// Created by liran-baruch on 1/13/19.
//

#ifndef UNTITLED6_SEARCHER_H
#define UNTITLED6_SEARCHER_H

#include <deque>
#include <set>
#include "ISearcher.h"
#include "Greater.h"
using namespace std;
template <typename S, typename  N>
class Searcher : public ISearcher<S, N>
{
    int evaluatedNodes;
protected:
    deque<State<N>*> dequeOpenList;
    multiset<State<N>, Greater<N>>multisetOpenList;
public:
    Searcher(){
        this->evaluatedNodes = 0;
    }

    virtual S search (ISearchable<N> searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;

};
#endif //UNTITLED6_SEARCHER_H
