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

Problem : https://careers.snowflake.com/us/en/job/6348286002/Software-Engineer-Intern-Berlin-2024
Day :409
*/

#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

auto _ = []() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}();



class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (n < 2 * k + 1) {
            return ans;
        }
        int mid = k, start = 0, end = 2 * k;

        long long int currSum = 0;
        for (int i = start; i < end;i++) {
            currSum = currSum + nums[i];
        }
        int d = 2 * k + 1;
        while (end < n) {
            currSum += nums[end];
            ans[mid] = currSum / d;
            currSum -= nums[start];
            mid++, start++, end++;
        }
        return ans;

    }
};