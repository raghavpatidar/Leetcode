/*
┌───────────────────────────────────────────────────────────────────────────────────────┐
│                      *-----------Raghav Patidar----------*                            |
|                   Fuck Ratings,Just Enjoy the Contest/Questions                       |
|                      I'm in Love with Experience and Learning.                        |
│                                                                                       |
|    Leetcode : https://leetcode.com/manito7/                                           |
│    Github : https://github.com/raghavpatidar                                          |
|    LinkedIn : https://www.linkedin.com/in/raghavpatidar07/                            |
|    Resume : https://drive.google.com/file/d/1nsTqWKSzxl-tcIXARi_b6vMSVcz57cVQ/view    |
|    Codeforces : https://codeforces.com/profile/raghavpatidar                          |
|                                                                                       |
└───────────────────────────────────────────────────────────────────────────────────────┘

Problem:  https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
Day :
*/

#include<bits/stdc++.h>
using namespace std;




vector<long long> printFirstNegativeInteger(long long int Arr[],
    long long int N, long long int K) {


    int i = 0, j = 0;
    long mini = 0;
    queue<pair<long long, int>> q;
    vector<long long>ans;
    while (j < N) {
        if (Arr[j] < 0) q.push({ Arr[j],j });


        if (j - i + 1 == K) {
            // get out window;
            if (!q.empty())ans.push_back(q.front().first);
            else ans.push_back(0);

            if (!q.empty()) {
                if (q.front().second == i)q.pop();
            }
            i++;
        }
        j++;
    }
    return ans;
}