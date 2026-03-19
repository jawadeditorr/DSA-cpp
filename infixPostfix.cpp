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
    
    bool isBalanced(string s){
        for(int i = 0; i < s.length(); i++){

            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){

                if(top == -1)
                    return false;

                char ch = pop();

                if(s[i] == ')' && ch != '(')
                    return false;

                if(s[i] == ']' && ch != '[')
                    return false;

                if(s[i] == '}' && ch != '{')
                    return false;
            }
        }
        return (top == -1);
    }

    int prec(char c){
        if(c=='^'){
            return 3;
        }
        else if (c=='*'||c=='/')
        {
            return 2;
        }
        else if (c=='+'||c=='-')
        {
            return 1;
        }
        else{
            return -1;
        }
    }

    string infixToPostfix(string s){
        string result="";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
            {
                result+=s[i];
            }
            else if (s[i]=='(')
            {
                push(s[i]);
            }
            else if (s[i]==')')
            {
                while (top!=-1 && values[top]!='(')
                {
                    result+=pop();
                }
                if (top!=-1)
                {
                    pop();
                }
            }
            else{
                while (top!=-1 && prec(values[top])>=prec(s[i]))
                {
                    result+=pop();
                }
                push(s[i]);
            }
        }
        while (top!=-1)
        {
            result+=pop();
        }
        
        return result;
    }

    int evaluatePostfix(string exp){
        Stack st(exp.length());

        for(int i = 0; i < exp.length(); i++){
            if(isdigit(exp[i])){
                st.push(exp[i]);
            }
            else {
                int val2 = st.pop() - '0';
                int val1 = st.pop() - '0';
                int res;
                switch(exp[i]){
                    case '+': res = val1 + val2; break;
                    case '-': res = val1 - val2; break;
                    case '*': res = val1 * val2; break;
                    case '/': res = val1 / val2; break;
                }
                st.push(res + '0');
            }
        }

        return st.pop() - '0';
    }
};

int main(){
    string str1 = "A+B*C";
    int k = str1.length();
    Stack s1(k);
    cout << s1.infixToPostfix(str1);
}