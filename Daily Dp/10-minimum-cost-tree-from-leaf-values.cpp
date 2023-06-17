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

Problem : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
Day : 10
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    pair<int, int> solve(int i, int j, vector<int>& arr, vector<vector<pair<int, int>>>& dp) {
        if (i == j)return { 0 , arr[i] };
        if (i > j)return { 1e9 , 1 };
        if (dp[i][j] != make_pair(-1, -1))return dp[i][j];
        pair<int, int> mini = { 1e9 ,1 };
        for (int k = i; k < j; k++) {
            auto left = solve(i, k, arr, dp);
            auto right = solve(k + 1, j, arr, dp);
            pair<int, int> temp = { left.second * right.second , max(left.second , right.second) };
            temp.first = temp.first + left.first + right.first;
            if (temp.first < mini.first) {
                mini = temp;
            }
        }
        return dp[i][j] = mini;


    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, { -1 , -1 }));
        auto ans = solve(0, arr.size() - 1, arr, dp);
        return ans.first;

    }
};