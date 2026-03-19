#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value){
        data=value;
        next=prev=NULL;
    }
};
class DoublyList{
    public:
    Node* head;
    Node* tail;
    DoublyList(){
        head = tail = NULL;
    }
    void pushFront(int value){
        Node* newNode = new Node(value);
        if (head==NULL)
        {
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void pushBack(int value){
        Node* newNode = new Node(value);
        if (head==NULL)
        {
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
};