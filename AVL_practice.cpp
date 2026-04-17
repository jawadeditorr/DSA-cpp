#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val){
        data = val;
        left = right = NULL;
        height = 1;
    }
};

struct AVL{
    Node* root;

    AVL(){
        root = NULL;
    }

    int height(Node* root){
        if (root == NULL)
        {
            return 0;
        }
        return root->height;
    }

    int balanceFactor(Node* root){
        if (root == NULL)
        {
            return 0;
        }
        return height(root->left) - height(root->right);
    }

    int max(int a,int b){
        if(a>b) return a;
        else return b;
    }

    Node* rightRotate(Node* root){
        Node* root2 = root->left;
        Node* root3 = root2->right;

        root2->right = root;
        root->left = root3;

        root->height= max(height(root->left), height(root->right))+1;
        root2->height= max(height(root2->left), height(root2->right))+1;

        return root2;
    }

    Node* leftRotate(Node* root){
        Node* root2 = root->right;
        Node* root3 = root2->left;

        root2->left = root;
        root->right = root3;

        root->height= max(height(root->left), height(root->right))+1;
        root2->height= max(height(root2->left), height(root2->right))+1;

        return root2;
    }

    Node* insert(Node* root, int key){
        if (root == NULL)
        {
            return new Node(key);
        }
        if (key < root->data)
        {
            root->left = insert(root->left,key);
        }
        else if (key > root->data)
        {
            root->right = insert(root->right, key);
        }
        else{return root;}
        
        root->height = 1 + max(height(root->left),height(root->right));
        int balance = balanceFactor(root);
        if (balance > 1)
        {
            if (balanceFactor(root->left) >= 0)
            {
                return rightRotate(root);
            } else{
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if (balance < -1)
        {
            if (balanceFactor(root->right) <= 0)
            {
                return leftRotate(root);
            } else{
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
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
    AVL tree1;
    tree1.root = tree1.insert(tree1.root,16);
    tree1.root = tree1.insert(tree1.root,20);
    tree1.root = tree1.insert(tree1.root,18);
    // tree1.root = tree1.insert(tree1.root,5);
    // tree1.root = tree1.insert(tree1.root,6);
    // tree1.root = tree1.insert(tree1.root,4);
    cout << "PreOrder : ";
    tree1.preOrder(tree1.root);
    cout << "\nInOrder : ";
    tree1.inOrder(tree1.root);
    cout << "\nPostOrder : ";
    tree1.postOrder(tree1.root);
}