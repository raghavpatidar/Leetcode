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

Problem : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        //creating lps array
        int n = haystack.size();
        int m = needle.size();
        vector<int>lps(m);
        //calculating lps
        int prevLps = 0, i = 1;
        while (i < m) {
            //is equal add 1 and move forward
            if (needle[i] == needle[prevLps]) {
                lps[i] = prevLps + 1;
                i++;
                prevLps++;
            }
            else {
                if (prevLps == 0) {
                    // if first index move forrad base case
                    lps[i] = 0;
                    i++;
                }
                else {
                    //move backwords till not getting matching char
                    prevLps = lps[prevLps - 1];
                }
            }
        }

        //KMP algo
        i = 0;
        int j = 0;
        while (i < n) {
            //match
            if (needle[j] == haystack[i]) {
                i++, j++;
            }
            else {
                //not match
                if (j == 0) {
                    //base case if we are at first position and not
                    //not match move forward
                    i++;
                }
                else {
                    //move to last lps
                    j = lps[j - 1];
                }
            }

            //if we god our string match return
            if (j == m) {
                // return starting indx of i pointer which is i - m
                return i - m;
            }
        }


        return -1;

    }
};