//
// Created by liran-baruch on 1/13/19.
//

#ifndef UNTITLED6_SEARCHER_H
#define UNTITLED6_SEARCHER_H

#include <deque>
#include <set>
#include <string>
#include "ISearcher.h"
#include "Greater.h"
#include <algorithm>
using namespace std;
template <typename  N>
class Searcher : public ISearcher<N>
{
private:
    int evaluatedNodes;
protected:
    deque<State<N>*> dequeOpenList;
    multiset<State<N>, Greater<N>>multisetOpenList;
public:

    Searcher(){
        this->evaluatedNodes = 0;
    }
     deque<State<N> *>* getDequeOpenList()  {
        return this->dequeOpenList;
    }

    const multiset<State<N>, Greater<N>> &getMultisetOpenList()  {
        return multisetOpenList;
    }


    bool isInDequeOpenList(State<N>* currState) {
        for (auto it = dequeOpenList.begin(); it != dequeOpenList.end(); it++) {
             State<N> *s = *it;
             if (*s == *currState)
             return true;
        }
            return false;
    }
    bool isInMultisetOpenList(State<N>* currState)
    {
        for (auto it = multisetOpenList.begin(); it != multisetOpenList.end(); it++)
        {
            State<N> s = *it;
            if(*s == *currState)
                return true;
        }
        return false;
    }

     int getNumberOfNodesEvaluated()  {
        return evaluatedNodes;
    }
    void addDequeOpenList(State<N> *state) {
        this->dequeOpenList.push_back(state);
    }
    void addMultisetOpenList(State<N> *state) {
        this->multisetOpenList.insert(*state);
    }
    State<N>* popDequeOpenList(bool isStack) {
        this->evaluatedNodes++;
        State<N> *s;
        if(isStack){
            s = dequeOpenList.back();
            dequeOpenList.pop_back();
        }else{
            s = dequeOpenList.front();
            dequeOpenList.pop_front();
        }
        return s;
    }
    State<N>* popMultisetOpenList() {
        this->evaluatedNodes++;
        auto it = multisetOpenList.begin();
        State<N> s = *it;
        multisetOpenList.erase(it);
        return s;
    }
    virtual vector<State<N> *> search (ISearchable<N>* searchable)  = 0;


    virtual vector<State<N> *> backTrace(State<N> *s, ISearchable<N> *searchable)
    {
        vector<State<N> *> path;
        State<N>* initState = searchable->getInitialState();
        path.push_back(s);
        while (!(*s == *initState)) {
            path.push_back(s->getCameFrom());
            s = s->getCameFrom();  //.State<N>::getCameFrom();
        }

        reverse(path.begin(), path.end());
        return path;
    }

};
#endif //UNTITLED6_SEARCHER_H
