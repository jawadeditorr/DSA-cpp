#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at End
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at Start
void insertStart(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Insert at Middle (after position 2)
void insertMiddle(Node*& head, int value) {
    if (head == NULL) return;

    Node* temp = head;
    int count = 1;

    while (count < 2 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}

// Delete Node by Value
void deleteNode(Node*& head, int value) {
    if (head == NULL) return;

    Node* temp = head;
    Node* prev = NULL;

    if (temp->data == value) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

// Display List
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node* head = NULL;

    // Initial List
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    cout << "Initial Linked List: ";
    display(head);

    // Insert at Start
    insertStart(head, 5);
    cout << "After Inserting at Start: ";
    display(head);

    // Insert at Middle
    insertMiddle(head, 15);
    cout << "After Inserting in Middle: ";
    display(head);

    // Insert at End
    insertEnd(head, 40);
    cout << "After Inserting at End: ";
    display(head);

    // Delete Added Nodes
    deleteNode(head, 5);
    deleteNode(head, 15);
    deleteNode(head, 40);

    cout << "After Deleting Added Nodes: ";
    display(head);

    return 0;
}