#include <iostream>
using namespace std;

class PriorityQueue {
    int *arr;
    int size;
    int front;
    int rear;

public:
    PriorityQueue(int s){
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void insertAscending(int val){
        if (rear == size - 1){
            cout << "Queue Full\n";
            return;
        }

        if (front == -1){
            front = rear = 0;
            arr[rear] = val;
            return;
        }

        int i;
        for (i = rear; i >= front; i--){
            if (val < arr[i]){   // 🔥 smaller → shift
                arr[i+1] = arr[i];
            } else {
                break;
            }
        }

        arr[i+1] = val;
        rear++;
    }

    void insertDescending(int val){
        if (rear == size - 1){
            cout << "Queue Full\n";
            return;
        }

        if (front == -1){
            front = rear = 0;
            arr[rear] = val;
            return;
        }

        int i;
        for (i = rear; i >= front; i--){
            if (val > arr[i]){   
                arr[i+1] = arr[i];
            } else {
                break;
            }
        }

        arr[i+1] = val;
        rear++;
    }

    void insert(int val){
        // full
        if (rear == size - 1){
            cout << "Queue Full\n";
            return;
        }

        // empty
        if (front == -1){
            front = rear = 0;
            arr[rear] = val;
            return;
        }

        int i;
        // shift elements (ascending order)
        for (i = rear; i >= front; i--){
            if (val < arr[i]){
                arr[i+1] = arr[i];
            } else {
                break;
            }
        }

        arr[i+1] = val;
        rear++;
    }

    void remove(){
        if (front == -1){
            cout << "Queue Empty\n";
            return;
        }

        front++;

        if (front > rear){
            front = rear = -1;
        }
    }

    int peek(){
        if (front == -1){
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front]; // smallest element
    }

    void display(){
        if (front == -1){
            cout << "Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    PriorityQueue pq(10);
    PriorityQueue pq1(10);

    pq.insertDescending(30);
    pq.insertDescending(10);
    pq.insertDescending(20);
    pq.insertDescending(5);

    pq1.insertAscending(30);
    pq1.insertAscending(10);
    pq1.insertAscending(20);
    pq1.insertAscending(5);

    pq.display();   // 5 10 20 30
    pq1.display();   // 5 10 20 30

    cout << "Top: " << pq.peek() << endl;

    pq.remove();
    pq.display();   // 10 20 30
}