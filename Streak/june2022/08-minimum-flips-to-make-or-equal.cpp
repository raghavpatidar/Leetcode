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

Problem : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
Day :  396
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void decToBinary(int n, int binaryNum[])
    {
        int i = 0;
        while (n > 0) {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
    }

    int minFlips(int a, int b, int c) {
        int x[32] = { 0 };
        int y[32] = { 0 };
        int z[32] = { 0 };
        decToBinary(a, x);
        decToBinary(b, y);
        decToBinary(c, z);

        int i, j, k, s = 0, m = 0;
        for (i = 0;i < 32;i++) {
            int a_or_b = x[i] | y[i];
            if (a_or_b != z[i]) {
                if (a_or_b == 1 and z[i] == 0) {
                    if (x[i] == 1 and y[i] == 1)
                        s += 2;
                    else
                        s++;
                }
                else {
                    s++;
                }
            }
        }


        return s;

    }
};