//
// Created by liran-baruch on 1/14/19.
//

#ifndef UNTITLED6_SEARCHABLEMATRIX_H
#define UNTITLED6_SEARCHABLEMATRIX_H
#include "ISearchable.h"
#include <list>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class SearchableMatrix : public ISearchable<pair<int,int>>
{
    vector<vector<State<pair<int,int>>>> matrix;
    int length;
    int width;
    State<pair<int,int>> *initialState;
    State<pair<int,int>> *goalState;
public:
    SearchableMatrix(vector<string> inputMatrix) {
        int i = 0,j = 0;
        vector<vector<State<pair<int,int>>>> temp;
        pair<int,int>* tempPair;
        State<pair<int,int>> *vertex;
        for (auto it = inputMatrix.begin(); it != inputMatrix.end(); it++)
        {
            vector<State<pair<int,int>>> line;
            vector<string> values = splitToExpression(*it,",");
            for (auto it = values.begin(); it != values.end(); it++)
            {
                tempPair = new pair<int, int>(i, j);
                vertex = new State<pair<int,int>>(tempPair, stod(*it));
                line.push_back(*vertex);
                j++;
            }
            temp.push_back(line);
            j = 0;
            ++i;
        }
        pair<int,int> *initialPair, *goalPair;
        initialPair = new pair<int,int>(temp[temp.size() - 2][0].getCost(), temp[temp.size() - 2][1].getCost());
        goalPair = new pair<int,int>(temp[temp.size() - 1][0].getCost(), temp[temp.size() - 1][1].getCost());
        double initialCost = temp[initialPair->first][initialPair->second].getCost();
        double goalCost = temp[goalPair->first][goalPair->second].getCost();;
        this->initialState = new State<pair<int,int>>(initialPair, initialCost);
        this->goalState = new State<pair<int,int>>(goalPair, goalCost);
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
        return this->initialState;
    }
    virtual State<pair<int,int>>* getGoalState(){
        return this->goalState;
    }

    virtual vector<State<pair<int,int>>*> getAllPossibleState(State<pair<int,int>> *state){
        vector<State<pair<int,int>>*> possibleStates;
        int x = this->width - 1 , y = this->length - 1;
        int vertexX = state->getNode()->second , vertexY = state->getNode()->first;
        bool getAbove = (vertexY != 0);
        bool getBelow = (vertexY < y);
        bool getLeft = (vertexX != 0);
        bool getRight = (vertexX < x);

//        //if for some reason the vertex is out of bounds
//        if(vertexX > x || vertexY > y){
//            throw runtime_error("vertex out of bounds, can't scan for possible states");
//
//        }

        if(getAbove){
            possibleStates.push_back(&this->matrix[vertexY - 1][vertexX]);
        }
        if(getBelow){
            possibleStates.push_back(&this->matrix[vertexY + 1][vertexX]);
        }
        if (getLeft){
            possibleStates.push_back(&this->matrix[vertexY][vertexX-1]);
        }
        if (getRight){
            possibleStates.push_back(&this->matrix[vertexY][vertexX + 1]);
        }


        /*//upper left
        else if(vertexX == vertexY == 0){
            //if there is another vertex from it's right.
            if(vertexX < x){
                possibleStates.push_back(&this->matrix[vertexY][vertexX + 1]);
            }//if there is another vertex from it's bottom.
            if(vertexY < y){
                possibleStates.push_back(&this->matrix[vertexY + 1][vertexX]);
            }

        }//upper right
        else if(vertexX == x && vertexY == 0){
            //if there is another vertex from it's bottom.
            if(vertexY < y){
                possibleStates.push_back(&this->matrix[vertexY + 1][vertexX]);
            }// add the vertex from it's left.
            possibleStates.push_back(&this->matrix[vertexY][vertexX-1]);

        }//upper
        else if(vertexY == 0){
            //if there is another vertex from it's bottom.
            if(vertexY < y){
                possibleStates.push_back(&this->matrix[vertexY + 1][vertexX]);
            }// add the vertex from it's left.
            possibleStates.push_back(&this->matrix[vertexY][vertexX-1]);
            //add the vertex from its right
            possibleStates.push_back(&this->matrix[vertexY][vertexX + 1]);


        }//bottom left
        else if (vertexX == 0 && vertexY == y){
            //if there is another vertex from it's right.
            if(vertexX < x){
                possibleStates.push_back(&this->matrix[vertexY][vertexX + 1]);
            }//add the vertex from above
            possibleStates.push_back(&this->matrix[vertexY-1][vertexX]);

        }//bottom right
        else if(vertexX == x && vertexY == y){
            //add the vertex from above
            possibleStates.push_back(&this->matrix[vertexY-1][vertexX]);
            // add the vertex from it's left.
            possibleStates.push_back(&this->matrix[vertexY][vertexX-1]);

        }//bottom
        else if(vertexY == y){
            //add the vertex from above
            possibleStates.push_back(&this->matrix[vertexY-1][vertexX]);
            // add the vertex from it's left.
            possibleStates.push_back(&this->matrix[vertexY][vertexX-1]);
            //add the vertex from its right
            possibleStates.push_back(&this->matrix[vertexY][vertexX + 1]);

        }//somewhere in the middle
        else{
            //add the vertex from above
            possibleStates.push_back(&this->matrix[vertexY-1][vertexX]);
            // add the vertex from it's left.
            possibleStates.push_back(&this->matrix[vertexY][vertexX-1]);
            //add the vertex from its right
            possibleStates.push_back(&this->matrix[vertexY][vertexX + 1]);
            //add the vertex from its bottom.
            possibleStates.push_back(&this->matrix[vertexY + 1][vertexX]);
        }


        */
        return possibleStates;
    }
};
#endif //UNTITLED6_SEARCHABLEMATRIX_H
