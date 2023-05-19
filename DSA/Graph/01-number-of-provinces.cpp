//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/number-of-provinces/description/


class Solution {
public:
    int vis[205];
    vector<int> adj[205];
    void dfs(int node){
        vis[node] = 1;
        for(auto i : adj[node]){
            if(vis[i] == 0 )dfs(i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
       for(int i = 0; i  <= n ; i++)
       {
           adj[i].clear();
           vis[i] = 0;
       }
       for(int i = 0; i < n ; i ++){
           for(int j = 0 ; j < n ;j++){
               if(i!=j and isConnected[i][j]==1)adj[i].push_back(j);
           }
       }
       int ans = 0; 
       for(int i = 0; i < n ; i++){
           if(vis[i]==0){
                ans++;
                dfs(i);
           }
       }
       return ans;

    }
};