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

Problem : https://leetcode.com/problems/distinct-subsequences/
Day : 7
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int  j, string& s, string& t, vector<vector<int>>& dp) {
        if (j == 0)return 1;
        if (i == 0)return 0;

        if (dp[i][j] != -1)return dp[i][j];

        //same
        int same = 0;
        if (s[i - 1] == t[j - 1]) {
            same = solve(i - 1, j - 1, s, t, dp);
        }
        int notSame = solve(i - 1, j, s, t, dp);

        return dp[i][j] = same + notSame;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, s, t, dp);
    }
};