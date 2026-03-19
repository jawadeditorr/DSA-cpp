#include <iostream>
using namespace std;

class Stack{
private:
    int top;
    int size;
    int* values;
public:
    Stack(int s){
        top=-1;
        size=0;
        values = new int[s];
    }
    void push(int val){
        if (top==size-1)
        {
            cout << "Stack OverFlow" << endl;
        }
        else{
            top++;
            values[top]=val;
        }
    }
    void pop(){
        
    }
};