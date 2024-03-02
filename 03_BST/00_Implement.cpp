#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Creating the class to implement the bst
//properties
// is first of all x'lefts <= x < x'rights
// follow minimums at left leaf, and maxies at right

class BST {
    public:
    int data;
    BST *left;
    BST * right;

    //consturctor
    BST(int d){
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

//-------function to insert ele
BST* insertInBst(BST*& root,int data){
    //base case
    if(!root){
        root = new BST(data);
        return root;
    }

    //already have ele
    //insert at right
    if(data > root->data){
        root->right = insertInBst(root->right,data);
    }
    else root->left = insertInBst(root->left,data);
    return root;

}

//Now inserting eleements in bst
void buildBST(BST*& root){
    int data;
    cin >> data;

    while(data != -1){
       root= insertInBst(root,data);
       cin >> data;
    }
}


//Function to printing the bst, have same function like binary tree
//function to print using level order traversal
void LvlOrderTraversal(BST* &root){
    //base case
    if(!root){
        cout << "null"<<endl;
        return;
    }

    queue<BST*> q;
    q.push(root);

    while(!q.empty()){
        BST* top = q.front();
        q.pop();

        cout << top->data << " ";
        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);

    }
}

//function of inorder traversal
void inorder(BST*&root){
    //base case //LNR
    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//------------ Morris Traversal
void MorrisTraveral(BST*& root) 
{ 
	BST *curr, *prev; 

	if (root == NULL) 
		return; 

	curr = root; 

	while (curr != NULL) { 

		if (!curr->left) { 
			cout << curr->data << " "; 
			curr = curr->right; 
		} 

		else { 

			/* Find the previous (prev) of curr */
			prev = curr->left; 
			while (prev->right != NULL && prev->right != curr) 
				prev = prev->right; 

			/* Make curr as the right child of its
			previous */
			if (prev->right == NULL) { 
				prev->right = curr; 
				curr = curr->left; 
			} 

			/* fix the right child of previous */
			else { 
				prev->right = NULL; 
				cout << curr->data << " "; 
				curr = curr->right; 
			} 
		} 
	} 
} 

//preorder traversal, NLR
void preorder(BST*&root){
    //base case
    if(!root) return;
    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

//postorder , LRN
void postorder(BST*& root){
    //base case
    if(!root) return;
    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}


//---------- Function to search an ele on bst
bool searchInBst(BST* &root,int data){
    if(!root) return false;

    if(root->data == data) return true;

    if(data > root->data)  
        return searchInBst(root->right,data);
    return searchInBst(root->left,data);
}


//-----------fnction to find most minimum
int mostMinimum(BST* root) {
    // Code here
    
    //base case
    if(!root) return -1;
    
    if(!root->left) return root->data;
    
    return mostMinimum(root->left);
}

//-------------function to finding the most maxi and most maxi element
int mostMaximum(BST*& root){
    //base case
    if(!root) return -1;

    //isleaf
    if(!root->left && !root->right) return root->data;

    if(root->right) return mostMaximum(root->right);
    else return mostMaximum(root->left);
}

//------------ function to finding the inorder predecessor
int predecessor = -1;
void inorderPredecessor(BST* &root,int data){
    //base case
    if(!root) return ;

    if(data > root->data){
        //can get predecessor
        predecessor = root->data;
        inorderPredecessor(root->right,data);
    }
    else inorderPredecessor(root->left,data);

}

//------------function to finding the inorder successor
int successor = -1;
void inorderSuccessor(BST*& root,int data){
    //base case
    if(!root) return;

    if(data < root->data){
        successor = root->data;
        inorderSuccessor(root->left,data);
    }
    else inorderSuccessor(root->right,data);
}


//--------------- function to delete the key in bst
BST* deleteKeyInBst(BST*&  root,int key){
    //base case
    if(!root) return root;

    //find the key
    if(root->data == key){
        //then follow the steps to delete
        //is is root is leaf
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        //if , have one child
        else if(root->left && !root->right){
            BST* temp = root->left;
            delete root;
            return temp;
        }

        //is on right
        else if(root->right && !root->left){
            BST* temp = root->right;
            delete root;
            return temp;
        }

        //last case, have two childes
        //then find most min from left, or can do most maxi from right, and replace
        else{
            int mini = mostMinimum(root->right);
            root->data = mini;
            root->right =  deleteKeyInBst(root->right,mini); 
            return root;
        }
    }
    else if(key > root->data){
        root->right = deleteKeyInBst(root->right,key);
        return root;
    }
    else{
        root->left = deleteKeyInBst(root->left,key);
        return root;
    }
    return NULL;
}


//--------------- Main function to running the program
int main() {
    BST* root = NULL;

    //build string-> 10 9 29 8 7 4 -1

    //build the bst
    cout << endl << "Build the bst, so enter vector of the elements "<<endl;
    buildBST(root);

    //Print the bst
    cout <<endl << "Print the bst,have multiple methods "<<endl;

    // cout <<endl<< "Level order traversal "<<endl;
    // LvlOrderTraversal(root);

    cout <<endl <<  "In order traversal "<<endl;
    inorder(root);

    // cout <<endl <<  "Pre order traversal "<<endl;
    // preorder(root);

    // cout <<endl <<  "Post order traversal "<<endl;
    // postorder(root);

    //--------- IMplment search in bst
    int data ;
    cout <<endl << endl<< "Search element in bst "<<endl;
    // cin >> data;
    // string ans = searchInBst(root,data) == true ? "YES" : "NO";
    // cout << data << " is exist ? "<< ans;

    //--------------- IMplment function in bst, to finding most minimum and most maximum in bst
    int mini = mostMinimum(root);
    int maxi = mostMaximum(root);

    cout <<endl << "Most minimum and most maximum value in bst is "<<mini << " & "<<maxi <<endl;

    //----------- IMplment the inorder predecessor, and inorder successor
    // cout << endl << "Finding the inorder predecessor, key>data just "<<endl;
    // inorderPredecessor(root,8);
    // cout << predecessor <<endl;

    // cout << endl << "Finding the inorder successor, key<data just "<<endl;
    // inorderSuccessor(root,8);
    // cout << successor <<endl;

    //---------- Morris Traversal
    cout << endl<< "Morris Traversal "<<endl;
    MorrisTraveral(root);

    //-------------IMplment the deletion of the a node in bst
    int key;
    cout << endl << "Enter key to delete "<<endl;
    cin >> key;
    root = deleteKeyInBst(root,key); //assume key always exist
    
    cout <<endl <<  "In order traversal "<<endl;
    inorder(root);

    return 0;
}