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

Problem : https://leetcode.com/problems/target-sum/description/
Day : 5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        //base case
        if (i < 0)
            return target == 0;

        //check the cache
        if (dp[i][target] != -1)
            return dp[i][target];

        int pick = 0, notpick = 0;
        notpick = solve(i - 1, target, nums, dp);
        if (target >= nums[i])
            pick = solve(i - 1, target - nums[i], nums, dp);

        return  dp[i][target] = pick + notpick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = 0;
        for (int i = 0;i < n;i++)
            total_sum += nums[i];
        int T = target + total_sum;
        if (T % 2 || T < 0)
            return 0;
        vector<vector<int>>dp(n, vector<int>(T / 2 + 1, -1));
        return solve(n - 1, T / 2, nums, dp);
    }
};