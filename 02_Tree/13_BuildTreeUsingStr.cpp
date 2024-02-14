//{ Driver Code Starts
// Initial Template for C++

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
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

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// } Driver Code Ends
// User function Template for C++

/*
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
*/

class Solution
{
    //---------function to insert else in a tree

    void buildTree(Node *&root, int data)
    {
        if (!root)
        {
            root = new Node(data);
            return;
        }

        // left
        buildTree(root->left, data);

        // right
        buildTree(root->right, data);
    }

public:
    // function to construct tree from string
    Node *treeFromString(string str)
    {
        // code here

        // Steps
        // 1. inserting eles in form of lvl order traversal
        int n = str.size();

        // Edge case
        if (n == 1)
        {
            int ch = str[0] - '0' + 0;
            Node *root = new Node(ch);
            return root;
        }

        // o/w we need to finding lvl order traversaldata
        map<int, vector<int>> mp; // key, arrays eles
        bool temp = str.size() == 7;
        cout << str[0] << " "<<str[1] << " && "<< temp << endl;

        int insertKey = 0;

        for (int i = 0; i < n; i++)
        {
            cout << str[i] << " & " << str[i]-'0'+0 <<endl;
            // if parenthesis
            if (str[i] == '(')
                insertKey++;

            else if (str[i] == ')')
                insertKey--;

            // if is integer
            if (str[i] != ')' && str[i] != '(')
            {
                cout << "insertKey " << insertKey << endl;
                // means is integer
                int ch = str[i] - '0' + 0;
                cout << ch << endl;

                mp[insertKey].push_back(ch);
            }
        }

        // Now we have sucsessfully created level order traversal vector
        Node *root = NULL;
        for (auto it : mp)
        {

            // vector traversal
            for (auto x : it.second)
            {
                cout <<  "values of x's " <<x << " ";
                buildTree(root, x);
            }
            cout << endl;
        }

        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout <<str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        cout <<endl<< "Print inorder"<<endl;
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends