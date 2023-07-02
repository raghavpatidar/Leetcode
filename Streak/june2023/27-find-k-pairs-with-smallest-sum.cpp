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

Problem : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        pq.push({ nums1[0] + nums2[0] , {0,0} });
        // for(int i=0; i<nums1.size() && i<k; i++) pq.push( {nums1[i] + nums2[0] , {i, 0 } });
        vector<vector<int>>ans;
        while (pq.size() > 0 and k > 0) {
            k--;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            // temp = ;
            ans.push_back({ nums1[x] , nums2[y] });
            // this will take care of rest 
            if (x + 1 < nums1.size()) {
                int sum = nums1[x + 1] + nums2[y];
                pq.push({ sum  ,{x + 1 , y} });
            }
            //x == 0 because we are making first idx of nums1 to match to all idx in nums2
            if (x == 0 and y + 1 < nums2.size()) {
                int sum = nums1[x] + nums2[y + 1];
                pq.push({ sum , {x , y + 1} });
            }
        }
        return ans;
    }
};
