//
// Created by yuval on 1/14/19.
//

#ifndef UNTITLED6_THREADSVECTOR_H
#define UNTITLED6_THREADSVECTOR_H

#include <pthread.h>
#include <vector>
#include <unistd.h>
#include "Problem.h"

#define THREAD_POOL_SIZE 5

using namespace std;

class ThreadsPool{
public:
    bool isActive;
    pthread_t* thread;
    pthread_mutex_t lock;

    ThreadsPool(pthread_t *thrd){
        this->thread = thrd;
        isActive = true;
    };

    void addThread(pthread_t *thread, vector<pthread_t*> vector_of_threads){
        vector_of_threads.push_back(thread);
    };

    void terminateThread(){
        pthread_mutex_destroy(&lock);
        isActive = false;
    };

    virtual ~ThreadsPool(){
        delete[] thread;
    };

private:

    void solveProblam(){
        while (this->isActive) {
            pthread_mutex_lock(&lock);

                pthread_mutex_unlock(&lock);
                task->execute();
            }
            else {
                pthread_mutex_unlock(&lock);
                sleep(1);
            }
        }
    }

};


#endif //UNTITLED6_THREADSVECTOR_H
