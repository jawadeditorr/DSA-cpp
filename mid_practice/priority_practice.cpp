#include <iostream>
using namespace std;

struct Priority{
    int front,rear,size;
    int* arr;

    Priority(int s){
        front=rear=-1;
        size=s;
        arr = new int[s];
    }
    
    void insertAsc(int val){
        if (rear == size-1)
        {
            cout << "Overflow" << endl;
        }
        if (front==-1)
        {
            front = rear = 0;
            arr[rear]=val;
            return;
        }
        int i;
        for(i = rear; i >= front; i--){
            if(val < arr[i]){
                arr[i+1]=arr[i];
            } else{
                break;
            }
        }
        arr[i+1]=val;
        rear++;
    }
    
    void insertDes(int val){
        if (rear == size-1)
        {
            cout << "Overflow" << endl;
        }
        if (front==-1)
        {
            front = rear = 0;
            arr[rear]=val;
            return;
        }
        int i;
        for(i = rear; i >= front; i--){
            if(val > arr[i]){
                arr[i+1]=arr[i];
            } else{
                break;
            }
        }
        arr[i+1]=val;
        rear++;
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
    Priority pq(10);
    Priority pq1(10);

    pq.insertDes(30);
    pq.insertDes(10);
    pq.insertDes(20);
    pq.insertDes(5);

    pq1.insertAsc(30);
    pq1.insertAsc(10);
    pq1.insertAsc(20);
    pq1.insertAsc(5);

    pq.display();   // 5 10 20 30
    pq1.display();
}