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

Problem : https://leetcode.com/problems/flower-planting-with-no-adjacent/
Day : 2
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dfs(int node, vector<int> adj[], vector<int>& ans, vector<int>& vis) {
        // cout<<"node "<<node<<"\n";
        vis[node] = 1;
        int temp[5] = { 0 };
        for (auto i : adj[node]) {
            if (vis[i] == 0) {

                int col = dfs(i, adj, ans, vis);
                //    cout<<"child "<<i <<" "<<col<<endl;
                temp[col] = 1;
            }
            else {
                temp[ans[i]] = 1;
            }
        }


        for (int i = 1; i <= 4;i++) {
            if (temp[i] == 0) {
                ans[node] = i;
                break;
            }
        }

        // cout<<" col - "<<node<<"-->"<<ans[node]<<endl;

        return ans[node];


    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n + 1], vis(n + 1, 0), ans(n + 1, 0);
        for (auto i : paths) {
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n;i++) {
            if (vis[i] == 0) {
                dfs(i, adj, ans, vis);
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};



// 1----2
// |\  /|
// | \/ |
// | /\ |
// |/  \|
// 4----3