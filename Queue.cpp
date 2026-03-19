#include <iostream>
using namespace std;

class Queue {
public:
    int size, front, rear;
    int* arr;

    Queue(int s) {
        size = s;
        arr = new int[s]; 
        front = rear = -1;
    }

    void enqueue(int data) {
        if (rear == size - 1) {
            cout << "Queue Overflow: No more space" << endl;
            return;
        }
        if (front == -1) front = 0;
        
        rear++;
        arr[rear] = data;
        cout << "Added " << data << "to the queue" << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow: Queue is empty" << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << "from the queue" << endl;
        front++;
    }

    bool isEmpty(){
        if (rear==-1)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void shiftLeft(){
        int x=front;
        while (x+1!=rear)
        {
            arr[x] = arr[x+1];
        }
    }

    bool isFull(){
        if (rear==size-1)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(3);
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(5);

    q.dequeue();
    q.shiftLeft();
    
    q.display();
    return 0;
}