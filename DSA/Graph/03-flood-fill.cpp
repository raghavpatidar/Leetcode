//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/flood-fill/
// Day : 

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int n = image.size();
         int m = image[0].size();
         int vis[55][55];
         queue<pair<int , int>> q;
         q.push({ sr , sc});
         int cx = image[sr][sc];
         image[sr][sc] = color;
         vis[sr][sc] = 1;
         int dx[4] = {1 , 0 , -1 , 0 };
         int dy[4] = {0  , -1 , 0 , 1};
         while(q.size()>0){
             int x = q.front().first;
             int y = q.front().second;
            //  cout<<x<<" "<<y<<" "<<image[x][y]<<endl;
             q.pop();
             for(int i = 0 ; i < 4 ; i++){
                 int nx = x + dx[i];
                 int ny = y + dy[i];
                 if(nx>=0 and ny>=0 and nx<n and ny<m and vis[nx][ny] == 0 and image[nx][ny] == cx ){
                     vis[nx][ny] = 1;
                     q.push({nx, ny});
                     image[nx][ny] = color;
                 }
             }
         }
         return image;
    }
};