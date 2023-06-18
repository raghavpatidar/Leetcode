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

Problem : https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


static int MOD = 1e9 + 7;
static vector<int> dirs = { 0,1,0,-1,0 };
class Solution {
public:
    vector<vector<long>> memo;
    long dp(vector<vector<int>>& grid, int i, int j) {
        long result = 1;
        if (memo[i][j] != -1)
            return memo[i][j];
        for (int d = 0;d < 4;d++) {
            int x = i + dirs[d], y = j + dirs[d + 1];
            if (x >= 0 && y >= 0 && x < grid.size() && y<grid[0].size() && grid[x][y]>grid[i][j])
                result = (result + dp(grid, x, y)) % MOD;
        }
        return memo[i][j] = result;
    }
    int countPaths(vector<vector<int>>& grid) {
        long result = 0;
        memo.resize(grid.size(), vector<long>(grid[0].size(), -1));
        for (int i = 0;i < grid.size();i++)
            for (int j = 0;j < grid[0].size();j++)
                result = (result + dp(grid, i, j)) % MOD;
        return result;
    }
};