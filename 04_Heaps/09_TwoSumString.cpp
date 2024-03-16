//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        
        //base case
        if(n == 1) return to_string(arr[0]);
        
        sort(arr,arr+n);
        
        string s1="",s2="";
        
        for(int i=0;i<n;i++){
            if(i&1) s2+= to_string(arr[i]);
            else s1+=to_string(arr[i]);
        }

cout <<s1 << " "<<s2 <<endl;

      long int n1 = stol(s1);
      long int n2 = stol(s2);
        
        cout << n1 << " "<<n2;
        
        long int sum = n1+n2;
        
        return to_string(sum);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends