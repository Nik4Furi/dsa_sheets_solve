//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        
        //edge case
        // if(x[0] == ')' || x[0] == '}' || x[0] == ']') return false;
        
        stack<char> st;
        int i=0,n=x.size();
        
        while(i<n){
           char ch = x[i];
           
           if(ch == ']' || ch == ')' || ch == '}'){
               if(st.empty()) return false;
               
               char top = st.top();
               if(top == '[' && ch == ']') st.pop();
               else if(top == '{' && ch == '}') st.pop();
               else if(top == '(' && ch == ')') st.pop();
               else return false;
           }
           else st.push(ch);
           
           i++;
        }
        
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends