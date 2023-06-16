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

Problem : https://leetcode.com/problems/last-stone-weight-ii/
Day : 10
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void allPositiveSum(int idx, vector<int>& stones, int curr, set<int>& ans, vector<vector<int>>& dp) {
        if (idx == 0) {
            ans.insert(curr);
            return;
        }
        if (dp[idx][curr] != -1)return;
        allPositiveSum(idx - 1, stones, curr, ans, dp);
        allPositiveSum(idx - 1, stones, curr + stones[idx - 1], ans, dp);

        dp[idx][curr] = 1;
    }
    int lastStoneWeightII(vector<int>& stones) {
        // p-->positive , n--> negative
        // p + n = S
        // p - n = mi
        // 2P - S = mi
        // all possible positive sum
        int n = stones.size();
        set<int> ans;
        vector<vector<int>> dp(n + 1, vector<int>(3005, -1));
        allPositiveSum(n, stones, 0, ans, dp);
        cout << ans.size() << endl;
        vector<int> pos;
        int s = accumulate(stones.begin(), stones.end(), 0LL);
        for (auto i : ans) {
            pos.push_back(abs(2 * i - s));

        }

        return *min_element(pos.begin(), pos.end());
    }
};