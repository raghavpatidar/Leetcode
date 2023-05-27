//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Day : 
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long maximumSumSubarray(int K, vector<int>& Arr, int N) {
        int start = 0;
        int i = 0;
        long sum = 0;
        //making window of size k 
        for (i = 0; i < K; i++) {
            sum += Arr[i];
        }
        long ans = sum;
        // moving window each time 
        while (i < N) {
            sum = sum - Arr[start++] + Arr[i++];
            ans = max(ans, sum);
        }
        return ans;
    }
};
