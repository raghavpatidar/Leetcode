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

Problem : https://leetcode.com/problems/redundant-connection/
Day : 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // {u,v} --> {idx , visited};
        map<  pair<int, int>, pair<int, int> > m;
        int n = edges.size();
        vector<int> adj[n + 1];
        vector<int> in(n + 1, 0);
        int k = 1;

        for (auto i : edges) {
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            m[{u, v}] = { k , 0 };
            m[{v, u}] = { k , 0 };
            in[u]++, in[v]++;
            k++;
        }


        queue<pair<int, int>> q;
        for (int i = 1; i <= n;i++) {
            if (in[i] == 1) {
                q.push({ i , -1 });
                in[i]--;
            }
        }

        // int parent = 
        while (q.size() > 0) {
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            // cout<<curr<<" "<< par<<endl;
            if (par != -1) {
                m[{curr, par}].second = 1;
                m[{par, curr}].second = 1;
            }

            for (auto i : adj[curr]) {
                m[{curr, i}].second = 1;
                m[{i, curr}].second = 1;
                in[i]--;
                //    cout<<in[6]<<" 6 "<<endl;
                if (in[i] == 1) {
                    q.push({ i , curr });
                }
            }
        }

        pair<int, int> p;
        int idx = 0;

        for (auto [i, j] : m) {
            if (j.second == 0) {
                // cout<<i.first<<","<< i.second<<" -- > "<<j.first<<" "<<j.second<<endl;
                if (idx < j.first) {
                    idx = j.first;
                    p = { i.first , i.second };
                }
            }
        }

        pair<int, int> p2;
        p2.first = p.second;
        p2.second = p.first;


        for (auto i : edges) {
            int u = i[0], v = i[1];
            if (p2.first == u and p2.second == v) {
                swap(p, p2);
            }
        }

        return { p.first , p.second };

    }
};

