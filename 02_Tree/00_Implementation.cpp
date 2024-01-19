#include <iostream>
#include <queue>
#include<stack>

using namespace std;

//------------- Class of the tree, assume we implement binary tree
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    //--------- Constructor
    Tree(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//--------------- Function to build tree
Tree *buildTree(Tree *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Tree(data);

    if (data == -1)
        return NULL;

    cout << "Enter data to insert in left: " << endl;
    root->left = buildTree(root->left);

    cout << "Enter data to insesrt in right: " << endl;
    root->right = buildTree(root->right);

    return root;
}

//------------- Level Order Traversal
void LevelOrderTraversal(Tree *root)
{
    queue<Tree *> q;
    q.push(root);
    q.push(NULL); // seperator for enter putting

    while (!q.empty())
    {
        Tree *top = q.front();
        q.pop();

        if (top == NULL)
        { // old level is completed traversal
            cout << endl;

            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << top->data << " ";

            if (top->left)
                q.push(top->left);

            if (top->right)
                q.push(top->right);
        }
    }
}


//---- Inorder Traversal 
void InorderTraversal(Tree* root){
    //LNR

    //base case
    if(root == NULL)
        return;

    if(root->left)
        InorderTraversal(root->left);

    cout << root->data << " ";

    if(root->right)
        InorderTraversal(root->right);


}

//-------- Preorder Traversal
void PreOrderTraversal(Tree* root){
    //NLR
    //base case
    if(root == NULL)
        return;
    
    cout << root->data << " ";

    if(root->left)
        PreOrderTraversal(root->left);
    
    if(root->right) 
        PreOrderTraversal(root->right);
}

//-------- Preorder Traversal
void PostOrderTraversal(Tree* root){
    //LRN
    //base case
    if(root == NULL)
        return;

    if(root->left)
        PostOrderTraversal(root->left);
    if(root->right)
        PostOrderTraversal(root->right);
    
    cout << root->data << " ";
}

//---------- Build tree using LvlOrder Traversal
void BuildTreeLvlOrderTraversal(Tree* & root){
    queue<Tree*> q;
    
    int data;
    cout << "Entre data for root: "<<endl;
    cin >>data;

    root = new Tree(data);
    q.push(root);

    while (!q.empty())
    {
        Tree* temp = q.front();
        q.pop();
        
        cout << "Enter left data to "<< temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new Tree(leftData);
            q.push(temp->left);
        }

        cout << "Enter right data to "<< temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new Tree(rightData);
            q.push(temp->right);
        }
    }
    
}

//------------- Function to print reverse level order
void ReverseLvlOrder(Tree* root){
    //base case
    if(root == NULL){
        cout << " NULL "<<endl;
        return;
    }

    stack<Tree*> st;
    st.push(root);

    // cout << st.top()->data << endl;

    while(!st.empty()){
        Tree* tp = st.top();
        cout << tp->data << " ";
        st.pop();


        if(tp->left)
            st.push(tp->left);
        
        if(tp->right)
            st.push(tp->right);

    }
}

int main()
{

    Tree *root = NULL;
    // -------- Build tree 
    // root = buildTree(root);

    //---------- Build tree using level order traversal
    BuildTreeLvlOrderTraversal(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //3 2 1 4 5 2 -1 -1 -1 -1 -1 -1 -1 -1

    //--------- Printing the level order traversal
    cout << endl
         << "Level order traversal " << endl;
    LevelOrderTraversal(root);

 //--------- Printing the reverse level order traversal
    cout << endl
         << "Reverse Level order traversal " << endl;
    ReverseLvlOrder(root);

  /* //--------- Printing Inorder traversal
    cout << endl << "Inorder Traversal "<<endl;
    InorderTraversal(root);

    //--------- Printing Pre order traversal
    cout << endl << "PreOrder Traversal "<<endl;
    PreOrderTraversal(root);

    //--------- Printing PostOrder traversal
    cout << endl << "Postorder Traversal "<<endl;
    PostOrderTraversal(root); */




    return 0;
}
