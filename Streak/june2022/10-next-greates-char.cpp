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

Problem : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
Day : 398
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto i : letters) {
            if (i > target)return i;
        }
        return letters[0];
    }

};

//binary search solution
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int low = 0;
        int high = letters.size() - 1;

        if (letters[0] > target)
            return letters[0];

        else if (target >= letters[letters.size() - 1])
            return letters[0];

        char ans;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (letters[mid] > target) {
                ans = letters[mid];
                high = mid - 1;
            }

            else
                low = mid + 1;

        }

        return ans;

    }
};