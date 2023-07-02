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

Problem : https://leetcode.com/problems/longest-arithmetic-subsequence/description/
Day : 412
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // // pair<int , int> dp[nums.size()+1][520];
        vector<vector<pair<int, int>>>dp(nums.size() + 1, vector<pair<int, int>>(501));
        // memset(dp , 0 , sizeof(dp));
        unordered_map<int, int > m;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 501; j++) {
                int x = nums[i] - j;
                int y = nums[i] + j;
                if (m.find(x) != m.end()) {
                    dp[i][j].first = dp[m[x]][j].first + 1;
                }
                else {
                    dp[i][j].first = 1;
                }
                if (m.find(y) != m.end()) {
                    dp[i][j].second = dp[m[y]][j].second + 1;
                }
                else {
                    dp[i][j].second = 1;
                }

                ans = max({ ans , dp[i][j].first , dp[i][j].second });
            }
            m[nums[i]] = i;
        }

        return ans;

    }
};