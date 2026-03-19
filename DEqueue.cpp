#include <iostream>
using namespace std;

class Deque {
public:
    int size, front, rear;
    int* arr;

    Deque(int s) {
        size = s;
        arr = new int[s];
        front = rear = -1;
    }

    void pushBack(int data) {
        if (rear == size - 1) {
            cout << "Deque Overflow at Rear" << endl;
            return;
        }

        if (front == -1) front = 0;

        rear++;
        arr[rear] = data;
        cout << "Inserted " << data << " at rear" << endl;
    }

    void pushFront(int data) {
        if (front == 0) {
            cout << "Deque Overflow at Front" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            front--;
        }

        arr[front] = data;
        cout << "Inserted " << data << " at front" << endl;
    }

    void popFront() {
        if (front == -1 || front > rear) {
            cout << "Deque Underflow from Front" << endl;
            return;
        }

        cout << "Removed " << arr[front] << " from front" << endl;
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void popBack() {
        if (rear == -1 || front > rear) {
            cout << "Deque Underflow from Rear" << endl;
            return;
        }

        cout << "Removed " << arr[rear] << " from rear" << endl;
        rear--;

        if (front > rear) {
            front = rear = -1;
        }
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Enter deque size : ";
    int n;
    cin >> n;

    Deque dq(n);

    int choice = 1;

    while (choice) {
        cout << "\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n0. Exit\n";
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