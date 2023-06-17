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

Problem : https://leetcode.com/problems/course-schedule-iv/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


// another optimal approach is to use topological sort
// find ordered for topo sort
// for each node in order we can add it's child: adj[curr] pair to our matrix such that matrix[curr][child] = 1;
//and we need to do this for all nodes such that for each node Time-> O(V*E) Space O(V^2)


class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        // we can think of all pair shortest path
        //  all element exact digonal is inf then add all u->v dist 1
        // using flyod warshall algo
        vector<vector<int>> isReachable(numCourses, vector<int>(numCourses, 1e9));
        for (int i = 0; i < numCourses; i++)isReachable[i][i] = 0;
        for (auto i : prerequisites) {
            int u = i[0], v = i[1];
            isReachable[u][v] = 1;
        }
        //via path k
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses;j++) {
                    if (isReachable[i][j] > isReachable[i][k] + isReachable[k][j] and isReachable[k][j] != 1e9 and isReachable[i][k] != -1e9) {
                        isReachable[i][j] = isReachable[i][k] + isReachable[k][j];
                    }
                }
            }
        }
        vector<bool> ans(queries.size());
        int k = 0;
        for (auto i : queries) {
            int u = i[0], v = i[1];
            if (isReachable[u][v] != 1e9) {
                ans[k] = true;
            }
            else {
                ans[k] = false;
            }
            k++;
        }
        return ans;
    }
};





