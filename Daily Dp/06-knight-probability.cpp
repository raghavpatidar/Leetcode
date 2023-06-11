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

Problem : https://leetcode.com/problems/knight-probability-in-chessboard/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // int dx[8] = {-2 , -2 ,-1 , -1 , 1 , 1 , 2 , 2};
    // int dy[8] = {1 , -1  ,2  , -2 , 2 , -2 , 1 , -1};
    vector<int>dx = { -2,-2,-1,-1,1,1,2,2 }, dy = { -1,1,-2,2,-2,2,1,-1 };

    double solve(int  r, int c, int k, int n, vector<vector<vector<double>>>& dp) {
        if (r < 0 || c < 0 || r >= n || c >= n)return 0.0;
        if (k == 0)return 1.0;
        if (dp[r][c][k] != -1)return dp[r][c][k];
        double cnt = 0;
        for (int i = 0; i < 8; i++) {
            cnt += (solve(r + dx[i], c + dy[i], k - 1, n, dp));
        }
        cnt = cnt / 8;
        return dp[r][c][k] = cnt;
        return cnt;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(k + 1, -1)));
        return solve(row, column, k, n, dp);
    }
};
