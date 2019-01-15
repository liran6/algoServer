//
// Created by liran-baruch on 1/14/19.
//

#ifndef UNTITLED6_SEARCHABLEMATRIX_H
#define UNTITLED6_SEARCHABLEMATRIX_H
#include "ISearchable.h"
#include <list>
#include <vector>
using namespace std;

class SearchableMatrix : public ISearchable<pair<int,int>>
{
    vector<vector<int>> matrix;
    int length;
    int width;
    State<pair<int,int>> initialState;
    State<pair<int,int>> goalState;
public:
    SearchableMatrix(vector<string> inputMatrix) {
        vector<vector<int>> temp;
        for (auto it = inputMatrix.begin(); it != inputMatrix.end(); it++)
        {
            vector<int> line;
            vector<string> values = splitToExpression(*it,",");
            for (auto it = values.begin(); it != values.end(); it++)
            {
                line.push_back(std::stoi(*it));
            }
            temp.push_back(line);
        }
        pair<int,int> *initialPair, *goalPair;
        initialPair = new pair<int,int>(temp[temp.size() - 2][0], temp[temp.size() - 2][1]);
        goalPair = new pair<int,int>(temp[temp.size() - 1][0], temp[temp.size() - 1][1]);
        this->initialState.setNode(*initialPair);
        this->goalState.setNode(*goalPair);
        temp.pop_back();
        temp.pop_back();
        this->length = temp.size();
        this->width = temp[0].size();
        this->matrix = temp;
    }
    vector<string> splitToExpression(string line, string parser) {
        vector<string> valVec;
        string expression = "";
        unsigned long splitter = 0;

        while(splitter != -1){
            splitter = line.find(parser);
            expression = line.substr(0, splitter);
            if(expression.empty()){
                line = line.substr(splitter + 1, line.length());
                continue;
            }
            line = line.substr(splitter + 1, line.length());
            valVec.push_back(expression);
        }
        return valVec;
    }
    virtual State<pair<int,int>>* getInitialState(){
        return &this->initialState;
    }
    virtual State<pair<int,int>>* getGoalState(){
        return &this->goalState;
    }
};
#endif //UNTITLED6_SEARCHABLEMATRIX_H
