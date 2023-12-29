/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
*/

//I have differenct approach, now we are showing all here
class Solution {
    //----------- function to finding longest common subsequences
    int solve(string text1, string text2, int n, int m) {
        // base case
        if (n < 0 || m < 0)
            return 0;

        // if both are match
        if (text1[n] == text2[m])
            return 1 + solve(text1, text2, n - 1, m - 1);
        return 0 + max(solve(text1, text2, n - 1, m),
                       solve(text1, text2, n, m - 1));
    }

    //---------- function to finding the lcs using rec+memo
    int solveMemo(string text1, string text2, int n, int m,
                  vector<vector<int>>& dp) {
        // base case
        if (n < 0 || m < 0)
            return 0;

        // edge case
        if (dp[n][m] != -1)
            return dp[n][m];

        if (text1[n] == text2[m]) {
            dp[n][m] = 1 + solveMemo(text1, text2, n - 1, m - 1, dp);
            return dp[n][m];
        }
        dp[n][m] = 0 + max(solveMemo(text1, text2, n - 1, m, dp),
                           solveMemo(text1, text2, n, m - 1, dp));

        return dp[n][m];
    }

    //--------- functiong to finding lcs using dp with tabulation
    int solveTabu(string text1, string text2, int n, int m) {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    //--------------- function to finding lcs with space optimixation
    int solveSpac(string& text1, string& text2, int n, int m) {

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[m];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        // edge case
        if (text1 == text2)
            return n;

        // Finding lcs using recursion
        // return solve(text1,text2,n-1,m-1);

        /*
        //Now we try to find using dp
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return solveMemo(text1,text2,n-1,m-1,dp);
        */

        /*
        //try to finding lcs using dp with tabulation
        return solveTabu(text1,text2,n,m);

        */

        // Space optimization
        return solveSpac(text1, text2, n, m);
    }
};