#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int n, int arr[]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1];
    cout << "\n";
}

int main(){
    int size = 5;
    int arr[size] = {4,2,2,5,8};
    bubbleSort(size,arr);
}