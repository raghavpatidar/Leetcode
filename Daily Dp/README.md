# Daily DP problem June 2023 .

# Table of Content


- [Daily DP problem June 2023 .](#daily-dp-problem-june-2023-)
- [Table of Content](#table-of-content)
- [Day 1](#day-1)
  - [940. Distinct Subsequences II](#940-distinct-subsequences-ii)
  - [Dice Throws](#dice-throws)
- [Day 2](#day-2)
  - [486. Predict the Winner / Optimal Game Streatgy](#486-predict-the-winner--optimal-game-streatgy)



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
[Code Link](./01-Distinct-subsequence.cpp)
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

## [Dice Throws](https://www.codingninjas.com/codestudio/problems/dice-throws_799924?leftPanelTab=0) 
<h4>
You are given D dice, each having F faces numbered 1 to F, both inclusive. The task is to find the possible number of ways to roll the dice together such that the sum of face-up numbers equal the given target S.
Return ans to modulo <code>1e9 + 7</code> .
</h4>
<code >Logic</code>

```text
1. Recursion    : Simple recursion with target sum approach our targeet is total sum and 
                  for each dice we have 1 to F option.
                  TC = O(2^N)  SC = O(N)

2. Memoization  : dp[i][j] -->number of ways  for ith dice have jth sum
                  Tc =O(N*N)   SC = O(N) + O(N*N)

3. Tabulation   : Remove Recursive Stack complexity
                  Tc =O(N*N)   SC = O(N*N)

4. Space Optimal: As we can see that we need only previous row dp[i-1] for our ith 
                  calculation so we can reomve our 2D dp and use prev  and curr 1D array
                  TC = O(N*N)  SC = O(2*N)
                      
```
[Code Link](./01-Dice-Throws.cpp)
<details><summary>code - Memoization</summary> 

```cpp
#include <bits/stdc++.h>

int solve(int idx  , int face , int target , vector<vector<int>>& dp , int mod ){
    
    if(idx == 0 and target == 0 )return 1;
    if(target == 0 || idx == 0 )return 0;
    if(dp[idx][target] != -1)return dp[idx][target];
    int cnt = 0;
    for(int j = 1 ; j<= face ; j++){
        if( target >= j ){
           cnt = ( cnt%mod +  solve(idx - 1 , face, target - j , dp, mod)%mod )%mod;
        }
    }
    return dp[idx][target] = cnt%mod;
}
int diceThrows(int d, int f, int s) {
    vector<vector<int>> dp(d +1 , vector<int>(s +1 , -1));
    int mod = 1e9+7;
    return solve(d , f , s  , dp , mod)%mod;
}
```
</details>
<details><summary>code - Tabulation</summary> 

```cpp
#include <bits/stdc++.h>
int diceThrows(int d, int f, int s) {
    vector<vector<int>> dp(d +1 , vector<int>(s +1 , -1));
    int mod = 1e9+7;
    for(int i = 0 ;i <= d ; i++)dp[i][0] = 0;
    for(int j = 0; j <= s ; j++ )dp[0][j] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++) {
      for (int j = 1; j <= s; j++) {
            int cnt = 0;
            for(int k = 1 ; k<= f ; k++){
                if( j >= k ){
                cnt = ( cnt%mod +  dp[i - 1][j - k] )%mod;
                }
            }
            dp[i][j] = cnt%mod;
      }
    }
    return dp[d][s]%mod;
}
```
</details>
<details><summary>code- Space Optimization</summary> 

```cpp
int diceThrows(int d, int f, int s) {
    int mod = 1e9+7;
    vector<int> prev(s+1 , 0) , curr(s+1 , 0);
    for(int j = 0; j <= s ; j++ )prev[j] = 0;
    prev[0] = 1;
    for (int i = 1; i <= d; i++) {
        curr[0] = 0;
      for (int j = 1; j <= s; j++) {
            int cnt = 0;
            for(int k = 1 ; k<= f ; k++){
                if( j >= k ){
                cnt = ( cnt%mod +  prev[j - k] )%mod;
                }
            }
          curr[j] = cnt%mod;
      }
      prev = curr;
    }
    return prev[s]%mod;   
}
```
</details>
<br>

# Day 2
## [486. Predict the Winner / Optimal Game Streatgy](https://leetcode.com/problems/predict-the-winner/description/) 
<h4>
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.
Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.
</h4>
<code >Logic</code>

```text
This is MiniMax Logic  we can max of min in our DP state Generally used in Game theory
(i,j) is the position from player 1 can pick
Case1:  pick from start (ith)
            then second player has two options 
                Condition1: he can pick from start which is i+1 so player 1 have left with (i+2,j) for next move
                Condition2 he can pick from end which is j-1 so plaayer 1 have open for first is (i+1,j-1) for next move
            now as both are playing optimally second player will choose max from 1 and 2 so first player have got min of both condition 
            such that startPick = min(Condition1 , Condition2) + arr[i] (as start value is picked)
Case2:  pick from end (jth)
            then second player has two options 
                Condition1: he can pick from start which is i+1 so player 1 have (i+2,j) for next move
                Condition2: he can pick from end which is j-1 so plaayer 1 have open for first is (i+1,j-1) for next move
            now as both are playing optimally second player will choose max from 1 and 2 so first player have got min of both condition 
            endPick = min(Condition1 , Condition2) + arr[j] (as end value is picked)

now our player 1 can choose max of both case such that CurrSum = Max(Case1 , Case2) == Max(startPick , endPick);
```
[Code Link](./02-Optimal-Gram-Streatgy.cpp)
<details><summary>code</summary>

```cpp

class Solution {
public:
    int solve(int i , int j , vector<int>& nums , vector<vector<int>>&dp){{
        if(i > j)return 0;
        if(i == j )return nums[i];

        if(dp[i][j] != -1)return dp[i][j];

        int startPick = nums[i] + min(solve(i+2 , j , nums, dp) ,solve( i+1,j-1,nums,dp));
        int endPick = nums[j] + min(solve(i , j-2 , nums ,dp) , solve(i+1 , j-1 , nums , dp));

        int currSum = max(startPick , endPick);
        return dp[i][j] = currSum;

    }}
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int totalSum = 0;
        for(auto i :nums)totalSum += i;
        int suma = solve(0 , n-1 , nums, dp );
        int sumb = totalSum - suma;
        cout<<suma<<" " <<sumb<<endl;
        return suma >= sumb;
    }
};
```
</details>
<br> 


<!-- # Day 
## []() 
<h4>
Statement
</h4>
<code >Logic</code>

```text
Logic
```
<details><summary>code</summary>

```cpp
Code
```
</details>
<br> 

-->
