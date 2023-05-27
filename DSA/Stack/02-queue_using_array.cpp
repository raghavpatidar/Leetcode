//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : 
// Day : 


/*
    Problem Link: https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1/
*/

#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode* next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue() { front = 0;rear = 0; }
    void push(int);
    int pop();
};

//Function to push an element x in a queue.
void MyQueue::push(int x) {
    // Your Code
    // avoid overflow
    if (rear >= 100005)
        return;
    arr[rear++] = x;
}

//Function to pop an element from queue and return that element.
int MyQueue::pop() {
    // Your Code 
    return front == rear ? -1 : arr[front++];
}
