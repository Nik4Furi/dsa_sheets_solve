/*
I have to create the class, to build the tree, if we insert any ele
*/
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void buildTree(Node* &root,int data){
    if(!root){
        root = new Node(data);
        return;
    }
    
    //left
    buildTree(root->left,data);

    //right
    buildTree(root->right,data);
}

//----------function to print tree
void printTree(Node* root){ //form in inorder
    if(!root){
        return; 
    }

    //left
    printTree(root->left);

    //data
    cout << root->data << " ";

    //right
    printTree(root->right);

}

int main(){

    int data;
    cin >> data;

    Node* root = NULL;
    cout << endl << "buidling a tree,only pass data "<<endl;
    buildTree(root,data);

    cout << endl << "Printing a tree "<<endl;
    printTree(root);




    return 0;
}