#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
struct Doubly{
    Node* head;
    Node* tail;

    Doubly(){
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
            head->prev = newNode;
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
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pushAt(int val, int key){
        if (key==0)
        {
            pushFront(val);
            return;
        }
        else
        {    
            Node* temp = head;
            for (int i = 0; i < key-2; i++)
            {
                if(temp==NULL){
                    cout << "INDEX OUT OF RANGE !!!!!!!!!!!!!!!";
                    return;
                }
                temp = temp->next;
            }
            if (temp==tail)
            {
                pushBack(val);
            }
            else{
                Node* newNode = new Node(val);
                newNode->next=temp->next;
                newNode->prev=temp;
                temp->next->prev=newNode;
                temp->next=newNode;
            }
        }   
    }

    void popFront(){
        if (head==NULL)
        {
            return;
        }
        Node* temp = head;
        head = temp->next;
        if (head!=NULL)
        {
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    void popBack(){
        if (head==NULL)
        {
            return;
        }
        else{
            Node* temp = tail;
            tail = temp->prev;
            if (tail!=NULL)
            {
                tail->next=NULL;
            }
            
            temp->prev=NULL;
            delete temp;
        }
    }

    void printLL(){
        Node* temp = head;
        cout << "DOUBLY LIST : ";
        while (temp!=NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    Doubly d1;
    d1.pushBack(1);
    d1.pushBack(2);
    d1.pushBack(3);
    d1.pushBack(4);
    // d1.pushAt(5,3);
    d1.popFront();
    // d1.popFront();
    d1.printLL();
}