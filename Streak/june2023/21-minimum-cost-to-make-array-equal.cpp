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

Problem : https://leetcode.com/problems/minimum-cost-to-make-array-equal/submissions/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long ans = 1e18;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < nums.size(); i++)
            v[i] = { nums[i], cost[i] };

        sort(v.begin(), v.end());
        vector<long long> pref(n), suff(n);
        long long c_sum = 0, nc = 0;
        for (int i = 0; i < n; i++) {
            pref[i] = (v[i].first * c_sum - nc);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        c_sum = 0, nc = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = min(ans, abs(v[i].first * c_sum - nc) + pref[i]);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        return ans;

    }
};
