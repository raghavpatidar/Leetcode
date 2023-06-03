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

Problem : https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
Day : 392
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int dfs(int manager, std::vector<int>& informTime, std::unordered_map<int, std::vector<int>>& adjList) {
        int maxTime = 0;
        if (adjList.find(manager) != adjList.end()) {
            for (int subordinate : adjList[manager]) {
                maxTime = std::max(maxTime, dfs(subordinate, informTime, adjList));
            }
        }
        return maxTime + informTime[manager];
    }

public:
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {
        std::unordered_map<int, std::vector<int>> adjList;
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }

        return dfs(headID, informTime, adjList);
    }
};