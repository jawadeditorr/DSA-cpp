#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node(int val){
        value = val;
        next = NULL;
    }
};
class CircularList{
public:
    Node*head;
    Node* tail;
    CircularList(){
        head=tail=NULL;
    }
    void insertAtHead(int value){
        Node* newNode = new Node(value);
        if (head==NULL)
        {
            head=tail=newNode;
            tail->next=head;
        }
        else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }
    void insertAtTail(int value){
        Node* newNode = new Node(value);
        if (head==NULL)
        {
            head=tail=newNode;
            tail->next=head;
        }
        else{
            tail->next=newNode;
            newNode->next=head;
            tail=newNode;
        }
    }
    void print(){
        if (head==NULL) 
        {
            return;
        }
        cout << head->value << "->";
        Node* temp = head->next;
        while (temp!=head)
        {
            cout << temp->value << "->";
            temp=temp->next;
        }
        cout << temp->value << endl;        
    }
};

int main(){
    CircularList cll;
    cll.insertAtHead(7);
    cll.insertAtHead(6);
    cll.insertAtTail(8);
    cll.print();
}