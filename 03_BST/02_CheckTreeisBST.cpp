class Solution{
//-------- function to check a tree is bst
    bool solve(Node* &root,int mini,int maxi){
        //base case
        if(!root) return true;
        
        if(root->data >= maxi || root->data <= mini) return false;
    
        return (solve(root->left,mini,root->data) && solve(root->right,root->data,maxi));
    }
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        //base case
        if(!root || (!root->left && !root->right)) return true;
        
        return solve(root,INT_MIN,INT_MAX);
    }
};