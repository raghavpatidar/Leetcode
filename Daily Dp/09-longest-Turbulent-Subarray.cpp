/*
┌────────────────────────────────────────────────────────────────────────────────────────┐
│                      *-----------Raghav Patidar----------*                             |
|                   Fuck Ratings,Just Enjoy the Contest/Questions                        |
|                      I'm in Love with Experience and Learning.                         |
│                                                                                        |
|    Leetcode   : https://leetcode.com/manito7/                                          |
|    CodingNinja: https://bit.ly/3IW2Nqi                                                 |
│    Github     : https://github.com/raghavpatidar                                       |
|    LinkedIn   : https://www.linkedin.com/in/raghavpatidar07/                           |
|    Resume     : https://drive.google.com/file/d/1nsTqWKSzxl-tcIXARi_b6vMSVcz57cVQ/view |
|    Codeforces : https://codeforces.com/profile/raghavpatidar                           |
|                                                                                        |
└────────────────────────────────────────────────────────────────────────────────────────┘

Problem : https://leetcode.com/problems/longest-turbulent-subarray/
Day : 9
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& v, int i, bool t, int prev)
    {
        if (i == v.size())
            return 0;
        if (dp[prev][t] != -1)
            return dp[prev][t];
        if (prev == 0)
        {
            return dp[prev][t] = max({ 1 + solve(v,i + 1,0,i + 1),1 + solve(v,i + 1,1,i + 1),solve(v,i + 1,t,prev) });
        }
        else if (t == 0)
        {
            if (v[i] < v[prev - 1])
                return dp[prev][t] = 1 + solve(v, i + 1, 1, i + 1);
        }
        else
        {
            if (v[i] > v[prev - 1])
                return dp[prev][t] = 1 + solve(v, i + 1, 0, i + 1);
        }
        return dp[prev][t] = 0;
    }
    int maxTurbulenceSize(vector<int>& arr)
    {
        int n = arr.size();
        dp.resize(n + 1, vector<int>(3, -1));
        return solve(arr, 0, 0, 0);
    }
};