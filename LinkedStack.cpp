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
};
int main(){
    LinkedStack st;
    cout << "using Nodes : " << endl;
    st.push('D');
    st.push('A');
    st.push('W');
    st.push('A');
    st.push('J');
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
}

/*

*/