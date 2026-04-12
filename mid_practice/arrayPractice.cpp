#include <iostream>
using namespace std;

void secondHighest(int arr[],int size){
    int max=arr[0];
    int secMax=arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>max)
        {
            int temp = arr[i];
            secMax = max;
            max = temp;
        }       
        else if (arr[i]<=max && arr[i]>secMax)
        {
            secMax = arr[i];
        }
    }
    
    cout << "Highest : " << max << endl;
    cout << "Second Highest : " << secMax << endl;   
}
int main(){
    int size = 5;
    int arr[size] = {5,20,6,4,8};
    secondHighest(arr,size);
}