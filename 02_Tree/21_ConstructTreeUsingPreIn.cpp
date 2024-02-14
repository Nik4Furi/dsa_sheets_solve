/*
Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5


*/

//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    //------------- Function to find the position of ele in inorder
    int FindPosIn(int in[],int ele,int n,int *&visited){
        
        for(int i=0;i<n;i++){
            
            if(in[i] == ele && visited[i] != 1){
                visited[i] =1 ;
                return i;
            }
        }
        return -1;
    }
    
    //---------------- function to build tree using the inorder and preorder
    Node* solve(int in[],int pre[],int n,int &ind,int inS,int inEnd,int* & visited){
        
        //base case
        if(ind >=n || inS > inEnd) return NULL;
        
        //Create the node
        int ele = pre[ind++];
        Node* root = new Node(ele);
        
        //Now we finding the ind of the ele in inorder
        int pos = FindPosIn(in,ele,n,visited);
        
        if(pos == -1) return NULL;
        
        root->left = solve(in,pre,n,ind,inS,pos-1,visited);
        root->right = solve(in,pre,n,ind,pos+1,inEnd,visited);
        
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        
        //base case
        if(n == 0) return NULL;
        
        else if(n ==1) {
            Node* root = new Node(pre[0]);
            return root;
        }
        
        //o/w we build the tree
        int* visited = new int[n];
        
        for(int i=0;i<n;i++)
            visited[i] = 0;
        
        int ind = 0;
        return solve(in,pre,n,ind,0,n,visited); //two arr,n,ind,inSt,inEnd
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends