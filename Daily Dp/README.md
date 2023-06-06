

# Day 1
## [940. Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/description/) 
<h4> Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo <code>109 + 7</code> .
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. i.e., <code>"ace</code>" is a subsequence of <code>"abcde</code>" while <code>"aec</code>" is not.
</h4>
<code >Logic</code>

```text
1. dp[i]  shows that total number of sequece till ith index but if we found repeating character then we have to remove it's all previous subsequence 
2. let say repeateIdx is  index where last time char i occur so we can remove it's all occurance before this such that dp[i] = dp[i]  - dp[repeateIdx - 1];
      Case 1 : if we found element which we don't found before
               simply add it's all subsequence to dp[i] = 2 * d[i-1];
      Case2 : found and repeated index 
             1 add all new sequence such that dp[i] = 2* dp[i-1];
             2 remove repeated subsequence count  dp[i] -= dp[repeatedIdx -1];

3. finally dp.back() will have our total distinxt subsequence 
```
<details><summary>code</summary>

```cpp
class Solution {
public:
    int distinctSubseqII(string s) {
        map<char, int> m ;
        vector<int>dp(s.size()+1);
        dp[0] = 1;
        int mod = 1e9 + 7;
        for(int i = 1; i <=s.size();i++){
            dp[i] = (2 * dp[i-1])%mod;
            if(m.find(s[i-1]) != m.end()){
                int repeateidx = m[s[i-1]]-1;
                dp[i] = (dp[i] - dp[repeateidx]);
                dp[i] %=mod;
            }
            m[s[i-1]] = i;
        }
        int n = s.size();
        dp[n]--;
        if(dp[n] < 0 )dp[n]+= mod;
        return dp[n] ;
    }
};
```
</details>

<br>
