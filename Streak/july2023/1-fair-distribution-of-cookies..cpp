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

Problem : https://leetcode.com/problems/fair-distribution-of-cookies/s
Day :  421
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = INT_MAX;
    void solve(int start, vector<int>& nums, vector<int>& v, int k) {
        if (start == nums.size()) {
            int maxm = INT_MIN;
            for (int i = 0;i < k;i++) {
                maxm = max(maxm, v[i]);
            }
            ans = min(ans, maxm);
            return;
        }
        for (int i = 0;i < k;i++) {
            v[i] += nums[start];
            solve(start + 1, nums, v, k);
            v[i] -= nums[start];
        }
    }

    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k, 0); // v is to store each sum of the k subsets
        solve(0, nums, v, k);
        return ans;
    }
};