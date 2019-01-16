#include <string>
#include <fstream>
#include <iostream>
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "SearchableMatrix.h"
#include "MatrixSolver.h"
#include "Solver.h"
#include "State.h"
#include "BFS.h"
#include "BestFirstSearch.h"

//TODO: MATRIX
using namespace std;
int main(int argc, char **argv) {
//    std::string input, line;
//    std::ifstream matrixReader("matrices.txt");
//    if (matrixReader.is_open()) {
//        while (matrixReader.good()) {
//            getline(matrixReader, line);
//            input += line + "\n";
//        }
//    }


/*State<pair<int, int>> *x = new State<pair<int, int>>(new pair<int, int>(1, 1), 2) ;
State<pair<int, int>> *y = new State<pair<int, int>>(new pair<int, int>(1, 1), 2) ;
State<pair<int, int>> *z = x;
z->setNode(*x - *y);
int c = 4;*/
//    pair<int, int> *a = new pair<int, int>(1, 1);
//State<pair<int, int>>* s = new State<pair<int, int>>(a, 0);
//State<pair<int, int>>* t = new State<pair<int, int>>(a, 0);
//bool x = (*s == *t);
//int r = 5;
//

    vector<string> mat;
    mat.push_back("1,2,3");
    mat.push_back("4,5,6");
    mat.push_back("7,8,9");
    mat.push_back("0,0");
    mat.push_back("2,2");
    SearchableMatrix *matrix = new SearchableMatrix(mat);
    auto x = new BFS<pair<int,int>> ;
    MatrixSolver * matrixSolver = new MatrixSolver(x);
    string s = matrixSolver->solve(matrix);
    cout<<s<< endl;
    //string move[4] = {"Up","Down","Left","Right"};
    //ISearchable<pair<int,int>>* mt = new matrixProblem(matrix,enter,exit);
    //State<vector<int>> s = State<vector<int>>(enter, 3, NULL);
    //list<State<vector<int>>> x;
    //x = mt->getAllPossibleStates(s);

    //ISearcher<vector<State<pair<int,int>>>> *b = new BFS<vector<State<pair<int,int>>>>();
    //vector<State<pair<int,int>>*> sol = b->search(matrix);
   // int x = b->getNumberOfNodesEvaluate();



/*


    vector<string> mat;
    mat.push_back("1,2,3");
    mat.push_back("4,5,6");
    mat.push_back("7,8,9");
    mat.push_back("0,0");
    mat.push_back("2,2");


    SearchableMatrix *matrix = new SearchableMatrix(mat);
   ISearcher<vector<vector<State<pair<int,int>>>>> s = new ISearcher< vector<vector<State<pair<int,int>>>>>(matrix);
    MatrixSolver * matrixSolver = new MatrixSolver(matrix);
    //string h = new MatrixSolver(matrix).solve;
    int c = 4;

*/


//    SearchableMatrix *searchableMatrix = new SearchableMatrix(matrix);
//    DFS<std::pair<int, int>> *dfs = new DFS<std::pair<int, int>>();
//    //Searchable<SearchableMatrix> *searchable = new Searchable<SearchableMatrix>();
//    State<std::pair<int,int>> state1;
//    State<std::pair<int,int>> state2;
//
//    pair<int,int> *pair1 = new pair<int,int>(0,0);
//    state1.setState(*pair1);
//    pair<int,int> *pair2 = new pair<int,int>(3,3);
//    state2.setState(*pair2);
//
//    dfs->setSource(state1);
//    dfs->setDestination(state2);
//    dfs->search(searchableMatrix);




//    if (argc < 1) throw "usage: <executable> <port>";
//
//    int port = std::stoi(argv[1]);
//
//    //auto stringSolver = new server_side::StringReverser();
//    auto matrixSolver = new server_side::MatrixSolver();
//    auto serialServer = new server_side::MySerialServer();
//    auto fCacheManager = new server_side::FileCacheManager();
//    auto handler = new server_side::MyTestClientHandler(matrixSolver, fCacheManager);
//
//    serialServer->open(port, handler);
//
//
//    getchar();
//
//
//    serialServer->stop();

    return 0;

}

//flush and free memory