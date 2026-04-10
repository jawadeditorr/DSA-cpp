#include <iostream>
#include <vector>
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

class AVL{
public:
    Node* root;
    int count;

    AVL(){
        root = NULL;
        count = 0;
    }

    int getHeight(Node* node){
        if(node == NULL) return 0;
        return node->height;
    }

    int getBalance(Node* node){
        if(node == NULL) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int val){
        if(node == NULL){
            count++;
            return new Node(val);
        }

        if(val < node->data)
            node->left = insert(node->left, val);
        else if(val > node->data)
            node->right = insert(node->right, val);
        else
            return node; 

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if(balance > 1 && val < node->left->data)
            return rightRotate(node);

        if(balance < -1 && val > node->right->data)
            return leftRotate(node);

        if(balance > 1 && val > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if(balance < -1 && val < node->right->data){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Node* root){
        if(root == NULL) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root){
        if(root == NULL) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node* root){
        if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    Node* buildAVL(vector<int> arr){
        for(int val : arr){
            root = insert(root, val);
        }
        return root;
    }

    int noOfNodes(){
        return count;
    }
};

int main(){
    vector<int> arr = {3,2,1,5,6,4};

    AVL tree;

    tree.buildAVL(arr);

    cout << "PreOrder : ";
    tree.preOrder(tree.root);

    cout << "\nInOrder : ";
    tree.inOrder(tree.root);

    cout << "\nPostOrder : ";
    tree.postOrder(tree.root);

    cout << "\nNo of Nodes : " << tree.noOfNodes();

    return 0;
}