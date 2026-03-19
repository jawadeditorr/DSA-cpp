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

    void insertAtStart(int val){
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

    void insertAtEnd(int val){
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
                newNode->next = temp->next;
                temp->next=newNode;
            }
            temp = temp->next;
        }
    }

    void popFront(){
        if(head==NULL){
            cout << "Linked List is empty" << endl;
            return;
        }
        Node* temp = head ;
        head = head->next;
        temp->next=NULL;

        delete temp;
    }

    void popBack(){
        if (head==NULL)
        {
            return;
        }
        Node* temp = head;
        while (temp->next!=tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void popNode(int key){
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        while (current->next!=NULL && current->next->value!=key)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "value not found" << endl;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void printList(){
        Node* temp = head;
        while (temp!=NULL)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    List l1;
    l1.insertAtEnd(40);
    l1.insertAtEnd(50);
    l1.insertAtEnd(60);
    l1.insertAtEnd(70);
    l1.insertAtStart(80);   //Inserting at start
    l1.insertAtEnd(80);     //Inserting at end
    l1.insertAfter(80,50);  //Inserting in the middle
    cout << "Linked List : " << endl;
    l1.printList();
    cout << "Deleting Node at start : " << endl;
    l1.popFront();
    l1.printList();
    cout << "Deleting Node At End : " << endl;
    l1.popBack();
    l1.printList();
    cout << "Deleting Node in the Middle : " << endl;
    l1.popNode(80);
    l1.printList();
    
    return 0;
}