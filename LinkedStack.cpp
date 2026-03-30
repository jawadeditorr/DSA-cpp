#include <iostream>
using namespace std;

class Node{
public:
    char data;
    Node* next;

    Node(char val){
        data = val;
        next = NULL;
    }
};

class LinkedStack{
private:
    Node* head;
public:
    LinkedStack(){
        head = NULL;
    }

    void push(char val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    char pop(){
        if(head == NULL){
            cout << "Stack Underflow" << endl;
            return ' ';
        }
        else{
            Node* temp = head;
            char val = temp->data;
            head = head->next;
            delete temp;
            return val;
        }
    }

    void display(){
        Node* temp = head;
        while (temp->next!=NULL)
        {
            cout << temp->data << "  ";
            temp=temp->next;
        }
        cout << temp->data << endl;
    }
};
int main(){
    LinkedStack st;
    st.push('D');
    st.push('A');
    st.push('W');
    st.push('A');
    st.push('J');
    cout << "Stack : ";
    st.display();
    cout << "Popping Nodes form stack : ";
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
}