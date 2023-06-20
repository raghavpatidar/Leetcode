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

Problem : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int solve(int idx, int prev, int n, vector<vector<int>>& cuboids, vector<vector<int>>& dp) {
        if (idx == n)return 0;

        //memo
        if (dp[idx][prev + 1] != -1)return dp[idx][prev + 1];

        int pick = 0, notPick = 0;
        if (prev == -1 || (cuboids[idx][0] >= cuboids[prev][0] && cuboids[idx][1] >= cuboids[prev][1] && cuboids[idx][2] >= cuboids[prev][2])) {
            pick = cuboids[idx][2] + solve(idx + 1, idx, n, cuboids, dp);
        }
        notPick = solve(idx + 1, prev, n, cuboids, dp);

        return dp[idx][prev + 1] = max(pick, notPick);

    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& i : cuboids)sort(i.begin(), i.end());
        int n = cuboids.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        sort(cuboids.begin(), cuboids.end());
        return solve(0, -1, n, cuboids, dp);
    }
};