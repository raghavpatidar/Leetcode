//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/maximum-subsequence-score/submissions/956538177/
// Day : 382    

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int, int>> p;

        for (int i = 0; i < nums1.size(); i++)
        {
            p.push_back({ nums2[i] , nums1[i] });
        }

        sort(p.rbegin(), p.rend());

        long long ans = 0;
        long long sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k - 1; i++)
        {
            sum += p[i].second;
            pq.push(-p[i].second);
        }

        for (int i = k - 1; i < nums1.size(); i++)
        {

            sum += p[i].second;
            pq.push(-p[i].second);

            ans = max(ans, sum * p[i].first);

            sum += pq.top();
            pq.pop();
        }

        return ans;


    }
};