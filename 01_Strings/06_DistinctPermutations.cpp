/*
Win from a cash prize pool of INR 15,000
Check out Hack-For-Health Hackathon Now!

banner
Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/

//App-I: use map to check its consider or not, tC O(n!*n), SC O(n), use map

//App-II; insetead of using map, swaping the indexes else, tC O(n!*n), SC O(1), if our ans is not consider as space
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    //------------Function to finding all distinct permutations
    void solve(string &s,int n,int ind,unordered_set<string> &st){
        //base case
        if(ind >=n){
            st.insert(s);
            return;
        }
        
        for(int j=ind;j<n;j++){
            swap(s[ind],s[j]);
            
            solve(s,n,ind+1,st);
            
            swap(s[ind],s[j]);
        }
    }
    
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    
		    int n = S.size();
		    
		    unordered_set<string> st;
		    
		    solve(S,n,0,st);
		    
		    vector<string> ans(st.begin(),st.end());
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends