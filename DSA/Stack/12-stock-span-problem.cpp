//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/online-stock-span/
// Day : 
#include<bits/stdc++.h>
using namespace std;



class StockSpanner {
public:
    StockSpanner() {

    }
    stack<pair<int, int>>  st;
    int idx = 0;
    int next(int price) {
        while (st.size() > 0 and st.top().first <= price) {
            st.pop();
        }
        int ans = 0;
        if (st.size() == 0)ans = idx + 1;
        else ans = idx - st.top().second;

        st.push({ price , idx });
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */