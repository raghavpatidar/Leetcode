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

Problem : https://leetcode.com/problems/maximum-product-subarray/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int idx, int prev, vector<int>& nums, map<pair<int, int>, int>& dp) {
        if (idx == 0)return prev;

        if (dp.count({ idx , prev }))return dp[{idx, prev}];

        if (prev == -1e9) {
            int pick = solve(idx - 1, nums[idx - 1], nums, dp);
            int notPick = solve(idx - 1, nums[idx - 1], nums, dp);
            return  dp[{idx, prev}] = max({ pick, notPick, prev });
        }

        int pick = solve(idx - 1, prev * nums[idx - 1], nums, dp);
        int notPick = solve(idx - 1, nums[idx - 1], nums, dp);

        return  dp[{idx, prev}] = max({ pick, notPick, prev });

    }
    int solvingUsingPrefixSuffixApproach(vector<int>& nums, int n) {
        int pre = 1, suff = 1;
        int maxi = -1e9;
        bool isZero = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pre = 1;
                isZero = true;
                continue;
            }
            pre = pre * nums[i];
            maxi = max(pre, maxi);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                suff = 1;
                isZero = true;
                continue;
            }
            suff = suff * nums[i];
            maxi = max(suff, maxi);
        }

        if (isZero)maxi = max(maxi, 0);
        return maxi;
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // map<pair<int,int>,int>dp;
        // int dpSolutionAns =  solve(n , -1e9 , nums , dp);
        int preSuffAns = solvingUsingPrefixSuffixApproach(nums, n);
        return  preSuffAns;
    }
};