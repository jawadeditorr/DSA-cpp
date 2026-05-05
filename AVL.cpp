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

    Node* minValueNode(Node* node){
        Node* current = node;
        while(current->left != NULL)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int val){
        if(root == NULL) return root;

        if(val < root->data)
            root->left = deleteNode(root->left, val);

        else if(val > root->data)
            root->right = deleteNode(root->right, val);

        else{
            if(root->left == NULL || root->right == NULL){
                Node* temp = root->left ? root->left : root->right;

                if(temp == NULL){
                    temp = root;
                    root = NULL;
                }
                else{
                    *root = *temp;
                }
                delete temp;
                count--;
            }
            else{
                // Node with two children
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if(root == NULL) return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if(balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if(balance > 1 && getBalance(root->left) < 0){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if(balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if(balance < -1 && getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
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

    int noOfNodes(){
        return count;
    }
};

int main(){
    AVL tree1;
    cout << "===AVL===" << endl;
    tree1.root = tree1.insert(tree1.root,10);
    tree1.root = tree1.insert(tree1.root,30);
    tree1.root = tree1.insert(tree1.root,20);

    cout << "PreOrder : ";
    tree1.preOrder(tree1.root);

    cout << "\nAfter Deletion (delete 20): ";
    tree1.root = tree1.deleteNode(tree1.root, 20);

    cout << "\nInOrder : ";
    tree1.preOrder(tree1.root);

    return 0;
}