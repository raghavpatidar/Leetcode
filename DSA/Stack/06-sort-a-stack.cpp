//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Day : 
#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>



void sortStack(stack<int>& st)
{
    if (st.size() == 1)return;

    int x = st.top();
    st.pop();
    sortStack(st);


    stack<int> temp;
    while (st.size() > 0 and st.top() > x) {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while (temp.size() > 0) {
        st.push(temp.top());
        temp.pop();
    }
    // Write your code here
}