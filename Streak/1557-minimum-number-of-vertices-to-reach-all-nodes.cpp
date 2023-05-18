//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
// Day : 376


class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> deg(n , 0 );
        for(auto i: edges)deg[i[1]]++;
        vector<int>ans;
        for(int i = 0; i < n ;i++)if(deg[i] == 0 )ans.push_back(i);
        return ans;
    }
};