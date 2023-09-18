#include "queue.h"
#include "testQueue.h"

// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

// define default capacity of the queue
#define SIZE 10

// Constructor to initialize queue
Queue::Queue(int size)
    : arr(new int[size]), capacity(size), front(0), rear(-1), count(0)
{}

// Destructor to free memory allocated to the queue
Queue::~Queue()
{
    delete[] arr; // corrected to delete array
}

// Utility function to remove front element from the queue
void Queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
}

// Utility function to add an item to the queue
void Queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Utility function to return front element in the queue
int Queue::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// Utility function to return the size of the queue
int Queue::size()
{
    return count;
}

// Utility function to check if the queue is empty or not
bool Queue::isEmpty()
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool Queue::isFull()
{
    return (size() == capacity);
}

// main function
int main()
{
    testDequeue();
    testEnqueue();
    testPeek();
    testSize();
    testIsEmpty();
    testIsFull();

    return 0;
}
