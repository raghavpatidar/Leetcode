//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/top-k-frequent-elements/submissions/955262604/
// Day : 380

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto i : nums)m[i]++;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
        for (auto i : m) {
            q.push({ i.second , i.first });
            if (q.size() > k)q.pop();
        }
        vector<int> ans;
        while (q.size() > 0) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};