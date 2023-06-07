# Daily DP problem June 2023 .

# Table of Content


- [Daily DP problem June 2023 .](#daily-dp-problem-june-2023-)
- [Table of Content](#table-of-content)
- [Day 1](#day-1)
  - [940. Distinct Subsequences II](#940-distinct-subsequences-ii)
  - [Dice Throws](#dice-throws)
- [Day 2](#day-2)
  - [486. Predict the Winner / Optimal Game Streatgy](#486-predict-the-winner--optimal-game-streatgy)
  - [221. Maximal Square](#221-maximal-square)



# Day 1
## [940. Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/description/) 
> Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo <code>109 + 7</code>. A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. i.e., <code>"ace</code>" is a subsequence of <code>"abcde</code>" while <code>"aec</code>" is not.

<code >Logic</code>




 ```qoute
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
>You are given D dice, each having F faces numbered 1 to F, both inclusive. The task is to find the possible number of ways to roll the dice together such that the sum of face-up numbers equal the given target S. Return ans to modulo <code>1e9 + 7</code> .

<code >Logic</code>

```quote
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
>You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array. Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

<code >Logic</code>

```quote
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



## [221. Maximal Square](https://leetcode.com/problems/maximal-square/description/) 

> Given an m x n binary matrix filled with 0's and 1's, find the largest <code>square</code>  containing only 1's and return its area.

<code >Logic</code>

```quote
Approach 1 : dp[i][j] --> max length of square at i,j and stores it length
        case 1: i ==0 then we are at first row so max length is one if matrix[0][j] = 1 i.e dp[0][j]= matrix[0][j]
        case 2: j ==0 then we are at first col so max length is one if matrix[i][0] = 1 i.e dp[i][j]= matrix[i][0]
        case 3: matrix[i][j] = 0  means current index we don't have any square i.e dp[i][j] = 0
        case 4: matrix[i][j] = 1  measn we can have square of and it's max len is Min( dp[i-1][j-1] , dp[i-1][j-1] , dp[i][j-1]) +1
                such that it's min of it's uper square , previous back square od digonal left up
        we can take max of all dp[i][j] and return it's area as square of side*side

Approach 2 : Think of  Aream of Histrogram we can think each layers as histroger of top of it
             dp[i][j] histogram at ith row and jth value 
             dp[i] each row 
             if matrix[i][j] = 1  then dp[i][j]= dp[i-1][j]
             else dp[i][j] = 0
             ans = max(ans , AreaHitogram(dp[i]));
```
[Code Link](./02-Maximal-Square.cpp)
<details><summary>Approach 1 code</summary>

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size() , ans = 0;
        vector<vector<int>> dp(n , vector<int>(m, 0));
        for(int i= 0; i < n ; i++){
            for(int j= 0; j < m ; j++){
                if(i == 0 || j ==0 || matrix[i][j] =='0') dp[i][j] = matrix[i][j] -'0';
                else {
                   dp[i][j] = min({dp[i-1][j-1] , dp[i][j-1] , dp[i-1][j]})+1;
                }
                ans = max(ans , dp[i][j]);
            }
        }
        return ans*ans;

    }
};
```
</details>
<details><summary>Approach 2 code</summary>

```cpp
class Solution {
public:
    vector<int> nsl(vector<int>v){
        stack<int>st;
        vector<int> ans;
        for(int i = 0; i < v.size() ; i++){
            if(st.size()>0){
                while(st.size()>0 and v[st.top()] >= v[i])st.pop();
                if(st.size() == 0)ans.push_back(-1);
                else ans.push_back(st.top());
            }else{
                ans.push_back(-1);
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nsr(vector<int>v){
        stack<int>st;
        vector<int> ans;
        int n = v.size();
        for(int i = v.size()-1; i >= 0 ; i--){
            if(st.size()>0){
                while(st.size()>0 and v[st.top()] >= v[i])st.pop();
                if(st.size() == 0)ans.push_back(n);
                else ans.push_back(st.top());
            }else{
                ans.push_back(n);
            }
            st.push(i);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }

    int maxHistogram(vector<int> v){
        vector<int>left = nsl(v);
        vector<int>right = nsr(v);
        int ans = 0;
        for(int i = 0; i < v.size() ; i++){
            int w = (right[i] - left[i] - 1 );
            int h =v[i];
            int area = min(h , w) * min(h , w);
            ans = max(ans , area);
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n , vector<int>(m , 0));
        for(int j = 0; j < m ; j++)dp[0][j] = matrix[0][j] - '0';
        int ans = maxHistogram(dp[0]);
        for(int i = 1; i < n ; i++){
            for(int j = 0; j < m ;j++){
                if(matrix[i][j] == '0' )dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] +1;
            }
            ans = max(ans ,maxHistogram(dp[i]));
        }
        return ans;
    }
};
```
</details>
<br> 


<!-- # Day 
## []() 

> Statement

<code >Logic</code>

```quote
Logic
```
[Code Link]()
<details><summary>code</summary>

```cpp
Code
```
</details>
<br> 

-->
