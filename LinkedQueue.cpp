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

    int sumOfDigits(){
        int sum=0;
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return sum;
        }

        Node* temp = front;

        while (temp != NULL) {
            sum+=temp->data;
            temp = temp->next;
        }

        return sum;
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
    Queue myqueue;

    myqueue.enqueue(1);
    myqueue.enqueue(5);
    myqueue.enqueue(3);

    cout << "Sum of Digits : " << myqueue.sumOfDigits() << endl;
    myqueue.dequeue();
    myqueue.dequeue();
    myqueue.dequeue();
    return 0;
}