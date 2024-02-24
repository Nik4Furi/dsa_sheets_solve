//---------- function of coutn nodes
int cntNodes(struct Node* &root){
    //base case
    if(!root) return 0;
    return 1+cntNodes(root->left)+cntNodes(root->right);
}

//--------- function to finding the media
int a,b;
void solve(struct Node* &root,int& i,int n1,int n2){
    //base case
    if(!root) return;
    
    solve(root->left,i,n1,n2);
    i++;
    
    if(i == n1) a = root->data;
    if(i == n2) b = root->data;
    
    solve(root->right,i,n1,n2);
    
}
// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node *root)
{
      //Code here
      
      //do this in O(n) time and O(1) space
      
      //first coutn nodes
      int n = cntNodes(root);
      int i=0;
      
      //is even
      if(n&1) solve(root,i,n/2+1,n/2+1);
      else solve(root,i,n/2,n/2+1);
      
      return (a+b)/2.0;
}