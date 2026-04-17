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

    
};