#include <iostream>
using namespace std;

void addByValue(int n){
    n = n+10;
    cout << "in function"<<n<<endl;
}
void addByRef(int &n){
    n = n+10;
}

int main(){
    int x = 10;
    addByValue(x);
    cout<<x<<endl;

    

    










    //Pointerrr
    // int a = 5;
    // cout << "Value before : " << a << endl;
    // int* b = &a;
    // *b = 20;
    // cout << "Value after : " << a << endl;
    // cout << b << endl;

    //Dynamic arrays 
    // int n = 5;
    // int *array = new int[n];
}