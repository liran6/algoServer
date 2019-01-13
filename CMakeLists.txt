cmake_minimum_required(VERSION 3.13)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled6 main.cpp Server.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Problem.h Solution.h MySerialServer.cpp MySerialServer.h)