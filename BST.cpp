#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        left=right=NULL;
        data = val;
    }
};
class BST{
public:
    Node* root;
    BST(){
        root = NULL;
    }

    Node* insert(Node* root,int val){
        if (root==NULL)
        {
            return new Node(val);
        }
        if (val<root->data)
        {
            root->left=insert(root->left,val);
        }else{
            root->right=insert(root->right,val);
        }
        return root;
    }

    void preOrder(Node* root){
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root){
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    
    void postOrder(Node* root){
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    Node* buildBST(vector<int> arr){
        for (int val : arr)
        {
            root = insert(root,val);
        }
        return root;   
    }
};
