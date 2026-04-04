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

    bool search(Node* root,int key){
        if (root==NULL)
        {
            return false;
        }
        if (key == root->data)
        {
            return true;
        }
        if (key<root->data)
        {
            return search(root->left,key);
        }
        else{
            return search(root->right,key);
        }
    }
};

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    BST tree1;
    tree1.root = tree1.insert(tree1.root,3);
    tree1.root = tree1.insert(tree1.root,2);
    tree1.root = tree1.insert(tree1.root,1);
    tree1.root = tree1.insert(tree1.root,5);
    tree1.root = tree1.insert(tree1.root,6);
    tree1.root = tree1.insert(tree1.root,4);
    cout << "PreOrder : ";
    tree1.preOrder(tree1.root);
    cout << "\nInOrder : ";
    tree1.inOrder(tree1.root);
    cout << "\nPostOrder : ";
    tree1.postOrder(tree1.root);
}
/*
BST:
    (3)
    / \
  (2) (5)
  /   / \
(1) (4) (6)
*/