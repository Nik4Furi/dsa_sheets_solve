/*

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    const int q = 65535;
    
    //--------function to match the patterns
    bool matchPat(int ind,string pat,string txt){
        int m = pat.size();
        int j=0;
        
        for(;j<m;j++){
            if(txt[ind+j] != pat[j]) return false;
        }
        return true;
    }
    
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            if(pat == txt) return {1};
            
            int n = txt.size(),m=pat.size();
            if(m > n) return {-1};
            
            long long hashTxt=0,hashPat=0;
            
            vector<int>ans;
            
            //first we hash our first m eles
            for(int i=0;i<m;i++){
                hashPat = (hashPat+pat[i])&q;
                hashTxt = (hashTxt+txt[i])&q;
            }
            
            //edge case
            if(hashPat == hashTxt){
                if(matchPat(0,pat,txt))
                    ans.push_back(1);
            }
            
            //Now we consider for next
            for(int i=1;i<=n-m;i++){
                hashTxt = (hashTxt-txt[i-1]+txt[i+m-1])&q;
                
                if(hashTxt == hashPat){
                    if(matchPat(i,pat,txt))
                        ans.push_back(i+1);
                }
            }
            
            if(ans.empty()) return {-1};
            
            return ans;
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends