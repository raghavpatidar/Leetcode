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

Problem : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
Day :
*/

#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int maxi = arr[0];
        int prevDelete = 0;
        int prevNoDelete = arr[0];
        int ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            // if prev is deleted then we have two option take max of not delete or  add current value to prev delete 
            prevDelete = max(prevNoDelete, prevDelete + arr[i]);
            // if prev is not delete then we can take prev no delete otherwise take cureent because current is max
            prevNoDelete = max(prevNoDelete + arr[i], arr[i]);
            ans = max({ ans , prevDelete , prevNoDelete });
        }
        return ans;
    }
};