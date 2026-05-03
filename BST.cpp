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
    int count;
    Node* root;
    BST(){
        root = NULL;
        count = 0;
    }

    Node* insert(Node* root,int val){
        if (root==NULL)
        {
            count++;
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

    Node* findMin(Node* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key) {

        // Step 1: Find node
        if (root == NULL) return root;
        
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        
        else {
            // Node found
        
            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
        
            // Case 2: One child
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
        
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
        
            // Case 3: Two children
            Node* temp = findMin(root->right); // successor
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    
        return root;
    }

    int noOfNodes(){return count;}
};

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    BST tree1;
    //60, 40, 80, 20, 50, 70, 90, 10, 30, 45, 55

    tree1.root = tree1.insert(tree1.root,60);
    tree1.root = tree1.insert(tree1.root,40);
    tree1.root = tree1.insert(tree1.root,80);
    tree1.root = tree1.insert(tree1.root,20);
    tree1.root = tree1.insert(tree1.root,50);
    tree1.root = tree1.insert(tree1.root,70);
    tree1.root = tree1.insert(tree1.root,90);
    tree1.root = tree1.insert(tree1.root,10);
    tree1.root = tree1.insert(tree1.root,30);
    tree1.root = tree1.insert(tree1.root,45);
    tree1.root = tree1.insert(tree1.root,55);
    cout << "PreOrder : ";
    tree1.preOrder(tree1.root);
    cout << "\nInOrder : ";
    tree1.inOrder(tree1.root);
    // cout << "\nPostOrder : ";
    // tree1.postOrder(tree1.root);
    cout << "\nNo of Nodes : " << tree1.noOfNodes();
    tree1.deleteNode(tree1.root,40);

    cout << "\nInOrder : ";
    tree1.inOrder(tree1.root);
    cout << "\nPreOrder : ";
    tree1.preOrder(tree1.root);
}
/*
BST:
    (3)
    / \
  (2) (5)
  /   / \
(1) (4) (6)
*/