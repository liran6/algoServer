//
// Created by liran-baruch on 1/16/19.
//

#ifndef UNTITLED6_BFS_H
#define UNTITLED6_BFS_H



#include "ISearchable.h"
#include "Searcher.h"
#include <list>
#include <deque>
#define IS_USING_STACK  false

template <typename N>
class BFS : public Searcher<N> {
public:

/*    solution backTrace(State<N> s, ISearchable<N> *searchable)
    {
        deque<string> path;
        string ans = "";
        State<N> initState = searchable->getInitialState();
        State<N> *currState = new State<N>(s.getState(),s.getCost(),s.getCameFrom(),s.getCameFromDir());
        while (!(currState->Equals(initState))) {
            path.push_front(currState->getCameFromDir());
            currState = currState->getCameFrom();  //.State<N>::getCameFrom();
        }

        auto it = path.begin();
        ans += *it;

        for (; it != path.end(); it++)
        {
            ans += ",";
            ans += *it;
        }
        return ans;
    }*/

    vector<State<N> *> search(ISearchable<N>* searchable)
    {
        State<N>* s = searchable->getInitialState();
        deque<State<N>*> closed;
        Searcher<N>::addDequeOpenList(s);

        while (Searcher<N>::dequeOpenList.size() > 0)
        {
            State<N>* n = Searcher< N>::popDequeOpenList(IS_USING_STACK);
            closed.push_back(n);
            bool x = *searchable->getGoalState() == *n;
            if (*(searchable->getGoalState()) == *n) {
               return Searcher<N>::backTrace(n, searchable);
            }
            State<N>* parent = new State<N>(n->getNode(), n->getCost());
            vector<State<N>*> successors = searchable->getAllPossibleState(parent); // calling the delegated method, returns a list of states with n as a parent
            for (auto it = successors.begin(); it != successors.end(); it++)
            {
                if (!((Searcher<N>::isInDequeOpenList(*it))) && !(isInSet(&closed,*it)))
                {
                    State<N>* s = *it;
                    s->setCameFrom(n);
                    Searcher<N>::addDequeOpenList(s);
                }
            }
        }
    }

    bool isInSet(deque<State<N>*>* setOfState,State<N>* currState)
    {
        for (auto it = setOfState->begin(); it != setOfState->end(); it++)
        {
            State<N>* s = *it;
            if(*s == *currState)
                return true;
        }
        return false;
    }
};

























/*#include "Searcher.h"
#include <queue>
#include <iostream>

using namespace std;

template < typename  N>
class BFS : public Searcher< N> {
    int numOfNodes;
    double totalPathCost;
public:
    BFS(){
        numOfNodes = 0;
        totalPathCost = 0;
    }

    *//**
     * Checks if the node has already been visited during the BFS scan.
     * @param nodesVec - vector of nodes that have been visited.
     * @param node - node to check.
     * @return true / false .
     *//*
    bool hasNodeBeenVisited(vector<State<N> *> nodesVec, State<N> *node) {
        for (State<N> *state : nodesVec) {
            if (state->equalsTo(node)) {
                return true;
            }
        }
        return false;
    }
    //BFS algorithm.
    vector<State<N> *> search(ISearchable<N> *searchable) override {
        resetMembers();
        vector<State<N> *> nodesVisited;
        vector<State<N> *> path;
        //set the current state to the initial we received from the problem.
        State<N> *currentState = searchable->getInitialState();
        currentState->setCameFrom(currentState);
        //put it into the nodes that have been visited.
        nodesVisited.emplace_back(currentState);
        State<N> *goalState = searchable->getGoalState();
        queue<State<N> *> stateQ;
        stateQ.push(currentState);
        //go over the state queue until it is empty.
        while (!stateQ.empty()) {

            currentState = stateQ.front();
            stateQ.pop();
            this->numOfNodes += 1;
            //the node we are currently on is the goal node.
            if (currentState->equalsTo(goalState)) {
                path.insert(path.begin(), currentState);
                this->totalPathCost += currentState->getCost();
                //restores the path from the initial to the goal.
                while (!(currentState->equalsTo(
                        searchable->getInitialState()))) {
                    currentState = currentState->getCameFrom();
                    path.insert(path.begin(), currentState);
                    this->totalPathCost += currentState->getCost();
                }
                //returns the path.
                return path;
            }

            //goes over all sons of the current state and expands them.
            for (State<N> *adj : searchable->getPossibleStates(currentState)) {
                //already visited, continue.
                if (hasNodeBeenVisited(nodesVisited, adj)) {
                    continue;
                }
                //otherwise, insert to the nodes visited , set it's cameFrom and insert into state queue.
                nodesVisited.emplace_back(adj);
                adj->setCameFrom(currentState);
                stateQ.push(adj);
            }
        }
        //could not find path from requested initial to goal.
        return path;
    }

    int getNumOfNodes() const {
        return numOfNodes;
    }

    double getTotalPathCost() const {
        return totalPathCost;
    }

    void resetMembers(){
        this->totalPathCost = 0;
        this->numOfNodes = 0;
    }*/

//};
#endif //UNTITLED6_BFS_H
