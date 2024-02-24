//--------- function to create the bst
Node* insertNode(Node* &root, int d){
    //base case 
    if(!root){
        root = new Node(d);
        return root;
    }
    //already have ele
    if(d > root->data){
        root->right = insertNode(root->right,d);
        return root;
    }
    else {
        root->left = insertNode(root->left,d);
        return root;
    }
    
}

Node *constructTree (int post[], int size)
{
//code here
    int ind = size-1;
    Node* root = NULL;
    
    while(ind >= 0){
       root = insertNode(root,post[ind]);
        ind--;
    }
    return root;
}