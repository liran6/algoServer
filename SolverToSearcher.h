//
// Created by liran-baruch on 1/15/19.
//

#ifndef UNTITLED6_SOLVERTOSEARCHER_H
#define UNTITLED6_SOLVERTOSEARCHER_H

#include <string>
#include "Solver.h"
#include "Searcher.h"
#include "SearchableMatrix.h"
using namespace std;

template <typename P, typename S>
class SolverToSearcher : public Solver<ISearchable<P>, S>
{
private:
    Searcher<S, P> *searcher;
    SearchableMatrix matrix;

public:
    SolverToSearcher(Searcher<S,P> *searcher , vector<string> &inputMatrix){
        this->searcher = searcher;
        this->matrix = new SearchableMatrix(inputMatrix);
    }

    Searcher<S, P> *getSearcher() const {
        return searcher;
    }

    const SearchableMatrix &getMatrix() const {
        return matrix;
    }

};

#endif //UNTITLED6_SOLVERTOSEARCHER_H
