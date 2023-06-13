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

Problem : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
Day :
*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int solve(int  i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (i == 0 and j == 0)return 0;
        if (i == 0)return t[j - 1] + solve(i, j - 1, s, t, dp);
        if (j == 0)return s[i - 1] + solve(i - 1, j, s, t, dp);


        if (dp[i][j] != -1)return dp[i][j];

        int same = 1e9;
        if (s[i - 1] == t[j - 1]) {
            return solve(i - 1, j - 1, s, t, dp);
        }
        int notSameMoveFirst = s[i - 1] + solve(i - 1, j, s, t, dp);
        int notSameMoveSecond = t[j - 1] + solve(i, j - 1, s, t, dp);

        return dp[i][j] = min(notSameMoveFirst, notSameMoveSecond);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return  solve(n, m, s1, s2, dp);

    }
};