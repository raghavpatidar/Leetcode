//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/course-schedule/
// Day : 

class Solution {
public:
    bool topo(int n, vector<vector<int>>& pre) {
        queue<int> q;
        vector<int> in(n);
        vector<int> adj[n];
        vector<int> ans;
        for (auto i : pre) {
            adj[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
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
        if (ans.size() == n) {

            return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return topo(numCourses, prerequisites);
    }
};