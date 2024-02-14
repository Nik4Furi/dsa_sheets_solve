//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    
    //---------- function to finding the unique subsequences of the strings
    void solve(string &s,int n,int ind, set<string> &st,string output){
        //base case
        if(ind >=n){
            st.insert(output);
            // output = "";
        }
        
        //exclude
        solve(s,n,ind++,st,output);
        
        //include
        output.push_back(s[ind]);
        solve(s,n,ind++,st,output);
        
    }
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n  = s.size();
	    
	    if(s == "") return 0;
	    
	    
	    vector<string> ans;
	    set<string> st;
	    
	    string output = "";
	    
	    solve(s,n,0,st,output);
	    
	    return st.size();
	    
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends