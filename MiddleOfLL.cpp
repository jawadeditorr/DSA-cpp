#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int val){
        value = val;
        next = NULL;
    }
};

struct List{
    Node* head;
    Node* tail;

    List(){
        head=tail=NULL;
    }

    void pushFront(int val){
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head=tail=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
};

Node midOfList(List& head){
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL || fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    return 0;
}