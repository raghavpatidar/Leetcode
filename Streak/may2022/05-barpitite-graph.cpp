//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/is-graph-bipartite/
// Day : 377
class Solution {
public:
    int color[500], vis[500];
    bool dfs(int node, int c, vector<vector< int>>& graph) {
        vis[node] = 1, color[node] = c;
        for (auto i : graph[node]) {
            if (vis[i] == 0)if (!dfs(i, c xor 1, graph))return false;
            if (color[i] == color[node])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        for (int i = 0; i <= graph.size();i++)vis[i] = 0, color[i] = 0;
        for (int i = 0; i < graph.size(); i++)
            if (vis[i] == 0) {
                int temp = dfs(i, 0, graph);
                if (temp == 0)return false;
            }
        return true;
    }
};
