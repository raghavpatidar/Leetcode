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

Problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
Day : 411
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
        if (idx == 0)
        {
            if (buy)return -1 * (fee + prices[0]);
            else return 0;
        }
        if (dp[idx][buy] != -1)return dp[idx][buy];

        int pick = 1e9;
        int noPick = solve(idx - 1, buy, fee, prices, dp);
        if (buy) {
            // can sell 
            pick = solve(idx - 1, 0, fee, prices, dp) - prices[idx] - fee;
        }
        else {
            // can buy 
            pick = solve(idx - 1, 1, fee, prices, dp) + prices[idx];
        }

        return dp[idx][buy] = max(pick, noPick);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(n - 1, 0, fee, prices, dp);
    }
};