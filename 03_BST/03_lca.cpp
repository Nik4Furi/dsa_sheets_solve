class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            
            //base case
            if(!root) return root;
            
            if(root->data == n1 || root->data == n2) return root;
            
            Node* left = LCA(root->left,n1,n2);
            Node* right = LCA(root->right,n1,n2);
            
            if(left && right) return root;
            else if(left && !right) return left;
            else if(!left && right) return right;
            else return NULL;
        }

};
