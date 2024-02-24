
    //----------- function to find inorder
    void inorder(Node* &root,vector<int> &v){
        //base case
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    //----------- function to merge two sorted arrays
    void mergeTwoArr(vector<int> v1,vector<int> v2,vector<int> &ans){
        //base case
        int i=0,n=v1.size();
        int j=0,m=v2.size();
        
        while(i<n && j<m){
            if(v1[i] <= v2[j]) ans.push_back(v1[i++]);
            else ans.push_back(v2[j++]);
        }
        
        while(i<n)
            ans.push_back(v1[i++]);
        
        while(j<m)
            ans.push_back(v2[j++]);
    }
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       
       /*
        Find inorder array, and merge two arrays
        
       */
       vector<int> v1,v2;
       inorder(root1,v1);
       
       inorder(root2,v2);
       
       //Now we merge two sorted arrays
       vector<int> ans;
       mergeTwoArr(v1,v2,ans);
       
       return ans;
       
    }