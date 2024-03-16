//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    //-----------function to check a tree is cbt
    bool isCBT(struct Node* tree,int ind,int n){
        //base case
        if(!tree) return true;
        
        if(ind >= n) return false;
        
        bool left = isCBT(tree->left,2*ind+1,n);
        bool right = isCBT(tree->right,2*ind+2,n);
        
        return (left&&right);
        
    }
    
    
    //--------function to check a tree follow max heap property
    bool isMaxHeap(struct Node* tree){
        //base case
        if(!tree || (!tree->left && !tree->right)) return true;
        
        if(!tree->right) return tree->data >= tree->left->data;
        
        bool left = isMaxHeap(tree->left);
        bool right = isMaxHeap(tree->right);
        
        if(left && right && tree->data >= tree->left->data && tree->data >= tree->right->data) return true;
        return false;
    }
    
    //-----------function to countNodes
    int countNodes(struct Node* tree){
        //base case
        if(!tree) return 0;
        
        if(!tree->left && !tree->right) return 1;
        
        return 1+countNodes(tree->left)+countNodes(tree->right);
    }
    
  public:
    bool isHeap(struct Node* tree) {
        // code here
        
        //base case
        if(!tree || (!tree->left && !tree->right)) return true;
        
        //is cbt
        int ind=0;
        int nodes = countNodes(tree);
        
        //call
        if(isCBT(tree,ind,nodes) && isMaxHeap(tree)) return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends