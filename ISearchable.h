//
// Created by liran-baruch on 1/13/19.
//

#ifndef UNTITLED6_ISEARCHABLE_H
#define UNTITLED6_ISEARCHABLE_H

#include "State.h"
#include <vector>
using namespace std;
//Searchable interface.
template<typename N>
class ISearchable
{
public:
    virtual State<N>* getInitialState() = 0;
    virtual State<N>* getGoalState() = 0;
    virtual vector<State<N>*> getAllPosibbleState(State<N>*) = 0;
    virtual ~ISearchable(){};
};
#endif //UNTITLED6_ISEARCHABLE_H
