#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;Node* right;
    Node(int val){
        left=right=NULL;
        data=val;
    }
};

class BST{
public:
    int count;
    Node* root;
    BST(){
        root = NULL;
        count=0;
    }
    Node* insert(Node* root,int val){
        if (root == NULL)
        {
            return new Node(val);
        }
        if (val>root->data) root->right=insert(root->right,val);
        else root->left=insert(root->left,val);
        return root;        
    }
};