//
// Created by liran-baruch on 1/16/19.
//
#include "MatrixSolver.h"


string MatrixSolver::solve(ISearchable<pair<int, int>> *matrix) {
    vector<State<pair<int, int>> *> path;
    path = this->searcher->search(matrix);
    return pathDirection(path);
 //   return getPathInstructions(path);
}

pair<int,int> operator - (const pair<int,int> &a ,const  pair<int,int> &b )
{
    return make_pair(a.first - b.first, a.second - b.second);
}

string MatrixSolver::pathDirection(vector<State<pair<int, int>> *> path){
    string direction = "";
    string comma = ",";
    pair<int, int> up = make_pair(1,0);
    pair<int, int> down = make_pair(-1,0);
    pair<int, int> left = make_pair(0,1);
    pair<int, int> right = make_pair(0,-1);
    for (int i = 0; i <path.size() - 1 ; i++) {
        pair<int, int> initialState = make_pair (path[i]->getNode()->first, path[i]->getNode()->second);
        pair<int, int> nextState = make_pair (path[i+1]->getNode()->first, path[i+1]->getNode()->second);
        pair<int, int> guid = initialState - nextState;
        if(guid == up){
           direction += "Up";
        }
        if(guid == down){
            direction += "Down";
        }
        if(guid == left){
            direction += "Left";
        }
        if(guid == right){
            direction += "Right";
        }
        direction += comma;
    }
    direction = direction.substr(0,direction.size() - comma.size());
    return direction;
//    for (auto it = path.begin(); it != path.end(); it++) {
//        State<pair<int, int>> *initialState = *it;
//        State<pair<int, int>> *nextState = *it;
//        pair<int, int> *init = initialState->getNode();
//    }

}
