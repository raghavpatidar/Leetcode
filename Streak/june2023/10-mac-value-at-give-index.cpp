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

Problem : https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
Day : 399
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    // int check
    ll sum(ll n) {
        //return sum from 0 to n;
        return (n * (n + 1)) / 2;
    }
    ll check(ll x, ll idx, ll maxSum, ll n) {
        // left, right  limit till our x-1,x-2  goes 
        // 1 2  [3 4 5 6 5 4 ] 3 2 1 , maximise 0 index as for left we need to find Sum(6) - Sum(2) so 2 is our left limit
        // and Sum(6) - Sum(3) so 3 is right limit
        // when mid is 5 and idx is n-1 --> [0 0 0 1 2 3 4 5]
        // but we can't add 0 need positive so justs count zero in left range
        // and Similary zero in right range and that total 1 we need to add to our current total array sum 
        ll l = x - idx - 1;
        ll r = x - n + idx;
        ll cntZero = 0;
        if (l < 0)cntZero += abs(l), l = 0;
        if (r < 0)cntZero += abs(r), r = 0;
        ll sumx = sum(x);
        ll suml = sum(l);
        ll sumr = sum(r);
        ll total = (sumx - suml) + (sumx - sumr) - x + cntZero; // count X two time so removing 1 time
        return maxSum >= total;
    }
    int maxValue(int n, int index, int maxSum) {
        ll l = 1, r = maxSum;
        ll ans = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, index, maxSum, n)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};