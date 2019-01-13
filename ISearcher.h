//
// Created by liran-baruch on 1/13/19.
//

#ifndef UNTITLED6_ISEARCHER_H
#define UNTITLED6_ISEARCHER_H
#include "ISearchable.h"
#include "State.h"

template <typename S, typename N>
class ISearcher {
public:
    virtual S  search (ISearchable<N>* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
};
#endif //UNTITLED6_ISEARCHER_H
