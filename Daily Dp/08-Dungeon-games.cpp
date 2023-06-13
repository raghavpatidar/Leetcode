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

Problem : https://leetcode.com/problems/dungeon-game/submissions/969903884/
Day : 8
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int  i, int  j, int n, int m, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {

        //Base Case
        if (i == n || j == m)return 1e9;
        if (i == n - 1 and j == m - 1) {
            return dungeon[i][j] < 0 ? 1 - dungeon[i][j] : 1;
        }

        if (dp[i][j] != -1)return dp[i][j];

        int left = solve(i, j + 1, n, m, dungeon, dp);
        int right = solve(i + 1, j, n, m, dungeon, dp);

        int minHealth = min(left, right) - dungeon[i][j];

        return dp[i][j] = minHealth <= 0 ? 1 : minHealth;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 and j == m - 1) dp[i][j] = dungeon[i][j] < 0 ? 1 - dungeon[i][j] : 1;
                else {
                    int left = dp[i][j + 1];
                    int right = dp[i + 1][j];
                    int minHealth = min(left, right) - dungeon[i][j];
                    dp[i][j] = minHealth <= 0 ? 1 : minHealth;
                }
            }
        }
        // return solve(0 ,0 , n , m , duongeon , dp);
        return dp[0][0];
    }
};