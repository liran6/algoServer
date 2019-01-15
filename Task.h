//
// Created by yuval on 1/14/19.
//

#ifndef UNTITLED6_TASK_H
#define UNTITLED6_TASK_H


class Task {

    void* (*func)(void *arg);
    void *arg;

public:
    Task(void * (*func)(void *arg), void* arg);

    void execute() {
        func(arg);
    }

    virtual ~Task() {}
};


#endif //UNTITLED6_TASK_H
