#include <iostream>
using namespace std;

class Stack{
public:
    int top;
    int size;
    char* values;

    Stack(int s){
        top = -1;
        size = s;
        values = new char[size];
    }

    void push(char val){
        if(top == size-1){
            cout << "Stack Overflow" << endl;
        }
        else{
            top++;
            values[top] = val;
        }
    }

    char pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return ' ';
        }
        else{
            char temp = values[top];
            top--;
            return temp;
        }
    }
};

int main(){

    Stack st(10);
    
    string str = "dawaJ mA I";
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }
    for(int i=0;i<str.length();i++){
        cout << st.pop();
    }
}

/*
st.push('D');
    st.push('A');
    st.push('W');
    st.push('A');
    st.push('J');
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
*/