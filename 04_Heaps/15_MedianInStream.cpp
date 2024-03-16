//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    vector<double> ans;
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    double median;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxi.size() && x >= maxi.top())
            mini.push(x);
        else maxi.push(x);
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int m= maxi.size(),n = mini.size();
        if(abs(m-n) > 1){
            
            if(m>n){
                mini.push(maxi.top());
                maxi.pop();
            }
            else{
                maxi.push(mini.top());
                mini.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        double ans = 0.0;
        int m = maxi.size(),n=mini.size();
        int total = m+n;
        
        if(total&1){
            if(m>n) ans += maxi.top();
            else ans+= mini.top();
        }
        else{
            if(m) ans+= maxi.top();
            if(n) ans+= mini.top();
            
            ans = ans/2.0;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends