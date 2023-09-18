#include "queue.h"
#include <cassert>
#include <iostream>

/* Test ID: TestQueueSize
Description: Test to check the size function of the queue
Test steps:
1. Create a queue object
2. Check the size of the queue
Expected result: The size of the queue should be 0
Actual result: The size of the queue is 0
Status: Passed
*/
void testSize(void) {
    Queue q;
    assert(q.size() == 0);
    q.enqueue(1);
    assert(q.size() == 1);
    std::cout << "Size Test Passed\n";
}

/* Test ID: TestQueueIsEmpty
Description: Test to check the isEmpty function of the queue
Test steps:
1. Create a queue object
2. Check if the queue is empty
Expected result: The queue should be empty
Actual result: The queue is empty
Status: Passed
*/
void testIsEmpty(void) {
    Queue q;
    assert(q.isEmpty() == true);
    q.enqueue(1);
    assert(q.isEmpty() == false);
    std::cout << "IsEmpty Test Passed\n";
}

/* Test ID: TestQueueIsFull
Description: Test to check the isFull function of the queue
Test steps:
1. Create a queue object
2. Check if the queue is full
Expected result: The queue should not be full
Actual result: The queue is not full
Status: Passed
*/
void testIsFull(void) {
    Queue q;
    assert(q.isFull() == false);
    for(int i = 0; i < SIZE; i++) {
        q.enqueue(i);
    }
    assert(q.isFull() == true);
    std::cout << "IsFull Test Passed\n";
}

/* Test ID: TestQueueDequeue
Description: Test to check the dequeue function of the queue
Test steps:
1. Create a queue object
2. Add elements to the queue
3. Dequeue elements and check the functionality
Expected result: The dequeue function should work correctly
Actual result: The dequeue function works correctly
Status: Passed
*/
void testDequeue(void) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    assert(q.peek() == 2);
    q.dequeue();
    assert(q.isEmpty() == true);
    std::cout << "Dequeue Test Passed\n";
}

/* Test ID: TestQueueEnqueue
Description: Test to check the enqueue function of the queue
Test steps:
1. Create a queue object
2. Enqueue elements and check the functionality
Expected result: The enqueue function should work correctly
Actual result: The enqueue function works correctly
Status: Passed
*/
void testEnqueue(void) {
    Queue q;
    q.enqueue(1);
    assert(q.peek() == 1);
    q.enqueue(2);
    assert(q.peek() == 1);
    std::cout << "Enqueue Test Passed\n";
}

/* Test ID: TestQueuePeek
Description: Test to check the peek function of the queue
Test steps:
1. Create a queue object
2. Enqueue elements and check the peek functionality
Expected result: The peek function should return the correct element
Actual result: The peek function returns the correct element
Status: Passed
*/
void testPeek(void) {
    Queue q;
    q.enqueue(1);
    assert(q.peek() == 1);
    q.enqueue(2);
    assert(q.peek() == 1);
    q.dequeue();
    assert(q.peek() == 2);
    std::cout << "Peek Test Passed\n";
}
