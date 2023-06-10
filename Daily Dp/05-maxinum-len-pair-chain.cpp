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

Problem : https://leetcode.com/problems/maximum-length-of-pair-chain/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int idx, int previdx, vector<vector<int>>& pairs, vector<vector<int>>& dp) {
        if (idx == pairs.size()) {
            return 0;
        }
        if (dp[idx][previdx + 1] != -1)return dp[idx][previdx + 1];

        int notPick = solve(idx + 1, previdx, pairs, dp);
        int pick = 0;
        if (previdx == -1 || pairs[idx][0] > pairs[previdx][1]) {
            pick = 1 + solve(idx + 1, idx, pairs, dp);
        }
        return dp[idx][previdx + 1] = max(pick, notPick);
    }

    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0])return true;
        if (a[0] > b[0])return false;
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        sort(pairs.begin(), pairs.end(), comp);
        int ans = solve(0, -1, pairs, dp);
        return ans;

    }
};