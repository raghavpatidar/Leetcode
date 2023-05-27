//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob :  https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1
// Day : 



#include<bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

//Function to push an integer into the stack.
void MyStack::push(int x) {
    // Your Code
    // avoid overflow
    if (top >= 1000)
        return;
    arr[++top] = x;
}

//Function to remove an item from top of the stack.
int MyStack::pop() {
    // Your Code  
    return top == -1 ? -1 : arr[top--];
}
