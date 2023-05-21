//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/number-of-islands/submissions/953726673/
// Day : 

class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')return;
        grid[x][y] = '0';
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
        dfs(x + 1, y, grid);
        dfs(x - 1, y, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        // vector<vector<int>>v(grid.size() , vector<int>(grid[0].size()));
        int ans = 0;
        for (int i = 0; i < grid.size();i++)
            for (int j = 0; j < grid[0].size();j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        return ans;
    }
};