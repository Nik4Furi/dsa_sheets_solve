/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
*/

//App-I: in each of substring tC O(n^2), check is plaindrom tC O(n), tc O(n.n^2)

//App-II: In each middle of ele, check both side equal, tC O(n^2)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        //base case
        if(S == "") return "";
        
        //edge case
        string temp = S;
        reverse(temp.begin(),temp.end());
        if(temp == S) return S;
        
        int n = S.size(),i=0,maxi=0;
        string ans = "";
        
        
        while(i<n){
            
            //odd length 
            int right=i,left=i;
            
            while(left >=0 && right <n && S[left] == S[right]){
                if(right-left+1 > maxi){
                    maxi = right-left+1;
                    // cout << "string "<< S.substr(left,right-left+1) << " ";
                    ans = S.substr(left,right-left+1);
                }
                left--,right++;
            }
            
            
            // even length
            right = i+1,left=i;
            
            while(left >=0 && right <n && S[left] == S[right]){
                 if(right-left+1 > maxi){
                    maxi = right-left+1;
                    // cout << "string "<< S.substr(left,right-left+1) << " ";
                    ans = S.substr(left,right-left+1);
                }
                left--,right++;
            }
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends