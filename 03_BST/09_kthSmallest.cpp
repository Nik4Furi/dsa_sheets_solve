/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    //---------- function of inorder
    void inorder(TreeNode* &root,int k,priority_queue<int> &pq){
        //base case
        if(!root) return;

        inorder(root->left,k,pq);
        pq.push(root->val);
        if(pq.size() > k) pq.pop();

        inorder(root->right,k,pq);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq; //use max heap
        inorder(root,k,pq);

        return pq.top();
    }
};