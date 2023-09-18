#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include <limits>

#define SIZE 10

class Queue
{
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = SIZE);
    ~Queue();

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

#endif // QUEUE_H
