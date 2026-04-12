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
struct LL{
    Node* head;
    Node* tail;

    LL(){
       head = tail = NULL; 
    }
    void pushFront(int val){
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void pushBack(int val){
        Node* newNode = new Node(val);
        if (head==NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pushAt(int val,int key){
        Node* newNode = new Node(val);
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
                if (temp==NULL)
                {
                    cout << "Index not Found" << endl;
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void popFront(){
        if (head==NULL)
        {
            return;
        }
        else{
            Node* temp = head;
            head = temp->next;
            if (head==NULL)
            {
                tail = NULL;
            }
            delete temp;
        }
    }
    void popBack(){
        if (head==NULL)
        {
            return;
        }
        else{
            Node* temp = head;
            while (temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail = temp;
        }
    }
    void printLL(){
        Node* temp = head;
        cout << "LINKLIST = ";
        while (temp!=NULL)
        {
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LL l1;
    l1.pushFront(1);
    l1.pushFront(2);
    l1.pushFront(3);
    l1.pushFront(4);
    l1.pushAt(5,3);

    l1.printLL();
}