 //---------- inorder
    void inorder(Node* &root,vector<int> &nodes){
        //base case
        if(!root) return;
        
        inorder(root->left,nodes);
        nodes.push_back(root->data);
        inorder(root->right,nodes);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> nodes;
        inorder(root,nodes);
        
        sort(nodes.begin(),nodes.end(),greater<int>()); //decreasing order
        
        return nodes[K-1];
    }