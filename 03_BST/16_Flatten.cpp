class Solution {
    
    TreeNode* prev = NULL;
public:

    void flatten(TreeNode* root) {
        //base case
        if(!root) return ;
        flatten(root->right);
        flatten(root->left);

        root->right =prev;
        root->left = NULL;
        prev = root;
    }
};