//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/find-eventual-safe-states/description/
// Day : 

class Solution {
public:
    vector<int> topo(int n, vector<int> adj[], vector<int> in) {
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0)q.push(i);
        }
        while (q.size() > 0) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (int i : adj[curr]) {
                in[i]--;
                if (in[i] == 0) q.push(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        vector<int> in(graph.size());
        for (int i = 0; i < graph.size();i++)for (auto j : graph[i]) {
            in[i]++;
            adj[j].push_back(i);
        }

        return topo(graph.size(), adj, in);
    }
};