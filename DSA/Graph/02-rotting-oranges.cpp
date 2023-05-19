//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int vis[12][12];
    bool isvalid(int x , int y , vector<vector<int>>&grid){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())return false;
        if(grid[x][y]== 0 || grid[x][y] == 2 || vis[x][y] == 1)return false;
        return true;
    }
    bool isvalid2(int x , int y , vector<vector<int>>&grid){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())return false;
        if(grid[x][y]== 0 || grid[x][y] == 1)return false;
        return true;
    }
    int dx[4] = {1 , 0 , -1  , 0 };
    int dy[4] = {0 , -1 , 0 , 1};
    int bfs(int x , int y , vector<vector<int>>&grid){
        queue<pair<int , pair<int, int>>> q;
        int ans = 0;
        q.push({0 , {x, y}});
        vis[x][y] = 1;
        while(q.size() > 0 ){
            int d = q.front().first;
            int a= q.front().second.first;
            int b = q.front().second.second;
            q.pop();
            for(int i = 0; i  <  4 ;i++){
                int xnew = a + dx[i];
                int ynew = b + dy[i];
                if(isvalid2(xnew , ynew , grid)){
                    ans = d + 1;
                    return ans;
                }
                if(isvalid(xnew , ynew , grid)){
                    vis[xnew][ynew] = 1;
                    q.push({d+1 , {xnew , ynew}});
                }
            }
        }
        return -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
       for(int i = 0; i < grid.size() ; i++){
           for(int j = 0; j < grid[0].size();j++){
               memset(vis , 0 , sizeof(vis)); 
               if(isvalid(i , j , grid)){
                  int x =    bfs(i , j , grid);
                //   cout<<i<<" "<< j<<" "<< x<< endl;
                  if(x == -1){
                      return -1;
                  }
                  ans = max(ans , x);


               }
           }
       }
       return ans;
    }
};