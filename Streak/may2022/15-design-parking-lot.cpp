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

Problem : https://leetcode.com/problems/design-parking-system/submissions/959665817/
Day : 387
*/

#include<bits/stdc++.h>
using namespace std;


class ParkingSystem {
public:
    int b = 0, m = 0, s = 0;
    int x = 0, y = 0, z = 0;
    ParkingSystem(int big, int medium, int small) {
        b = big, m = medium, s = small;
    }

    bool addCar(int carType) {
        bool ok = false;
        if (carType == 1) {
            if (x < b) x++, ok = true;
        }
        else if (carType == 2) {
            if (y < m) y++, ok = true;
        }
        else {
            if (z < s) z++, ok = true;
        }
        return ok;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
