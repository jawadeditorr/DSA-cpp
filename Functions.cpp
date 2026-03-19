#include <iostream>
using namespace std;

// Sum Of Digits
int sumOfDigits(int n){
    int num = n;
    int sum = 0;
    while (num!=0)
    {
        sum += num%10;
        num = num/10;
    }
    return sum;
}
// Factorial
int Factorial(int num){
    int i = num-1;
    int fact = num;
    if (num==0 || num==1)
    {
        return 1;
    }
    while (i>0)
    {
        fact *= i;
        i--;
    }
    return fact;
}

// nCr calculation
int combination(int n,int r){
    int nCr = Factorial(n)/(Factorial(r)*Factorial(n-r));
    return nCr;
}
int main(){
    int num = 832235;
    cout << "Sum of Digits for " << num << " is : " << sumOfDigits(num) << endl;
    cout << Factorial(7) << endl;
    cout << combination(6,3) << endl;
    return 0;
}