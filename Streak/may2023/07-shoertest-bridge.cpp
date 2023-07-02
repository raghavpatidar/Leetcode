//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob :  https://leetcode.com/problems/shortest-bridge/submissions/954486487/ 
// Day : 379

class Solution {
public:
    int vis[105][105];
    void printg(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    void dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 || vis[x][y] == 1)return;
        vis[x][y] = 1;
        grid[x][y] = 2;
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
        dfs(x + 1, y, grid);
        dfs(x - 1, y, grid);
    }
    int dx[5] = { -1 , 0 , 1 , 0 , -1 };
    int bfs(vector<vector<int>>& grid, int n) {
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({ 0 , {i , j } });
            }
        }
        while (q.size() > 0) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int d = q.front().first;
            q.pop();
            // grid[x][y] = 2;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dx[i + 1];
                if (nx >= 0 and ny >= 0 and nx < n and ny < n and grid[nx][ny] != 2) {
                    // cout<<grid[nx][ny]<<" "<<nx <<" "<<ny<<endl;
                    if (grid[nx][ny] == 1)return d;
                    else {
                        grid[nx][ny] = 2;
                        q.push({ d + 1 , {nx,ny} });
                    }
                }
            }
        }
        return INT_MAX;
    }
    pair<int, int> getoneidx(vector<vector<int>>& grid) {
        pair<int, int> p = { -1,-1 };
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return { i , j };
                }
            }
        }
        return p;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        //getting index of first island any position
        pair<int, int> p = getoneidx(grid);

        // change any  island value to 2
        dfs(p.first, p.second, grid);

        //bfs from all 2 with initial dist 0 and so increasing ....
        // start bfs with same index 
        int ans = bfs(grid, grid.size());
        return ans;
    }
};

// [1,1,1,1,1,1,1]
// [1,0,0,0,0,0,1]
// [1,0,2,2,0,0,1]
// [1,0,0,0,0,0,1]
// [1,1,1,1,1,1,1]



// 1 1 0 0 0 
// 1 0 3 2 2 
// 1 3 2 1 1 
// 3 2 1 2 2 
// 3 2 1 2 2 




// [0,1,0]
// [0,1,0]
// [0,2,2]
