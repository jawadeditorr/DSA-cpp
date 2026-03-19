#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = rear = NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (rear == NULL) {
            front = rear = newNode;
            cout << "Added " << data << " to the queue" << endl;
            return;
        }

        rear->next = newNode;
        rear = newNode;

        cout << "Added " << data << " to the queue" << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow: Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued " << temp->data << " from the queue" << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    bool isEmpty() {
        if (front == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
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
    Queue q;

    cout << "How many elements you want to insert: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        int val;
        cin >> val;
        q.enqueue(val);
    }

    q.display();

    cout << "Do you want to dequeue any element? (no=0 / yes=1): ";
    int choice;
    cin >> choice;

    while (choice == 1) {
        q.dequeue();
        cout << "Do you want to dequeue more elements? (no=0 / yes=1): ";
        cin >> choice;
    }

    q.display();

    return 0;
}