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

Problem : https://leetcode.com/problems/detonate-the-maximum-bombs/submissions/
Day :391
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, vector<vector<int>>& al, bitset<100>& detonated) {
        if (!detonated[i]) {
            detonated[i] = true;
            for (int j : al[i])
                dfs(j, al, detonated);
        }
        return detonated.count();
    }
    int maximumDetonation(vector<vector<int>>& bs) {
        int res = 0, sz = bs.size();
        vector<vector<int>> al(bs.size());
        for (int i = 0; i < sz; ++i) {
            long long x = bs[i][0], y = bs[i][1], r2 = (long long)bs[i][2] * bs[i][2];
            for (int j = 0; j < bs.size(); ++j)
                if ((x - bs[j][0]) * (x - bs[j][0]) + (y - bs[j][1]) * (y - bs[j][1]) <= r2)
                    al[i].push_back(j);
        }
        for (int i = 0; i < sz && res < sz; ++i)
            res = max(dfs(i, al, bitset<100>() = {}), res);
        return res;
    }
    // int vis[105];
    // int ctr = 0;
    // bool isvalid(int x, int y , int r , int nx , int ny, int nr , int idx){
    //     if(vis[idx] == 1)return false;
    //     long long int x2 = abs(x - nx);
    //     long long int y2 = abs(y - ny);
    //     long long int r2 = (r + nr);
    //     x2 = x2*x2;
    //     y2 = y2*y2;
    //     r2 = r2*r2;
    //     cout<<x2<<" "<<y2 <<" "<<r2<<endl;
    //     return x2 + y2 <= r2;
    // }
    // void dfs(int idx , vector<vector<int>>&bombs){
    //     int x = bombs[idx][0];
    //     int y = bombs[idx][1];
    //     int r = bombs[idx][2];
    //     ctr++;
    //     vis[idx] = 1;
    //     for(int i = 0; i < bombs.size(); i++){
    //         int nx = bombs[i][0];
    //         if(i == idx)continue;
    //         int ny= bombs[i][1];
    //         int nr = bombs[i][2];
    //         if(isvalid(x , y , r , nx , ny , nr , i)){
    //             dfs(i , bombs);
    //         }
    //     }

    // }
    // int maximumDetonation(vector<vector<int>>& bombs) {
    //     int ans = 0;
    //     for(int i = 0; i < bombs.size();i++){
    //         if(vis[i] == 0){
    //             ctr = 0;
    //             dfs(i , bombs );
    //             ans = max(ans , ctr);
    //         }
    //     }
    //     return ans;
    // }
};