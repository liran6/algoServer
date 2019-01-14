//
// Created by liran-baruch on 1/13/19.
//

#ifndef UNTITLED6_STATE_H
#define UNTITLED6_STATE_H
using namespace std;
template < typename N>

class State{
private:
    N* node;
    double cost;
    State<N>* cameFrom;

public:
    State(N* node, double cost){
        this->node = node;
        this->cost = cost;
        this->cameFrom = nullptr;
    }
//    State(N &node){
//        this->node = node;
//    }
    bool operator==(State<N> state) {
        return this->node == state.getNode();
    }

    N getNode() const {
        return node;
    }

    void setNode(N node) {
        this->node = node;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    State<N> *getCameFrom() const {
        return cameFrom;
    }

    void setCameFrom(State<N> *cameFrom) {
        this->cameFrom = cameFrom;
    }
};
#endif //UNTITLED6_STATE_H
