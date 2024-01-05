/**/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    //--------------function to edit the distance
    int solve(string &s, int i, string &t, int j)
    {
        // base case
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        // cout << "Iterated string --> "<< s << " " << t << endl;

        // Edge case
        if (s[i] == t[j])
            return solve(s, i - 1, t, j - 1);

        // insert
        int ins = 1 + solve(s, i, t, j - 1);
        int rem = 1 + solve(s, i - 1, t, j);
        int replace = 1 + solve(s, i - 1, t, j - 1);

        return min({ins, rem, replace});
    }

    //-------------function to finding edit distance
    int solveMemo(string &s, int i, string &t, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i < 0)
            return j + 1;
        else if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = solveMemo(s, i - 1, t, j - 1, dp);

        int ins = 1 + solveMemo(s, i, t, j - 1, dp);
        int rem = 1 + solveMemo(s, i - 1, t, j, dp);
        int rep = 1 + solveMemo(s, i - 1, t, j - 1, dp);

        return dp[i][j] = min({ins, rem, rep});
    }

public:
    int editDistance(string &s, string &t)
    {
        // Code here

        // Edge case
        if (s == t)
            return 0;

        int n = s.size(), m = t.size();

        // using recursion
        //  return solve(s, n - 1, t, m - 1);

        /*
        //using dp memo
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solveMemo(s,n-1,t,m-1,dp);
        */
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends