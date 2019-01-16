//
// Created by liran-baruch on 1/13/19.
//

#ifndef UNTITLED6_ISEARCHER_H
#define UNTITLED6_ISEARCHER_H
#include "ISearchable.h"
#include "State.h"

template <typename N>
class ISearcher {
public:
    virtual vector<State<N> *>  search (ISearchable<N>* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual vector<State<N> *> backTrace(State<N> *s, ISearchable<N> *searchable) = 0;
};
#endif //UNTITLED6_ISEARCHER_H
