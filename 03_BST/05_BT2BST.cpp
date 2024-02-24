class Solution{
    //--------- function to traverse root
    void inorder(Node* &root,vector<int> &nodes){
        //base case
        if(!root) return;
        inorder(root->left,nodes);
        nodes.push_back(root->data);
        
        inorder(root->right,nodes);
    }
    
    //------ function to insert node in root
    Node* insertNode(Node* &root,int d){
        //base case
        if(!root){
            root = new Node(d);
            return root;
        }
        
        if(d > root->data){
            root->right = insertNode( root->right,d);
            return root;
        }
        else {
            root->left = insertNode(root->left,d);
            return root;
        }
    }
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        
        //first insert all eles of root node into list
        vector<int> nodes;
        
        inorder(root,nodes);
        
        //now sort it
        sort(nodes.begin(),nodes.end());
        
        //Now traverse it from start and construct the tree
        int ind = 0,siz=nodes.size();
        Node* ans = NULL;
        
        while(ind < siz){
            ans = insertNode( ans,nodes[ind]);
            ind++;
        }
        return ans;
        
    }
};