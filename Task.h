/*
//
// Created by yuval on 1/14/19.
//


 // Liran - We will delete this class *&^%$


#ifndef UNTITLED6_TASK_H
#define UNTITLED6_TASK_H


class Task {

    void* (*func)(void *arg);
    void *arg;

public:
    Task(void* (*func)(void *arg), void* arg);

    void execute() {
        func(arg);
    }

    virtual ~Task() {}
};


#endif //UNTITLED6_TASK_H
*/
