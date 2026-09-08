#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int n, int arr[]){
    for (int i = 0; i < n-1; i++)
    {
        int smallest=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[smallest])
            {
                smallest = j;
            }
        }
        swap(arr[i],arr[smallest]);
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
    int arr[size] = {4,1,2,5,3};
    selectionSort(size,arr);
}