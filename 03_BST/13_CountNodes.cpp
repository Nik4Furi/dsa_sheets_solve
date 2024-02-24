void inorder(Node* &root,int l,int h,int &ans){
        //base case
        if(!root) return;
        
        //caond
        if(root->data >= l&& root->data <= h) ans ++;
        
        //left call
        inorder(root->left,l,h,ans);
        
        //right call
        inorder(root->right,l,h,ans);
    }
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      int ans = 0;
      
      /*
        Approach: run inorder, and in a root, find left side count nodes
      */
      
      inorder(root,l,h,ans);
      
      return ans;
    }