/*
┌────────────────────────────────────────────────────────────────────────────────────────┐
│                      *-----------Raghav Patidar----------*                             |
|                   Fuck Ratings,Just Enjoy the Contest/Questions                        |
|                      I'm in Love with Experience and Learning.                         |
│                                                                                        |
|    Leetcode   : https://leetcode.com/manito7/                                          |
│    Github     : https://github.com/raghavpatidar                                       |
|    LinkedIn   : https://www.linkedin.com/in/raghavpatidar07/                           |
|    Resume     : https://drive.google.com/file/d/1nsTqWKSzxl-tcIXARi_b6vMSVcz57cVQ/view |
|    Codeforces : https://codeforces.com/profile/raghavpatidar                           |
|                                                                                        |
└────────────────────────────────────────────────────────────────────────────────────────┘

Problem : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
Day : 386
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[102][102] = {};
    int dfs(vector<int>& cuts, int i, int j) {
        if (j - i <= 1)
            return 0;
        if (!dp[i][j]) {
            dp[i][j] = INT_MAX;
            for (auto k = i + 1; k < j; ++k)
                dp[i][j] = min(dp[i][j],
                    cuts[j] - cuts[i] + dfs(cuts, i, k) + dfs(cuts, k, j));
        }
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));
        return dfs(cuts, 0, cuts.size() - 1);
    }
};