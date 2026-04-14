#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left,*right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct BST{
    Node* root;
    int count;

    BST(){
        root = NULL;
        count = 0;
    }
    
    Node* insert(Node* root, int val){
        Node* newNode = new Node(val);
        if (root == NULL)
        {
            return newNode;
        }
        if (val > root->data)
        {
            root->right = insert(root->right,val);
        }
        else
        {
            root->left = insert(root->left,val);
        }
        return root;
    }

    void preOrder(Node* root){
        if (root==NULL)
        {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    
    void inOrder(Node* root){
        if (root==NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    
    void postOrder(Node* root){
        if (root==NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
};

int main(){
    BST tree1;
    tree1.root = tree1.insert(tree1.root,3);
    tree1.root = tree1.insert(tree1.root,2);
    tree1.root = tree1.insert(tree1.root,1);
    tree1.root = tree1.insert(tree1.root,5);
    tree1.root = tree1.insert(tree1.root,6);
    tree1.root = tree1.insert(tree1.root,4);

    tree1.preOrder(tree1.root);
    cout << "\n";
    tree1.inOrder(tree1.root);
    cout << "\n";
    tree1.postOrder(tree1.root);
}