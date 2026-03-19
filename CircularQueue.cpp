#include <iostream>
using namespace std;

template <typename T>
class CircularQueue{
public:
    int size, front, rear, currSize;
    T* arr;
    CircularQueue(int s){
        size = s;
        front = currSize = 0;
        rear = -1;
        arr = new T[size];
    }
    
    bool isEmpty(){
        return currSize == 0;
    }

    bool isFull(){
        return currSize == size;
    }

    void enqueue(T data){
        if(isFull()){
            cout << "circular Queue is Full" << endl;
            return;
        }
        rear = (rear+1)%size;
        arr[rear] = data;
        currSize++;
    }

    void dequeue(){
        if (isEmpty())
        {
            cout << "Circular Queue is Empty" << endl;
            return;
        }
        front = (front+1) % size;
        currSize--;
    }

    T getFront(){
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    CircularQueue<int> cq(5);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);
    cq.enqueue(70);
    cq.enqueue(80);  

    cout << "Queue : ";
    cq.display();  
}