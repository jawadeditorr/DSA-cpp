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
    void insertAfter(int val,int key){
        Node* temp = head;
        while (temp!=NULL)
        {
            if (temp->value==key)
            {
                Node* newNode = new Node(val);
                newNode->next=temp->next;
                temp->next=newNode;
            }
            temp=temp->next;            
        }
    }
    void popFront(){
        if(head==NULL){
            return;
        }
        else{
            Node* temp;
            
        }
    }
    void printList(){
        while (head!=NULL)
        {
            cout << head->value << "->";
            head=head->next;
        }
        cout << "NULL" << endl;
    }
};
int main(){
    List ll;
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(1);
    ll.pushBack(4);
    ll.insertAfter(5,4);
    ll.printList();
}