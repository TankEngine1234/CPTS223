/*
  Poor Attributes in the Code:

  1. Global Variables: The use of #define to declare global constants (like SIZE) can lead to issues 
     as they don't have any scope. Using const or constexpr variables would be a better choice.

  2. Error Handling: The error handling in the code is not robust. Terminating the program 
     immediately upon encountering an error (like queue overflow or underflow) is not a good practice. 
     It would be better to handle errors gracefully, possibly by returning error codes or throwing exceptions.

  3. Lack of Modularity: The main.cpp file contains both the class definition and implementation, 
     which makes the code less modular and harder to maintain. Separating the class definition 
     (in a header file) and implementation (in a source file) would be a better approach.

  4. Inefficient Data Structure: The queue is implemented using an array, which can lead to inefficient 
     operations, especially for large queues. Using a linked list or a circular buffer could be a more 
     efficient choice.

  5. Hardcoded Values: The code contains hardcoded values (like the error messages and exit codes), 
     which can make the code less flexible and harder to maintain. Using named constants or 
     configuration files to store these values would be a better approach.

*/

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
