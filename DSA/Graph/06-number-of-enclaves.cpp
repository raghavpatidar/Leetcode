//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/number-of-enclaves/submissions/953710526/
// Day : 

class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)return;
        grid[x][y] = 0;
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
        dfs(x + 1, y, grid);
        dfs(x - 1, y, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i * j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1 and grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }
        int ans = 0;
        for (auto i : grid)for (auto j : i)ans += j;
        return ans;
    }
};