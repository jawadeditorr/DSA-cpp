#include <iostream>
using namespace std;

bool binarySearch(int key,int arr[],int size){
    int start = 0,end = size-1;
    int mid = (start+end)/2;
    while (start<=end)
    {
        if (key==arr[mid])
        {
            return true;
        }
        else if(key>arr[mid]){
            start = mid + 1;
        }
        else if (key<arr[mid])
        {
            end = mid - 1;
        }
    }
    return false;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    if(binarySearch(40,arr,7)) cout << "true";
}