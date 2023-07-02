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

Problem :https://leetcode.com/problems/design-underground-system/solutions/
Day : 389
*/

#include<bits/stdc++.h>
using namespace std;


class UndergroundSystem {
public:
    //startStation:endStation -> {totalTime, numberOfTrips}
    unordered_map<string, pair<long long, int>> stationTimes;
    //customerId -> startStation
    unordered_map<int, pair<string, int>> inTransit;
    UndergroundSystem() {
        stationTimes.clear();
        inTransit.clear();
    }

    void checkIn(int id, string stationName, int t) {
        if (inTransit.find(id) != inTransit.end()) return;
        inTransit[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) {
        auto& info = inTransit[id];
        string startStation = info.first;
        int startTime = info.second;
        string key = startStation + ":" + stationName;
        int time = t - startTime;

        if (stationTimes.find(key) != stationTimes.end()) {
            auto& oldTimes = stationTimes[key];
            oldTimes.first += time;
            oldTimes.second++;
        }
        else {
            stationTimes[key] = { time, 1 };
        }
        inTransit.erase(id);

    }

    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        auto& info = stationTimes[key];
        double avg = (double)info.first / (double)info.second;
        return avg;
    }
};