//
// Created by liran-baruch on 1/16/19.
//

#ifndef UNTITLED6_BESTFIRSTSEARCH_H
#define UNTITLED6_BESTFIRSTSEARCH_H
#include "ISearchable.h"
#include "Searcher.h"
#include <unordered_set>
#include <deque>
#include <list>


using namespace std;

template<typename N>
class BestFirstSearch : public Searcher< N> {
public:

    vector<State<N> *> search(ISearchable<N>* searchable) {
        State<N>* s = searchable->getInitialState();
        multiset<State<N> , Greater<N>> closed;
        Searcher<N>::addMultisetOpenList(s);
        while (Searcher<N>::multisetOpenList.size() > 0) {
            State<N>* n = Searcher<N>::popMultisetOpenList();
            closed.insert(*n);
            if (*(searchable->getGoalState()) == *n)
                return Searcher<N>::backTrace(n, searchable);
            State<N>* parent = new State<N>(n->getNode(), n->getCost());
            vector<State<N>*> successors = searchable->getAllPossibleState(parent);
            for (auto it = successors.begin(); it != successors.end(); it++) {
                if (!(Searcher<N>::isInMultisetOpenList(*it)) && !(isInSet(&closed,*it))){
                    State<N>* s = *it;
                    s->setCameFrom(n);
                    Searcher<N>::addMultisetOpenList(s);
                }

                else if (!(isInSet(&closed,*it)))
                {
                    saveMin(*it);
                }
            }
        }
    }

    void saveMin(State<N>* currState)
    {
        for (auto it = Searcher<N>::multisetOpenList.begin(); it != Searcher<N>::multisetOpenList.end(); it++)
        {
            State<N>* s = *it;
            if(*s == *currState)
            {
                if (currState->getCost() < s->getCost())
                {
                    Searcher<N>::multisetOpenList.erase(it);
                    s->setCameFrom(currState->getCameFrom());
                    Searcher<N>::addMultisetOpenList(currState);
                }
                return;
            }
        }
        Searcher<N>::addMultisetOpenList(currState);
        return;
    }

    bool isInSet(multiset<State<N>,Greater<N>>* setOfState,State<N> *currState)
    {
        for (auto it = setOfState->begin(); it != setOfState->end(); it++)
        {
            State<N> *s = *it;
            if(*s == *currState)
                return true;
        }
        return false;
    }

};

#endif //UNTITLED6_BESTFIRSTSEARCH_H
