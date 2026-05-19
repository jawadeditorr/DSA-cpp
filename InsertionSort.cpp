#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int n, int arr[]){
    for (int i = 1; i < n; i++)
    {
        int prev = i-1;
        int curr = arr[i];
        while (prev>=0 && arr[prev]>curr)
        {
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
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
    insertionSort(size,arr);
}