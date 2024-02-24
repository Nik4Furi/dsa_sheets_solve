class Solution
{
    //------------ function of coutn pairs
    void solve(vector<int> v1,vector<int>& v2,int &ans,int x){
        // we knwo both arrays are sorted
        int n = v1.size(),m=v2.size();
        
        int i=n-1,j=0;
        
        while(i>=0 && j<m){
            int sum = v1[i]+v2[j];
            if(sum == x) ans++,i--,j++;
            else if(sum > x) i--;
            else j++;
        }
        
    }
    //--------- function of inorder
    void inorder(Node* &root,vector<int> &v){
        //base case
        if(!root) return;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        //--------- function of inorder
        vector<int> v1,v2;
        inorder(root1,v1);
        
        inorder(root2,v2);
        
        //function to count pairs
        int ans = 0;
        solve(v1,v2,ans,x);
        
        return ans;
    }
};