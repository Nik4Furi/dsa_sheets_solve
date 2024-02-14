/*
Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

Example 1:

Input: 
        4        
       /  \       
      2   5      
     / \   /  \     
    7  1 2  3    
      /
     6
Output: 
13
Explanation:
        4        
       /  \       
      2   5      
     / \   /  \     
    7  1 2  3 
      /
     6
The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
*/

//find left path, right path, and sum of left path, or right path, and compare according to 3 conditions, tC O(n),sC O(h)

typedef pair<int,int> pt;
class Solution
{
    //--------- function to finding longest path sum
    pt longPathSum(Node* &root){ //first is leng,second is sum
        //base case
        if(!root) return {0,0};
        
        //is leaf
        if(!root->left && !root->right) return {1,root->data};
        
        //left call
        pt left = longPathSum(root->left);
        pt right = longPathSum(root->right);
        
        //find sum
        int lsum = root->data+left.second;
        int rsum = root->data + right.second;
        
        //Now compare with path
        if(left.first == right.first) return {left.first+1,max(lsum,rsum)};
        else if(left.first > right.first) return {left.first+1,lsum};
        else return {right.first+1,rsum};
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        return longPathSum(root).second; //sum
    }
};