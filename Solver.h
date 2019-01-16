//
// Created by yuval on 1/9/19.
//

#ifndef UNTITLED6_SOLVER_H
#define UNTITLED6_SOLVER_H
//template <class >
template<typename P, typename S>
class Solver
{
public:
    virtual S solve(P problem) = 0;
    virtual ~Solver(){};
};
#endif //UNTITLED6_SOLVER_H
