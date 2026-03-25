#include <iostream>
using namespace std;
class Stack{
public:
    int top;
    int size;
    int* values;

    Stack(int s){
        top = -1;
        size = s;
        values = new int[size];
    }

    void push(char val){
        if(top == size-1){
            //cout << "Stack Overflow" << endl;
        }
        else{
            top++;
            values[top] = val;
        }
    }

    int pop(){
        if(top == -1){
            //cout << "Stack Underflow" << endl;
            return ' ';
        }
        else{
            char temp = values[top];
            top--;
            return temp;
        }
    }

    int getTop(){
        return values[top];
    }

    bool isEmpty(){
        if (top == -1)
        {
            return true;
        }
        else{
            return false;
        }
    }
};

class Queue{
public:
    Stack s1;
    Stack s2;

    Queue(int s) : s1(s), s2(s) {}
    
    void insertInDesc(int val){
        while (!s1.isEmpty() && s1.getTop()>val)
        {
            s2.push(s1.getTop());
            s1.pop();        
        }

        s1.push(val);

        while (!s2.isEmpty())
        {
            s1.push(s2.getTop());
            s2.pop();
        }
    }

    void display(){
        if(s1.isEmpty()){
            cout << "Queue is empty\n";
            return;
        }

        for(int i = 0; i <= s1.top; i++){
            cout << s1.values[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q1(4);
    q1.insertInDesc(45);
    q1.insertInDesc(15);
    q1.insertInDesc(95);
    q1.insertInDesc(67);
    q1.display();
}