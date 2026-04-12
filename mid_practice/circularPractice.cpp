#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
struct CircularLL{
    Node* head;
    Node* tail;

    CircularLL(){
       head = tail = NULL; 
    }
    void pushFront(int val){
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head = tail = newNode;
            tail->next=newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next=newNode;
        }
    }
    void pushBack(int val){
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head = tail = newNode;
            tail->next=newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            newNode->next=head;
        }
    }
    void pushAt(int val,int key){
        if (key==0)
        {
            pushFront(val);
            return;
        }
        else
        {
            Node* temp = head;
            
            for (int i = 0; i < key-1; i++)
            {
                temp = temp->next;
                if (temp==head)
                {
                    cout << "Index not Found" << endl;
                    return;
                }
            }
            if (temp==tail)
            {
                pushBack(val);
                return;
            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void popFront(){
        if (head==NULL)
        {
            return;
        }
        else if (head==tail)
        {
            delete head;
            head=tail=NULL;
        }
        
        else{
            Node* temp = head;
            head = temp->next;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }

    void popBack(){
        if (head==NULL)
        {
            return;
        }
        else if (head==tail)
        {
            delete head;
            head=tail=NULL;
        }
        else{
            Node* prev = head;
            Node* temp = tail;
            while (prev->next!=tail){
                prev=prev->next;
            }
            tail = prev;
            temp->next=NULL;
            delete temp;
            tail->next=head;
        }
    }
    void printLL(){
        Node* temp = head;
        cout << "LINKLIST = ";
        do{
            if (temp==NULL)
            {
                cout << "EMPTY" << endl;
                return;
            }
            
            cout << temp->data << "->";
            temp=temp->next;
        }while (temp!=head);
        cout << head->data << endl;
    }
};

int main(){
    CircularLL l2;
    l2.printLL();
    CircularLL l1;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(4);
    l1.pushAt(5,3);

    l1.popFront();
    l1.popBack();

    l1.printLL();
}