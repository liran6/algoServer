//
// Created by liran-baruch on 1/15/19.
//

#ifndef UNTITLED6_SOLVERTOSEARCHER_H
#define UNTITLED6_SOLVERTOSEARCHER_H

#include <string>
#include "Solver.h"
#include "ISearchable.h"
#include "Searcher.h"
#include "SearchableMatrix.h"
using namespace std;


class MatrixSolver : public Solver<ISearchable<pair<int, int>>*, string>
{
private:
    ISearcher< pair<int, int>> *searcher;
   // SearchableMatrix matrix;

public:
    MatrixSolver( ISearcher< pair<int, int>> *searcher){
        this->searcher = searcher;
        //this->matrix = new SearchableMatrix(inputMatrix);
    };
    virtual string solve(ISearchable<pair<int, int>>* matrix);
    virtual string pathDirection(vector<State<pair<int, int>> *> path);


};

#endif //UNTITLED6_SOLVERTOSEARCHER_H
