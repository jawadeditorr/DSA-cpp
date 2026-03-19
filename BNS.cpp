#include <iostream>
using namespace std;

// Decimal To Binary Conversion
int DecimalToBinary(int num){
    int ans =0;
    int power = 1;
    while (num>0)
    {
        int reminder = num%2;
        num = num/2;
        ans += (reminder*power);
        power *= 10;
    }
    return ans;
}

// Decimal To Binary Conversion
int BinaryToDecimal(int num){
    int ans =0;
    int power = 1;
    while (num>0)
    {
        int reminder = num%10;
        num = num/10;
        ans += (reminder*power);
        power *= 2;
    }
    return ans;
}
//17*6
//12*5
//7*3
//4x1
int main(){
    cout << DecimalToBinary(67) << endl;
    cout << sizeof(int) << endl;
    cout << BinaryToDecimal(1000011) << endl;
}