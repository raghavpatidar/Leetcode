//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/01-matrix/
// Day : 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n  = mat.size();
        int m = mat[0].size();
        int vis[n][m] ;
        memset(vis , 0 , sizeof(vis));
        queue<pair< int, pair<int , int>>>q;
        for(int i = 0; i < n ; i++)for(int j = 0; j< m ; j++)if(mat[i][j] == 0 ) {
            vis[i][j] = 1;
            q.push({0 ,{i,j}});
        }
        int dx[5] = {-1 , 0 , 1, 0, -1};
        while(q.size() > 0 ){
            int x = q.front().second.first;
            int y = q.front().second.second;
            int d = q.front().first;
            q.pop();
            for(int i = 0; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dx[i+1];
                if(nx>=0 and ny >=0 and nx < n and ny < m and vis[nx][ny]==0){
                    vis[nx][ny] = 1;
                    mat[nx][ny] = d+1;
                    q.push({d+1 , {nx , ny}});
                }
            }
        }
        return mat;
    }
};