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

Problem : https://leetcode.com/problems/max-dot-product-of-two-subsequences/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1)return dp[i][j];
        int use = nums1[i] * nums2[j] + solve(i - 1, j - 1, nums1, nums2, dp);
        int noUsei = solve(i - 1, j, nums1, nums2, dp);
        int noUsej = solve(i, j - 1, nums1, nums2, dp);
        return dp[i][j] = max({ use , noUsei , noUsej });
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = solve(n - 1, m - 1, nums1, nums2, dp);
        int mini1 = *min_element(nums1.begin(), nums1.end());
        int maxi1 = *max_element(nums1.begin(), nums1.end());
        int mini2 = *min_element(nums2.begin(), nums2.end());
        int maxi2 = *max_element(nums2.begin(), nums2.end());
        if (ans != 0)return ans;
        return max(mini1 * maxi2, maxi1 * mini2);
    }
};