cmake_minimum_required(VERSION 3.13)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled6 main.cpp Server.h MySerialServer.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Problem.h Solution.h State.h ISearchable.h Searcher.h ISearcher.h MyParallelServer.cpp MyParallelServer.h SearchableMatrix.h MatrixSolver.h MyClientHandler.cpp MyClientHandler.h Greater.h MatrixSolver.cpp BFS.h BestFirstSearch.h)