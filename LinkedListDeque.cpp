#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Deque {
public:
    Node* front;
    Node* rear;

    Deque() {
        front = rear = NULL;
    }

    // 🔹 Insert at Front
    void pushFront(int data) {
        Node* newNode = new Node(data);

        if (front == NULL) {
            front = rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << "Inserted " << data << " at front" << endl;
    }

    // 🔹 Insert at Rear
    void pushBack(int data) {
        Node* newNode = new Node(data);

        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cout << "Inserted " << data << " at rear" << endl;
    }

    // 🔹 Delete from Front
    void popFront() {
        if (front == NULL) {
            cout << "Deque Underflow from Front" << endl;
            return;
        }

        Node* temp = front;
        cout << "Removed " << temp->data << " from front" << endl;

        front = front->next;

        if (front != NULL)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
    }

    // 🔹 Delete from Rear
    void popBack() {
        if (rear == NULL) {
            cout << "Deque Underflow from Rear" << endl;
            return;
        }

        Node* temp = rear;
        cout << "Removed " << temp->data << " from rear" << endl;

        rear = rear->prev;

        if (rear != NULL)
            rear->next = NULL;
        else
            front = NULL;

        delete temp;
    }

    bool isEmpty() {
        if (front == NULL)
            return true;
        else
            return false;
    }

    void display() {
        if (front == NULL) {
            cout << "Deque is empty." << endl;
            return;
        }

        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;

    int choice = 1;

    while (choice) {
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            dq.pushFront(val);
        }
        else if (choice == 2) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            dq.pushBack(val);
        }
        else if (choice == 3) {
            dq.popFront();
        }
        else if (choice == 4) {
            dq.popBack();
        }
        else if (choice == 5) {
            dq.display();
        }
    }

    return 0;
}