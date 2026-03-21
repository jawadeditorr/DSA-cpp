#include <iostream>
using namespace std;
/*
Question:-
1)Write an algorithm to add an element
into an ascending Priority Queue 
implemented using a sorted array. 
2)Write an algorithm to add an element 
into an descending Priority Queue 
implemented using a stack.
*/
class Queue{
public:
    int* arr;
    int size,front,rear;
    Queue(int s){
        size = s;
        front = rear = -1;
        arr = new int[s];
    }
    void push(int val){
        if (rear == size-1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front==-1)
        {
            front=0;
        }
        rear++;
        arr[rear]=val;
    }
    void pop(){
        if (rear==size-1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else{
            front++;
        }
    }
    void insertInAscend(int val){
        if (rear==size-1)
        {
            cout << "Queue is Fulll" << endl;
            return;
        }
        if (front == -1)
        {
            push(val);
            return;
        }
        int i=0;
        for (i = rear; i >= front; i--)
        {
            if (val<arr[i])
            {
                arr[i+1]=arr[i];
            }else{
                break;
            }
        }
        arr[i+1]=val;
        rear++;
    }
    void insertInDesc(int val){
        if (rear==size-1)
        {
            cout << "Queue is Fulll" << endl;
            return;
        }
        if (front == -1)
        {
            push(val);
            return;
        }
        for (int i = rear; i >= front; i--)
        {
            if (val>arr[i])
            {
                arr[i+1]=arr[i];
            }else{
                arr[i+1] = val;
                rear++;
                return;
            }
        }
        arr[front] = val;
        rear++;
    }
    void display(){
        if (front == -1){
            cout << "Queue Empty" << endl;
            return;
        }
        for(int i=front;i<=rear;i++){
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Queue q(5);
    q.insertInAscend(12);
    q.insertInAscend(43);
    q.insertInAscend(14);
    q.insertInAscend(45);
    q.insertInAscend(25);
    q.display();
}
