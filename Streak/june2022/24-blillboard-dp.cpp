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

Problem : 412
Day :
*/

#include<bits/stdc++.h>
using namespace std;



// think of putting -1 , 0 , 1 in from for each element
// and wee need just sum of all element with 1 in from
// res we can ignore 
// base case if we are end then our total sum of all signs must be 0 otherwise return -inf

class Solution {
public:

    map <pair<int, int>, int> mp;
    int solve(int idx, int curr, vector<int>& rods, map <pair<int, int>, int>& mp) {
        if (idx == 0)return curr == 0 ? 0 : -1e9;
        if (mp.find({ idx , curr }) != mp.end())return mp[{idx, curr}];
        int ans = -1e9;
        for (int i = -1;i <= 1; i++) {
            int x = rods[idx - 1] * i;
            int y = i == 1 ? 1 : 0;
            ans = max(ans, rods[idx - 1] * y + solve(idx - 1, curr + x, rods, mp));
        }
        return mp[{idx, curr}] = ans;

    }
    int tallestBillboard(vector<int>& rods) {
        map <pair<int, int>, int> mp;
        return solve(rods.size(), 0, rods, mp);
    }
};


// [-1 , 0 , 1]-->











