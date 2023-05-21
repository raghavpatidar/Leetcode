//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/word-ladder/
// Day : 

class Solution {
public:
    int ladderLength(string st, string end, vector<string>& v) {
        int ans = 0;
        map<string, int> m;
        for (auto i : v)m[i] = 1;
        queue<pair<string, int>> q;
        q.push({ st , 1 });
        while (q.size() > 0) {
            string  curr = q.front().first;
            int d = q.front().second;
            q.pop();

            for (int i = 0; i < curr.size(); i++) {
                string temp = curr;
                for (char c = 'a'; c <= 'z';c++) {
                    temp[i] = c;
                    if (m.count(temp) and temp == end) {
                        return d + 1;
                    }
                    if (m.count(temp) and m[temp] == 1) {
                        q.push({ temp , d + 1 });
                        m[temp] = 2;
                    }
                }
            }
        }
        return 0;


    }
};