/*
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

Example 1:

Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
*/

//For more approaches can checkout the LCS part

//Here is more optimize approach

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    //--------------- Function to finding longest repeating subsequnce
    int solveSpac(string &str,string &temp,int n){
        
        vector<int> prev(n+1,0),curr(n+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(str[i-1] == temp[j-1] && i!=j)
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        
        return prev[n];
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    //edge cases
		    if(str == "") return 0;
		    
		    string temp = str;
		    int n = str.size();
		    
		    return solveSpac(str,temp,n);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends