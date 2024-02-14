/*
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

                                               

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.

*/

//Finding the sum from left and right, and sum with them, also consider the maxsum also which is root or left and right
// tC O(n), sC O(n)


class Solution{
    pair<int,int> maxSumSolve(Node* &root){
        //base case
        if(!root) return {0,0};
        
        pair<int,int> left = maxSumSolve(root->left);
        pair<int,int> right = maxSumSolve(root->right);
        pair<int,int> ans;
        
        //finding sum
        ans.first = left.second+right.second+root->data;
        ans.second = max(left.first,left.second)+max(right.first,right.second);
        
        return ans;
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        
        if(!root) return 0;
        
        auto sum = maxSumSolve(root);
        return max(sum.first,sum.second);
    }
};